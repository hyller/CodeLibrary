/**************************************************************************************************
  Filename:       cGP_stub.c
  Revised:        $Date: 2016-02-25 11:51:49 -0700 (Thu, 25 Feb 2016) $
  Revision:       $Revision: - $

  Description:    This file contains the implementation of the cGP stub.


  Copyright 2006-2015 Texas Instruments Incorporated. All rights reserved.

  IMPORTANT: Your use of this Software is limited to those specific rights
  granted under the terms of a software license agreement between the user
  who downloaded the software, his/her employer (which must be your employer)
  and Texas Instruments Incorporated (the "License").  You may not use this
  Software unless you agree to abide by the terms of the License. The License
  limits your use, and you acknowledge, that the Software may not be modified,
  copied or distributed unless embedded on a Texas Instruments microcontroller
  or used solely and exclusively in conjunction with a Texas Instruments radio
  frequency transceiver, which is integrated into your product.  Other than for
  the foregoing purpose, you may not use, reproduce, copy, prepare derivative
  works of, modify, distribute, perform, display or sell this Software and/or
  its documentation for any purpose.

  YOU FURTHER ACKNOWLEDGE AND AGREE THAT THE SOFTWARE AND DOCUMENTATION ARE
  PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER EXPRESS OR IMPLIED,
  INCLUDING WITHOUT LIMITATION, ANY WARRANTY OF MERCHANTABILITY, TITLE,
  NON-INFRINGEMENT AND FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT SHALL
  TEXAS INSTRUMENTS OR ITS LICENSORS BE LIABLE OR OBLIGATED UNDER CONTRACT,
  NEGLIGENCE, STRICT LIABILITY, CONTRIBUTION, BREACH OF WARRANTY, OR OTHER
  LEGAL EQUITABLE THEORY ANY DIRECT OR INDIRECT DAMAGES OR EXPENSES
  INCLUDING BUT NOT LIMITED TO ANY INCIDENTAL, SPECIAL, INDIRECT, PUNITIVE
  OR CONSEQUENTIAL DAMAGES, LOST PROFITS OR LOST DATA, COST OF PROCUREMENT
  OF SUBSTITUTE GOODS, TECHNOLOGY, SERVICES, OR ANY CLAIMS BY THIRD PARTIES
  (INCLUDING BUT NOT LIMITED TO ANY DEFENSE THEREOF), OR OTHER SIMILAR COSTS.

  Should you have any questions regarding your right to use this Software,
  contact Texas Instruments Incorporated at www.TI.com.
**************************************************************************************************/



/*********************************************************************
 * INCLUDES
 */

#include "ZGlobals.h"
#include "ZDProfile.h"
//GP_UPDATE
#include "ZComDef.h"
#include "cGP_stub.h"
#include "gp_interface.h"
#include "gp_common.h"
#include "dGP_stub.h"
#include "hal_aes.h"
#include "hal_ccm.h"
#include "hal_mcu.h"

#ifdef MT_GP_CB_FUNC
#include "MT_GP.h"
#endif

 /*********************************************************************
 * MACROS
 */
 
 
 /*********************************************************************
 * CONSTANTS
 */

/*********************************************************************
 * TYPEDEFS
 */

typedef uint8* (*getHandleFunction_t) (uint8 handle);

 /*********************************************************************
 * GLOBAL VARIABLES
 */
//List of dataInd waiting for SecRsp
gp_DataInd_t        *dgp_DataIndList;
uint8  dGP_StubHandle = 0;
uint8  GPEP_Handle = 0;
uint8* GPEP_findHandle(uint8 handle);

byte gp_TaskID;


const uint8 gGP_TX_QUEUE_MAX_ENTRY = GP_TX_QUEUE_MAX_ENTRY;
gp_DataReqPending_t gpTxQueueList[GP_TX_QUEUE_MAX_ENTRY];


/* Callbacks for GP endpoint */
GP_DataCnfGCB_t                   GP_DataCnfGCB = NULL;
GP_endpointInitGCB_t              GP_endpointInitGCB = NULL;  
GP_expireDuplicateFilteringGCB_t  GP_expireDuplicateFilteringGCB = NULL;
GP_stopCommissioningModeGCB_t     GP_stopCommissioningModeGCB = NULL;
GP_returnOperationalChannelGCB_t  GP_returnOperationalChannelGCB = NULL;
GP_DataIndGCB_t                   GP_DataIndGCB = NULL;
GP_SecReqGCB_t                    GP_SecReqGCB = NULL;
GP_CheckAnnouncedDevice_t         GP_CheckAnnouncedDeviceGCB = NULL;
ZDO_DeviceAnnce_t                 *GP_aliasConflictAnnce = NULL;

 /*********************************************************************
 * EXTERNAL VARIABLES
 */


extern uint32 gpTimeTempBackoff;
extern uint16 gpTimeTempTimer;
extern bool   gpLockTimestamp;



/*********************************************************************
 * EXTERNAL FUNCTIONS
 */

/*********************************************************************
 * LOCAL VARIABLES
 */
 
 /*********************************************************************
 * LOCAL FUNCTIONS
 */
 
 static uint8* gp_GenerateGPDF(uint8* msduLen, uint8 nwkFrameControl,uint8 ExtNwkFrameControl,gpd_ID_t *gpd_ID,uint8 EndPoint, uint32 SecFrameCounter, uint32 MIC, uint8 gp_payloadLen, uint8* gp_payload, uint8 gp_cmdID);
//void gp_sendMaintenanceFrameRsp(void);

uint8 gp_buildNwkFrameCtrl(uint8* pExtNwkFrameControl, uint8 FrameType, uint8 AutoCommissioning, uint8 AppId, uint8 securityLvl, uint8 SecKey, bool RxAfterTx, bool Direction);

bool gp_processMaintenanceFrame(void);
 
static ZStatus_t gp_SecBuildNonce(bool isOutgoingMsg,gpd_ID_t *gpd_ID, uint32 FrameCounter,uint8 *gp_AESNonce);
 
void gp_DataIndAppendToList(gp_DataInd_t *gp_DataInd, gp_DataInd_t **DataIndList);



static ZStatus_t gp_SecBuildHeader(gp_DataInd_t *gp_DataInd, uint8 **header, uint8 *headerLen);
static uint8 gp_ccmStar(gp_DataInd_t *gp_DataInd, uint8* key);
static void gp_sys_event_processing(void);

 /*********************************************************************
 * PUBLIC FUNCTIONS
 *********************************************************************/

#ifdef TESTING_DECRYPT
void TestingDecrypt(void);
#endif

//Common settings:
uint8 GP_SecurityKey[SEC_KEY_LEN] = {0xC0,0xC1,0xC2,0xC3,0xC4,0xC5,0xC6,0xC7,0xC8,0xC9,0xCa,0xCb,0xCc,0xCd,0xCe,0xCf};

uint8 nwkFrameCtrl = 0x8c;

#ifdef TESTING_DECRYPT
void TestingDecrypt(void)
{
  //FROM ACTUAL FUNCTION
  gp_DataInd_t  gp_DataInd;
  
  
  //Decrypt Auth shared key
  gp_DataInd.appID = 0;
  gp_DataInd.SrcId = 0x87654321;
  gp_DataInd.AutoCommissioning = 0;
  //gp_DataInd.GPDCmmdID = 0x83;   //this payload should not be used, until the process is done and it gets assigned form the ASDU buffer
  gp_DataInd.GPDasdu[0] = 0x83;
  gp_DataInd.GPDasduLength = 1;
  gp_DataInd.RxAfterTx = 0;
  gp_DataInd.GPDFSecLvl = GP_SECURITY_LVL_4FC_4MIC_ENCRYPT;
  gp_DataInd.GPDFKeyType = 0; 
  gp_DataInd.GPDSecFrameCounter = 0x00000002;
  gp_DataInd.MIC = 0xDD2443CA;
  
  gp_ccmStar(&gp_DataInd, GP_SecurityKey);
  
  //Auth shared key
  gp_DataInd.appID = 0;
  gp_DataInd.SrcId = 0x87654321;
  gp_DataInd.AutoCommissioning = 0;
  //gp_DataInd.GPDCmmdID = 0x83;   //this payload should not be used, until the process is done and it gets assigned form the ASDU buffer
  gp_DataInd.GPDasdu[0] = 0x20;
  gp_DataInd.GPDasduLength = 1;
  gp_DataInd.RxAfterTx = 0;
  gp_DataInd.GPDFSecLvl = GP_SECURITY_LVL_4FC_4MIC;
  gp_DataInd.GPDFKeyType = 0; 
  gp_DataInd.GPDSecFrameCounter = 0x00000002;
  gp_DataInd.MIC = 0x727E78CF;
  
  gp_ccmStar(&gp_DataInd, GP_SecurityKey);
   
}
#endif



uint8 gp_ccmStar(gp_DataInd_t *gp_DataInd, uint8* key)
{
  gpd_ID_t  gpd_ID;
  uint8     *pBuf = NULL;
  uint8     *temp;
  uint8     *tempKey;
  uint8 *header = NULL;
  uint8 headerLen = 0;  
  uint8 nonce[GP_NONCE_LENGTH] = {0};
  uint8 cstate[16];
  uint8 status = ZFailure;
  
  //Encryption requires to include the payload
  if(gp_DataInd->GPDFSecLvl == GP_SECURITY_LVL_4FC_4MIC_ENCRYPT)
  {
    //Mic size + message length
    pBuf = osal_mem_alloc(sizeof(uint32) + gp_DataInd->GPDasduLength);
    
    if(pBuf == NULL)
    {
      return ZFailure;
    }
    temp = pBuf;
    osal_memcpy(temp, gp_DataInd->GPDasdu,gp_DataInd->GPDasduLength);
    temp += gp_DataInd->GPDasduLength;
    osal_buffer_uint32(temp,gp_DataInd->MIC);
  }


  gpd_ID.AppID = gp_DataInd->appID;
  gpd_ID.GPDId.SrcID = gp_DataInd->SrcId;
  //Build nonce and header
  gp_SecBuildNonce(FALSE,&gpd_ID,gp_DataInd->GPDSecFrameCounter,nonce);
  
  gp_SecBuildHeader(gp_DataInd,&header,&headerLen);
  
  //From ccmStar
  HAL_AES_ENTER_WORKAROUND();
  tempKey = key;
  ssp_HW_KeyInit(tempKey);
  pSspAesEncrypt = sspAesEncryptHW;
 
  //Decrypt and authenticate
  if(gp_DataInd->GPDFSecLvl == GP_SECURITY_LVL_4FC_4MIC_ENCRYPT)
  {
    status = SSP_CCM_InvAuth_Decrypt (TRUE, sizeof(uint32), nonce, pBuf, sizeof(uint32) + gp_DataInd->GPDasduLength, header,
                                     headerLen, tempKey, cstate, 2);
    
    if(status == 0)
    {
      temp = pBuf;
      //Copy back the payload
      osal_memcpy(gp_DataInd->GPDasdu,pBuf,gp_DataInd->GPDasduLength);
      temp += gp_DataInd->GPDasduLength;
      osal_memcpy((uint8*)&gp_DataInd->MIC,temp,sizeof(uint32));
    }
    osal_mem_free(pBuf);
  }
  
  //Authenticate only
  if(gp_DataInd->GPDFSecLvl == GP_SECURITY_LVL_4FC_4MIC)
  {
    uint8 micBuff[4];

    osal_buffer_uint32(micBuff,gp_DataInd->MIC);

    status = SSP_CCM_InvAuth_Decrypt (TRUE, sizeof(uint32), nonce, micBuff, sizeof(uint32), header,
                                     headerLen, tempKey, cstate, 2);
  
  }
  HAL_AES_EXIT_WORKAROUND();
  
  osal_mem_free(header);
  
  return status;
}






/*********************************************************************
 * @fn          dGP_DataInd
 *
 * @brief       cGP stub primitive to pass to dGP stub a GPDF send from a GPD
 *
 * @param       dgp_DataInd
 *
 * @return      none
 */
void dGP_DataInd(dgp_DataInd_t *dgp_DataInd)
{
  gpd_ID_t     gpd_ID;   //Application ID inside
  uint8        *pMsdu;
  uint8        nwkFrameCtrl, FrameType, SecurityLvl, RxAfterTx;
  uint8        EndPoint = 0;   //if does not exist then it is ignored
  uint8        SecurityKey = 0;
  uint8        SecurityKeyType = 0; 
  uint8        *ExtNwkFrameCtrl = NULL;
  uint32       MIC32 = 0;
  uint32       SecurityFrameCounter32 = 0;
  uint8        *pGPPayload = NULL;
  uint8        GPPayloadLen = 0;
  uint8        GPnonPayloadLen = 0;
  uint8        AutoCommissioning;
  
  RxAfterTx = 0;
  //Initialize
  osal_memset(&gpd_ID,0,sizeof(gpd_ID_t));
  
  //Keep track of the pointer
  pMsdu = dgp_DataInd->mpdu;
  
  //First byte is nwk Frame Control
  nwkFrameCtrl = *pMsdu;
  pMsdu++;
  GPnonPayloadLen++;
  
  //FrameType
  FrameType = (nwkFrameCtrl & GP_NWK_FRAME_TYPE_MASK) >> GP_NWK_FRAME_TYPE_POS;
  
  //Autocomissioning
  AutoCommissioning = (nwkFrameCtrl & GP_AUTO_COMM_MASK) >> GP_AUTO_COMM_POS;
  
  //Application ID is 0 unless it is stated in ext nwk frame ctrl field
  gpd_ID.AppID = 0;
  
  //Assume security lvl 0
  SecurityLvl = 0;
  
  //does the frame has nwk extension
  if((nwkFrameCtrl & GP_NWK_FRAME_CTRL_EXT_MASK) >> GP_NWK_FRAME_CTRL_EXT_POS)
  {
    ExtNwkFrameCtrl = pMsdu;
    pMsdu++;
    GPnonPayloadLen++;
    
    RxAfterTx = ((*ExtNwkFrameCtrl & GP_EXT_NWK_APP_RX_AFTER_TX_MASK) >> GP_EXT_NWK_APP_RX_AFTER_TX_POS);
    
    if(RxAfterTx && AutoCommissioning)
    {
      return; //drop the packet
    }
    
    //Update the Application ID
    gpd_ID.AppID = ((*ExtNwkFrameCtrl & GP_EXT_NWK_APP_ID_MASK) >> GP_EXT_NWK_APP_ID_POS);
    SecurityLvl = ((*ExtNwkFrameCtrl & GP_EXT_NWK_APP_SEC_LVL_MASK) >> GP_EXT_NWK_APP_SEC_LVL_POS);
    SecurityKey = ((*ExtNwkFrameCtrl & GP_EXT_NWK_APP_SEC_KEY_MASK) >> GP_EXT_NWK_APP_SEC_KEY_POS);
  }
  if(FrameType != GP_NWK_FRAME_TYPE_MAINTENANCE)
  {
    //Check if the source ID is present
    if((gpd_ID.AppID == GP_APP_ID_DEFAULT))
    {
      osal_memcpy(&gpd_ID.GPDId.SrcID,pMsdu,sizeof(uint32));
      pMsdu += sizeof(uint32);
      GPnonPayloadLen += sizeof(uint32);
    }
    else if(gpd_ID.AppID == GP_APP_ID_GP)
    {
      EndPoint = *pMsdu;
      pMsdu++;
      GPnonPayloadLen++;
      
      if(dgp_DataInd->srcAddr.addrMode == SADDR_MODE_EXT)
      {
        osal_memcpy(gpd_ID.GPDId.GPDExtAddr, dgp_DataInd->srcAddr.addr.extAddr,Z_EXTADDR_LEN);
      }
    }
  }
  
  //Get the security parameters
  if(SecurityLvl >= GP_SECURITY_LVL_4FC_4MIC)
  {
    //Save pointer to security frame counter
    osal_memcpy(&SecurityFrameCounter32,pMsdu,sizeof(uint32));
    
    pMsdu += sizeof(uint32);
    GPnonPayloadLen += sizeof(uint32);
    
    //Point to GP payload  (encrypted)
    pGPPayload = pMsdu;
    //Calculate GP payload length, whole frame but bytes found until now, minus the bytes to come in the frame
    GPPayloadLen = dgp_DataInd->mpduLen - GPnonPayloadLen - sizeof(uint32); //takeout MIC
    pMsdu += GPPayloadLen;
    
    //Point to MIC
    osal_memcpy(&MIC32,pMsdu,sizeof(uint32));
  }
  else
  {
    //Point to GP payload
    pGPPayload = pMsdu;

    //Calculate GP payload length, whole frame but bytes found until now, minus the bytes to come in the frame
    GPPayloadLen = dgp_DataInd->mpduLen - GPnonPayloadLen;
  }
  
    //Frame type maintenance
  if(FrameType == GP_NWK_FRAME_TYPE_MAINTENANCE)
  {
    uint8 gpCmd = *pGPPayload;
    
    if(SecurityLvl)
    {
      //Maintenance packets should not be encrypted. Drop the packet
      return;
    }
    
    //Schedule transmission of GPDF app ID 000
    if(gpCmd < GP_CMD_ID_F0)
    {
      //A.1.7.4
      if(!AutoCommissioning)
      {
        gpd_ID_t gpd_ID;
        gpd_ID.AppID = 0;
        gpd_ID.GPDId.SrcID = 0;
        
#ifdef GP_FIXED_TIME
        gp_scheduleGPDFTransmission(&gpd_ID,0,0,FrameType);
#else
        gp_scheduleGPDFTransmission(&gpd_ID,0,gpTimeTempBackoff,FrameType);
#endif
      }
    }
    else
    {
      //Should not receive any command out of that range drop the packet
      return;
    }
  }

  gp_DataInd_t *gp_DataInd = NULL;
  
  //Validate the security level
  if(SecurityLvl == GP_SECURITY_LVL_RESERVED)
  {
    //Drop the packet
    return;
  }
  
  gp_DataInd = (gp_DataInd_t*)osal_msg_allocate(sizeof(gp_DataInd_t) + GPPayloadLen);
  
  if(gp_DataInd == NULL)
  {
    //no mem
    return;
  }
  
  gp_DataInd->hdr.event = GP_DATA_IND;
  gp_DataInd->hdr.status = ZSUCCESS;
  gp_DataInd->status = GP_DATA_IND_STATUS_NO_SECURITY;
  gp_DataInd->Rssi = dgp_DataInd->Rssi;
  gp_DataInd->LinkQuality = dgp_DataInd->LinkQuality;
  gp_DataInd->SeqNumber = dgp_DataInd->SeqNumber;
  osal_memcpy(&gp_DataInd->srcAddr,&dgp_DataInd->srcAddr, sizeof(sAddr_t));
  gp_DataInd->srcPanID = dgp_DataInd->srcPanID;
  gp_DataInd->appID = gpd_ID.AppID;
  gp_DataInd->GPDFSecLvl = SecurityLvl;
  gp_DataInd->GPDFKeyType = SecurityKeyType;
  gp_DataInd->AutoCommissioning = AutoCommissioning;
  gp_DataInd->RxAfterTx = RxAfterTx;
  gp_DataInd->SrcId = gpd_ID.GPDId.SrcID;
  gp_DataInd->EndPoint = EndPoint;
  gp_DataInd->GPDSecFrameCounter = SecurityFrameCounter32;
  gp_DataInd->MIC = MIC32;
  gp_DataInd->GPDCmmdID = 0;
  gp_DataInd->SecReqHandling.dGPStubHandle = gp_GetHandle(DGP_HANDLE_TYPE);
  gp_DataInd->SecReqHandling.next = NULL;
  gp_DataInd->SecReqHandling.timeout = 0xFF;
//#ifndef GP_FIXED_TIME
  gp_DataInd->timestamp = gpTimeTempBackoff;
//#endif

  //GP_SecReq
  gp_SecReq_t *gp_SecReq = NULL;
  gp_SecReq = (gp_SecReq_t*)osal_msg_allocate(sizeof(gp_SecReq_t));
  
  if(gp_SecReq == NULL)
  {
    //drop the packet, since there is no memory to send de sec request
    osal_msg_deallocate((uint8*)gp_DataInd);
    return;
  }
  
  gp_DataIndAppendToList(gp_DataInd,&dgp_DataIndList);
  
  gp_SecReq->hdr.event  = GP_SEC_REQ;
  gp_SecReq->hdr.status = ZSuccess;
  
  gp_SecReq->dGPStubHandle = gp_DataInd->SecReqHandling.dGPStubHandle;
    
  //Save the whole payload since it might be encrypted
  osal_memcpy(&gp_DataInd->GPDasdu,pGPPayload,GPPayloadLen);
  gp_DataInd->GPDasduLength = GPPayloadLen;

  gp_SecReq->EndPoint = EndPoint;
  gp_SecReq->gp_SecData.GPDFKeyType = SecurityKey;
  gp_SecReq->gp_SecData.GPDFSecLvl = SecurityLvl;
  gp_SecReq->gp_SecData.GPDSecFrameCounter = SecurityFrameCounter32;
  osal_memcpy(&gp_SecReq->gpd_ID.AppID,&gpd_ID,sizeof(gpd_ID_t));
  
  osal_msg_send(gp_TaskID,(uint8 *)gp_SecReq);

}
   







   
void dGP_DataCnf(uint8 Status, uint8 GPmpduHandle)
{
  uint8 i;
  gp_DataCnf_t gp_DataCnf;
  
  if(Status == GP_DATA_CNF_GPDF_SENDING_FINALIZED)
  {
    for (i = 0; i < gGP_TX_QUEUE_MAX_ENTRY; i++)
    {
      if(gpTxQueueList[i].gp_DataReq->GPEPhandle == GPmpduHandle)
      {
         //No need to pass message, since we are comming from one
        gp_DataCnf.GPEPhandle = GPmpduHandle;
        gp_DataCnf.status = GP_DATA_CNF_GPDF_SENDING_FINALIZED;

        if(GP_DataCnfGCB)
        {
          GP_DataCnfGCB(&gp_DataCnf);
        }

#if MT_GP_CB_FUNC
        MT_GPDataCnf(&gp_DataCnf);
#endif        
        
        osal_msg_deallocate((uint8*)gpTxQueueList[i].gp_DataReq);
        gpTxQueueList[i].gp_DataReq = NULL;
      }
    }
  }
}
   
 

/*********************************************************************
 * @fn          GP_DataReq
 *
 * @brief       Primitive by GP EndPoint to pass to dGP stub a request to send GPDF to a GPD
 *
 * @param       gp_DataReq
 *
 * @return      freeMsg - TRUE if the message will be free on return, FALSE if 
 *                        this msg will be free later
 */
bool GP_DataReq(gp_DataReq_t *gp_DataReq)
{
  uint8  i;
  uint8  addrIdLength = 0;
  uint8  freeEntry = gGP_TX_QUEUE_MAX_ENTRY;
  bool   replace = 0;
  bool   breakSearch = 0;
  bool   remove = 0;
  bool   freeMsg = TRUE;

  if(!(gp_DataReq->TxOptions & GP_OPT_USE_TX_QUEUE_MASK))
  {
    //TODO: what if this data request has other flags?
    return TRUE;
  }

  //NOTE: Basic proxy cannot expire packets, so the entry is cleared upon sending the GPDF or upon reception of a request to clear it
  osal_memset(gp_DataReq->gpTxQueueEntryLifeTime,0xFF,sizeof(gp_DataReq->gpTxQueueEntryLifeTime));

  //Check the application ID
  if(gp_DataReq->gpd_ID.AppID == GP_APP_ID_DEFAULT)
  {
    //look for source id
    addrIdLength = sizeof(uint32);
    //Make sure to ignore this field for APP ID Default
    gp_DataReq->TxOptions &= ~GP_OPT_TX_ON_MATCHING_ENDPOINT_MASK;
    
  }
  else if (gp_DataReq->gpd_ID.AppID == GP_APP_ID_GP)
  {
    //look for IEEE address
    addrIdLength = Z_EXTADDR_LEN;
  }
  else
  {
    freeMsg = TRUE;
    //App id not supported
    return freeMsg;
  }
  

  //Search in entries as per GP spec 14-0563-16 section A.1.5.2.1 
  //Check for gpTxQueueList
  for(i = 0; i < gGP_TX_QUEUE_MAX_ENTRY; i++)
  {
    remove = 0;

    if(gpTxQueueList[i].gp_DataReq != NULL)
    {
      //look only for entries with the same application ID
      if(gpTxQueueList[i].gp_DataReq->gpd_ID.AppID == gp_DataReq->gpd_ID.AppID)
      {
        //Compare the address based on the application ID
        if(osal_memcmp(&gpTxQueueList[i].gp_DataReq->gpd_ID.GPDId,&gp_DataReq->gpd_ID.GPDId,addrIdLength))
        {
          //Remove the first entry found
          if(gp_DataReq->Action == 0)
          {
            //Check if need to validate endpoints
            if(gp_DataReq->gpd_ID.AppID == GP_APP_ID_GP)
            {
              if(gp_DataReq->TxOptions & GP_OPT_TX_ON_MATCHING_ENDPOINT_MASK)
              {
                if(gp_DataReq->EndPoint != gpTxQueueList[i].gp_DataReq->EndPoint)
                {
                  continue;
                }
              }
            }
            //Mark to be removed later
            remove = TRUE;
            breakSearch = TRUE;
          }
          //Replace the first and erase the rest
          else
          {
            //Default application can only have a single entry
            if(gpTxQueueList[i].gp_DataReq->gpd_ID.AppID == GP_APP_ID_DEFAULT)
            {
              replace = TRUE;
              breakSearch = TRUE;
            }
            else
            {
              if(gp_DataReq->TxOptions & GP_OPT_TX_ON_MATCHING_ENDPOINT_MASK)
              {
                if(gp_DataReq->EndPoint != gpTxQueueList[i].gp_DataReq->EndPoint)
                {
                  continue;
                }
              }
              if(replace)
              {
                remove = TRUE;
              }
              else
              {
                replace = TRUE;
              }
            }
          }
          //Process the entry
          if(remove || replace)
          {
            gp_DataCnf_t *gp_DataCnf = NULL;
            gp_DataCnf = (gp_DataCnf_t*)osal_msg_allocate(sizeof(gp_DataCnf_t));
            
            //Notify about the entry removed or replaced
            if(gp_DataCnf != NULL)
            {
              gp_DataCnf->hdr.status = 0;
              gp_DataCnf->hdr.event = GP_DATA_CNF;
              
              gp_DataCnf->GPEPhandle = gpTxQueueList[i].gp_DataReq->GPEPhandle;
              //release the entry
              osal_msg_deallocate( (uint8 *)gpTxQueueList[i].gp_DataReq );
              gpTxQueueList[i].gp_DataReq = NULL;
                
              if(replace)
              {
                gp_DataCnf->status = GP_DATA_CNF_ENTRY_REPLACED;
                freeMsg = FALSE;
                gpTxQueueList[i].gp_DataReq = gp_DataReq;
              }
              else
              {
                gp_DataCnf->status = GP_DATA_CNF_ENTRY_REMOVED;
              }
              osal_msg_send(gp_TaskID,(uint8*)gp_DataCnf);
            }
          }
          if(breakSearch)
          {
            //Message already send
            break;
          }
        }
      }
    }
    else
    {
      //Save the free entry found
      freeEntry = i;
    }
  }
  
  //Did found an entry
  if((i < gGP_TX_QUEUE_MAX_ENTRY) || replace || breakSearch)
  {
    return freeMsg;
  }
  
  gp_DataCnf_t *gp_DataCnf = NULL;
  gp_DataCnf = (gp_DataCnf_t*)osal_msg_allocate(sizeof(gp_DataCnf_t));
  
  //Notify about the entry added or attempt to remove
  if(gp_DataCnf != NULL)
  {
    gp_DataCnf->hdr.status = 0;
    gp_DataCnf->hdr.event = GP_DATA_CNF;
    gp_DataCnf->GPEPhandle = gp_DataReq->GPEPhandle;
    
    //Did not found the entry, do we have free space to store?
    if(freeEntry < gGP_TX_QUEUE_MAX_ENTRY)
    {
      if(gp_DataReq->Action)
      {
        //add the entry and do not relase the message
        gpTxQueueList[freeEntry].gp_DataReq = gp_DataReq;
        freeMsg = FALSE;

        gp_DataCnf->status = GP_DATA_CNF_ENTRY_ADDED;
      }
      else
      {
        gp_DataCnf->status = GP_DATA_CNF_ENTRY_REMOVED;
      }
    }
    //Not found, no free entry, then table full
    else
    {
      gp_DataCnf->status = GP_DATA_CNF_TX_QUEUE_FULL;
    }
    osal_msg_send(gp_TaskID,(uint8*)gp_DataCnf);
  }
  return freeMsg;
}

 




/*********************************************************************
 * @fn          GP_SecRsp
 *
 * @brief       Response to dGP stub from GP endpoint on how to process the GPDF
 *
 * @param       gp_SecRsp 
 *
 * @return      none
 */
void GP_SecRsp(gp_SecRsp_t *gp_SecRsp)
{
  gp_DataInd_t* gp_DataInd;

  
  gp_DataInd = (gp_DataInd_t*)dGP_findHandle(gp_SecRsp->dGPStubHandle);
  
  if(gp_DataInd == NULL)
  {
    //Not found
    return;
  }

  switch(gp_SecRsp->Status)
  {
    case GP_SEC_RSP_DROP_FRAME:
      //Duplicate, release from list and from memory
      gp_DataIndReleaseFromList(TRUE,gp_DataInd,&dgp_DataIndList);
      return;
    break;

    case GP_SEC_RSP_PASS_UNPROCESSED:
      gp_DataInd->status = GP_DATA_IND_STATUS_UNPROCESSED;
      //Copy the message
      gp_DataInd->GPDCmmdID = gp_DataInd->GPDasdu[0];
      gp_DataInd->GPDasduLength--;
      osal_memcpy(&gp_DataInd->GPDasdu[0],&gp_DataInd->GPDasdu[1],gp_DataInd->GPDasduLength);
      
      //Send the messgage to gp endpoint
      osal_msg_send(gp_TaskID,(uint8 *)gp_DataInd);
      //release it from the list, but not from memory
      gp_DataIndReleaseFromList(FALSE,gp_DataInd,&dgp_DataIndList);
    break;
    
    case GP_SEC_RSP_TX_THEN_DROP:
      if(gp_ccmStar(gp_DataInd,gp_SecRsp->GPDKey))
      {
        gp_DataInd->status = GP_DATA_IND_STATUS_AUTH_FAILURE;
        
        //pass the indication with the right status
        osal_msg_send(gp_TaskID,(uint8 *)gp_DataInd);
        //release it from the list, but not from memory
        gp_DataIndReleaseFromList(FALSE,gp_DataInd,&dgp_DataIndList);
      }
      //Command ID out of range
      if(gp_DataInd->GPDasdu[0] >= GP_CMD_ID_F0)
      {
        gp_DataIndReleaseFromList(TRUE,gp_DataInd,&dgp_DataIndList);
        return;
      }
      

      gp_DataIndReleaseFromList(TRUE,gp_DataInd,&dgp_DataIndList);
      return;
    break;

    case GP_SEC_RSP_MATCH:
      if(gp_ccmStar(gp_DataInd,gp_SecRsp->GPDKey))
      {
        gp_DataInd->status = GP_DATA_IND_STATUS_AUTH_FAILURE;
        
        //pass the indication with the right status
        osal_msg_send(gp_TaskID,(uint8 *)gp_DataInd);
        //release it from the list, but not from memory
        gp_DataIndReleaseFromList(FALSE,gp_DataInd,&dgp_DataIndList);
      }
      //Command ID out of range
      if(gp_DataInd->GPDasdu[0] >= GP_CMD_ID_F0)
      {
        gp_DataIndReleaseFromList(TRUE,gp_DataInd,&dgp_DataIndList);
        return;
      }
      
      if(gp_DataInd->GPDFSecLvl)
      {
        gp_DataInd->status = GP_DATA_IND_STATUS_SECURITY_SUCCESS;
      }
      else
      {
        gp_DataInd->status = GP_DATA_IND_STATUS_NO_SECURITY;
      }
      
      //Adjust the command ID and command payload according to indication
      gp_DataInd->GPDCmmdID = gp_DataInd->GPDasdu[0];
      gp_DataInd->GPDasduLength--;
      osal_memcpy(gp_DataInd->GPDasdu,&gp_DataInd->GPDasdu[1],gp_DataInd->GPDasduLength);
      
      osal_msg_send(gp_TaskID,(uint8 *)gp_DataInd);
      //release it from the list, but not from memory, it will be used by GP endpoint
      gp_DataIndReleaseFromList(FALSE,gp_DataInd,&dgp_DataIndList);
      
    break;
  }
  
  if(gp_DataInd->RxAfterTx)
  {
    gpd_ID_t gpd_ID;
    
    gpd_ID.AppID = gp_DataInd->appID;
    if(gp_DataInd->appID == GP_APP_ID_DEFAULT)
    {
       gpd_ID.GPDId.SrcID = gp_DataInd->SrcId;
    }
    else
    {
      osal_memcpy(gpd_ID.GPDId.GPDExtAddr, gp_DataInd->srcAddr.addr.extAddr,Z_EXTADDR_LEN);
    }
    
#ifdef GP_FIXED_TIME
    gp_scheduleGPDFTransmission(&gpd_ID,gp_DataInd->EndPoint,1,GP_NWK_FRAME_TYPE_DATA);
#else
    gp_scheduleGPDFTransmission(&gpd_ID,gp_DataInd->EndPoint,gpTimeTempBackoff,GP_NWK_FRAME_TYPE_DATA);                       
#endif
  }  
  
}
     


/*********************************************************************
 * @fn          gp_releaseDataInd
 *
 * @brief       Releases an element in the list, with the option to free memory 
 *              or not
 *
 * @param       freeMem TRUE to free the memory, FALSE do not free (will be used
 *                      by the other layer)
 * @param       dataInd Pointer to the element in the list to be released
 *
 * @param       DataIndList List from which the data ind will be released
 *
 * @return      none
 */
void gp_DataIndReleaseFromList(bool freeMem, gp_DataInd_t* dataInd, gp_DataInd_t **DataIndList)
{
  //Check the first entry
  if(*DataIndList != NULL)
  {
    if(*DataIndList == dataInd)
    {
      gp_DataInd_t  *next = (*DataIndList)->SecReqHandling.next;
      if(freeMem)
      {
        osal_msg_deallocate((uint8*)*DataIndList);
      }
      *DataIndList = next;
    }
    else
    {
      gp_DataInd_t  *previous = *DataIndList;
      gp_DataInd_t  *current  = (*DataIndList)->SecReqHandling.next;
      
      while((current != NULL) && (previous != NULL))
      {
        if(current == dataInd)
        {
          gp_DataInd_t  *temp = current;
          previous->SecReqHandling.next = current->SecReqHandling.next;
          if(freeMem)
          {
            osal_msg_deallocate((uint8*)temp);
          }
          return;
        }
        previous = current;
        current = current->SecReqHandling.next;
      }
    }
  }
}





 /*********************************************************************
 * PRIVATE FUNCTIONS
 *********************************************************************/
 
 
 
uint8* gp_GenerateGPDF(uint8* msduLen, uint8 nwkFrameControl,uint8 ExtNwkFrameControl,gpd_ID_t *gpd_ID,uint8 EndPoint, uint32 SecFrameCounter, uint32 MIC, uint8 gp_payloadLen, uint8* gp_payload, uint8 gp_cmdID)
{
  uint8 *msdu = NULL;
  *msduLen = 0;
  
  (*msduLen)++; //nwkframe control
  (*msduLen)++; //gp_commandID

  //check if extended nwk frame ctrl is present
  if((nwkFrameControl & GP_NWK_FRAME_CTRL_EXT_MASK) >> GP_NWK_FRAME_CTRL_EXT_POS)
  {
    (*msduLen)++;
    //Check if Security frame counter and MIC are present
    if( ((ExtNwkFrameControl & GP_EXT_NWK_APP_SEC_LVL_MASK) >> GP_EXT_NWK_APP_SEC_LVL_POS == GP_SECURITY_LVL_4FC_4MIC) ||
        ((ExtNwkFrameControl & GP_EXT_NWK_APP_SEC_LVL_MASK) >> GP_EXT_NWK_APP_SEC_LVL_POS == GP_SECURITY_LVL_4FC_4MIC_ENCRYPT) )
    {
      (*msduLen) += sizeof(uint32);
      (*msduLen) += sizeof(uint32);
    }
  }
  if((nwkFrameControl & GP_FRAME_TYPE_MASK) == GP_NWK_FRAME_TYPE_DATA)
  {
    //Is endpoint included
    if(gpd_ID->AppID == GP_APP_ID_GP)
    {
      (*msduLen)++;
    }
    //Include the GPDSrcID
    else
    {
      (*msduLen) += sizeof(uint32);
    }
  }
    
  *msduLen += gp_payloadLen;
  
  msdu = (uint8*)osal_mem_alloc(*msduLen);
  
  if(msdu != NULL)
  {
    uint8* tempmsu = msdu;
    //Add the protocol version
    *tempmsu = nwkFrameControl;
    tempmsu++;
    
    if((nwkFrameControl & GP_NWK_FRAME_CTRL_EXT_MASK) >> GP_NWK_FRAME_CTRL_EXT_POS)
    {
      *tempmsu = ExtNwkFrameControl;
      tempmsu++;
    }
    
    if((nwkFrameControl & GP_FRAME_TYPE_MASK) == GP_NWK_FRAME_TYPE_DATA)
    {
      if(gpd_ID->AppID == GP_APP_ID_GP)
      {
        *tempmsu = EndPoint;
        tempmsu++;
      }
      else
      {
        UINT32_TO_BUF_LITTLE_ENDIAN(tempmsu,gpd_ID->GPDId.SrcID);
      }
    }
    
    if((nwkFrameControl & GP_NWK_FRAME_CTRL_EXT_MASK) >> GP_NWK_FRAME_CTRL_EXT_POS)
    {
      if( ((ExtNwkFrameControl & GP_EXT_NWK_APP_SEC_LVL_MASK) >> GP_EXT_NWK_APP_SEC_LVL_POS == GP_SECURITY_LVL_4FC_4MIC) ||
          ((ExtNwkFrameControl & GP_EXT_NWK_APP_SEC_LVL_MASK) >> GP_EXT_NWK_APP_SEC_LVL_POS == GP_SECURITY_LVL_4FC_4MIC_ENCRYPT) )
      {
        UINT32_TO_BUF_LITTLE_ENDIAN(tempmsu,SecFrameCounter);
      }
    }
    
    *tempmsu = gp_cmdID;
    tempmsu++;
    
    osal_memcpy(tempmsu,gp_payload,gp_payloadLen);
    tempmsu += gp_payloadLen;
    
    if((nwkFrameControl & GP_NWK_FRAME_CTRL_EXT_MASK) >> GP_NWK_FRAME_CTRL_EXT_POS)
    {
      if( ((ExtNwkFrameControl & GP_EXT_NWK_APP_SEC_LVL_MASK) >> GP_EXT_NWK_APP_SEC_LVL_POS == GP_SECURITY_LVL_4FC_4MIC) ||
          ((ExtNwkFrameControl & GP_EXT_NWK_APP_SEC_LVL_MASK) >> GP_EXT_NWK_APP_SEC_LVL_POS == GP_SECURITY_LVL_4FC_4MIC_ENCRYPT) )
      {
        UINT32_TO_BUF_LITTLE_ENDIAN(tempmsu,MIC);
      }
    }
  }
  return msdu;
}
 


void gp_scheduleGPDFTransmission(gpd_ID_t *gpd_ID, uint8 endpoint, uint32 timestamp,uint8 FrameType)
{
  uint8         *mpdu;
  uint8         mpduLen = 0;
  uint8         nwkFrameControl = 0;
  uint8         extNwkFrameControl = 0;
  uint16        dstPanID = 0xFFFF;
  zAddrType_t   SrcAddr;
  zAddrType_t   DstAddr;
  uint8  addrIdLength,i;
  
  
  //Check the application ID
  if(gpd_ID->AppID == GP_APP_ID_DEFAULT)
  {
    //look for source id
    addrIdLength = sizeof(uint32);
    //Make sure to ignore this field for APP ID Default
  }
  else if (gpd_ID->AppID == GP_APP_ID_GP)
  {
    //look for IEEE address
    addrIdLength = Z_EXTADDR_LEN;
  }
  else
  {
    //Cannot schedule transmission for reserved app ID
    return;
  }

  //Check for gpTxQueueList
  for(i = 0; i < gGP_TX_QUEUE_MAX_ENTRY; i++)
  {
    if(gpTxQueueList[i].gp_DataReq != NULL)
    {
      //look only for entries with the same application ID
      if(gpTxQueueList[i].gp_DataReq->gpd_ID.AppID == gpd_ID->AppID)
      {
        //Compare the address based on the application ID
        if(osal_memcmp(&gpTxQueueList[i].gp_DataReq->gpd_ID.GPDId,&gpd_ID->GPDId,addrIdLength))
        {
          //Check if need to validate endpoints
          if(gpd_ID->AppID == GP_APP_ID_GP)
          {
            if(endpoint != 0xFF)
            {
              if(endpoint != gpTxQueueList[i].gp_DataReq->EndPoint)
              {
                continue;
              }
            }
            //Found!
            break;
          }
          else
          {
            //Found!
            break;
          }
        }
      }
    }
  }
  if(i == gGP_TX_QUEUE_MAX_ENTRY)
  {
    //Not found
    return;
  }

  SrcAddr.addrMode = 0;  //Not present
  DstAddr.addr.shortAddr = 0xFFFF;
  DstAddr.addrMode = Addr16Bit;

  //None of the frames uses ACK or CSMA
  gpTxQueueList[i].gp_DataReq->TxOptions = 0;
  
  if(FrameType == GP_NWK_FRAME_TYPE_MAINTENANCE)
  {
    nwkFrameControl = gp_buildNwkFrameCtrl(NULL,FrameType,0,0,0,0,0,1);  
  }
  else
  {
    extNwkFrameControl = GP_EXT_NWK_APP_DIRECTION_MASK;
    nwkFrameControl = gp_buildNwkFrameCtrl(&extNwkFrameControl,FrameType,0,0,0,0,0,1);
  }
  
  mpdu = gp_GenerateGPDF(&mpduLen,nwkFrameControl,0,&gpTxQueueList[i].gp_DataReq->gpd_ID,gpTxQueueList[i].gp_DataReq->EndPoint,0,0,gpTxQueueList[i].gp_DataReq->GPDasduLength,gpTxQueueList[i].gp_DataReq->GPDasdu, gpTxQueueList[i].gp_DataReq->GPDCmmdId);

  CGP_DataReq(gpTxQueueList[i].gp_DataReq->TxOptions, &SrcAddr,_NIB.nwkPanId,&DstAddr,dstPanID,mpduLen,mpdu,gpTxQueueList[i].gp_DataReq->GPEPhandle,timestamp);
  
  osal_mem_free (mpdu);

}



#if 0
bool gp_processMaintenanceFrame(void)
{
  uint8 i;

  //drop duplicated packets
  if(gpdfMaintenanceInProcess)
  {
    return TRUE;
  }
    
  for (i = 0; i < gGP_TX_QUEUE_MAX_ENTRY; i++)
  {
    if(gpTxQueueList[i].gp_DataReq->gpd_ID.AppID == GP_APP_ID_DEFAULT)
    {
      if(gpTxQueueList[i].gp_DataReq->gpd_ID.GPDId.SrcID == 0)
      {
        uint8         *mpdu;
        uint8         mpduLen = 0;
        uint8         nwkFrameControl = 0;
        uint16        dstPanID = 0xFFFF;
        zAddrType_t   SrcAddr;
        zAddrType_t   DstAddr;

        SrcAddr.addrMode = 0;  //Not present
        DstAddr.addr.shortAddr = 0xFFFF;
        DstAddr.addrMode = Addr16Bit;

        //Maintenance frames do not use ACK neither CSMA
        gpTxQueueList[i].gp_DataReq->TxOptions = 0;

        nwkFrameControl = gp_buildNwkFrameCtrl(NULL,GP_NWK_FRAME_TYPE_MAINTENANCE,0,0,0,0,0,1);

        mpdu = gp_GenerateGPDF(&mpduLen,nwkFrameControl,0,&gpTxQueueList[i].gp_DataReq->gpd_ID,gpTxQueueList[i].gp_DataReq->EndPoint,0,0,gpTxQueueList[i].gp_DataReq->GPDasduLength,gpTxQueueList[i].gp_DataReq->GPDasdu, gpTxQueueList[i].gp_DataReq->GPDCmmdId);

        if(ZSuccess == CGP_DataReq(gpTxQueueList[i].gp_DataReq->TxOptions, &SrcAddr,_NIB.nwkPanId,&DstAddr,dstPanID,mpduLen,mpdu,gpTxQueueList[i].gp_DataReq->GPEPhandle))
        {
          //Maintenance frame in process
          gpdfMaintenanceInProcess = TRUE;
        }  
        osal_mem_free (mpdu);
      }
    }
  }
  
  return TRUE;
}
#endif



uint8 gp_buildNwkFrameCtrl(uint8* pExtNwkFrameControl, uint8 FrameType, uint8 AutoCommissioning, uint8 AppId, uint8 securityLvl, uint8 SecKey, bool RxAfterTx, bool Direction)
{
  uint8 nwkFrameControl = 0;

  nwkFrameControl = FrameType;

  nwkFrameControl |= (GP_ZIGBEE_PROTOCOL_VER << GP_ZIGBEE_PROTOCOL_VERSION_POS );

  if(AutoCommissioning)
  {
    nwkFrameControl |= GP_AUTO_COMM_MASK;
  }
  
  if(pExtNwkFrameControl)
  {
    nwkFrameControl |= GP_NWK_FRAME_CTRL_EXT_MASK;

    *pExtNwkFrameControl = AppId;
    
    *pExtNwkFrameControl |= (securityLvl << GP_EXT_NWK_APP_SEC_LVL_POS);
    *pExtNwkFrameControl |= (SecKey      << GP_EXT_NWK_APP_SEC_KEY_POS);
    *pExtNwkFrameControl |= (RxAfterTx   << GP_EXT_NWK_APP_RX_AFTER_TX_POS);
    *pExtNwkFrameControl |= (Direction   << GP_EXT_NWK_APP_DIRECTION_POS);
  }

return nwkFrameControl;
}


 
/*********************************************************************
 * @fn          gp_SecBuildHeader
 *
 * @brief         Build GreenPower Security header for incoming/outgoing GPDF
 *
 * @param [in]    gp_DataInd    - Parameters to build the header
 * @param [in]    header        - Pointer to memory buffer in which the header is located
 * @param [in]    headerLen     - Header length
 *
 *                NOTE: Calling function needs to release header memory
 *
 * @return        ZInvalidParameter
 *                ZFailure - No memory
 */ 
ZStatus_t gp_SecBuildHeader(gp_DataInd_t *gp_DataInd, uint8 **header, uint8 *headerLen)
{
  uint8 NwkFrameCounter;
  uint8 ExtNwkFrameCounter;
  uint8 *tempHeader;
  
  if(headerLen == NULL)
  {
    return ZInvalidParameter;
  }
  
  //NwkframeCtrl + ExtNwkFrameCtrl
  *headerLen = 2;

  if(gp_DataInd->appID == GP_APP_ID_DEFAULT)
  {
    //include SrcId
    *headerLen += sizeof(uint32);
  }
  //Include FrameCounter
  *headerLen += sizeof(uint32);

  //build NwkFrameCtrl and ExtNwkFrameCntrl
  NwkFrameCounter = gp_buildNwkFrameCtrl(&ExtNwkFrameCounter, GP_NWK_FRAME_TYPE_DATA,
                                         gp_DataInd->AutoCommissioning, gp_DataInd->appID,
                                         gp_DataInd->GPDFSecLvl, gp_DataInd->GPDFKeyType,
                                         gp_DataInd->RxAfterTx,0);
  
  if(gp_DataInd->GPDFSecLvl == GP_SECURITY_LVL_4FC_4MIC_ENCRYPT)
  {
    *header = osal_mem_alloc((uint16)*headerLen);
    if(header == NULL)
    {
      return ZFailure;
    }
  }
  else if(gp_DataInd->GPDFSecLvl == GP_SECURITY_LVL_4FC_4MIC)
  {
    *headerLen += gp_DataInd->GPDasduLength;
    
    *header = osal_mem_alloc((uint16)*headerLen);
    if(header == NULL)
    {
      return ZFailure;
    }
  }
  else
  {
    return ZInvalidParameter;
  }

  tempHeader = *header;
  *tempHeader = NwkFrameCounter;
  tempHeader++;
  
  *tempHeader = ExtNwkFrameCounter;
  tempHeader++;
  if(gp_DataInd->appID == GP_APP_ID_DEFAULT)
  {
    osal_memcpy(tempHeader,(uint8*)&gp_DataInd->SrcId,sizeof(uint32));
    tempHeader += sizeof(uint32);
  }
  osal_memcpy(tempHeader,(uint8*)&gp_DataInd->GPDSecFrameCounter,sizeof(uint32));
  tempHeader += sizeof(uint32);
  
  if(gp_DataInd->GPDFSecLvl == GP_SECURITY_LVL_4FC_4MIC)
  {
    //Plus one to include the payload
    osal_memcpy(tempHeader,&gp_DataInd->GPDasdu,gp_DataInd->GPDasduLength);
  }
  
  return ZSuccess;
}

 
/*********************************************************************
 * @fn          gp_SecBuildNonce
 *
 * @brief         Build GreenPower Nonce for incoming/outgoing GPDF
 *
 * @param [in]    isOutgoingMsg - TRUE for outgoing GPDF, FALSE for incomming GPDF 
 * @param [in]    gpd_ID        - Address structure for the incomming/outgoing GPDF
 * @param [in]    FrameCounter  - Framecounter of the incomming/outgoing GPDF
 * @param [out]   gp_AESNonce   - AES nonce constructed 
 *
 * @return      none
 */
ZStatus_t gp_SecBuildNonce(bool isOutgoingMsg,gpd_ID_t *gpd_ID, uint32 FrameCounter,uint8 *gp_AESNonce)
{
  if(gp_AESNonce == NULL)
  {
    return ZInvalidParameter;
  }
  
  ((gp_AESNonce_t*)gp_AESNonce)->securityControl = GP_NONCE_SEC_CONTROL;

  if(gpd_ID->AppID == GP_APP_ID_DEFAULT)
  {
    osal_buffer_uint32(&((gp_AESNonce_t*)gp_AESNonce)->SourceAddr[4],gpd_ID->GPDId.SrcID);
    if(isOutgoingMsg)
    {
      osal_memset(&((gp_AESNonce_t*)gp_AESNonce)->SourceAddr[0],0,sizeof(uint32));
    }
    else
    {
      osal_buffer_uint32(&((gp_AESNonce_t*)gp_AESNonce)->SourceAddr[0],gpd_ID->GPDId.SrcID);
    }
  }
  else if(gpd_ID->AppID == GP_APP_ID_GP)
  {
    osal_memcpy(((gp_AESNonce_t*)gp_AESNonce)->SourceAddr, gpd_ID->GPDId.GPDExtAddr,Z_EXTADDR_LEN);
    if(isOutgoingMsg)
    {
      ((gp_AESNonce_t*)gp_AESNonce)->securityControl = GP_NONCE_SEC_CONTROL_OUTGOING_APP_ID_GP;
    }
  }
  //Not supported other applications ID
  else
  {
    return ZInvalidParameter;
  }
  osal_buffer_uint32((uint8*)&((gp_AESNonce_t*)gp_AESNonce)->FrameCounter, FrameCounter);
  
  return ZSuccess;
}
 
 
/*********************************************************************
 * @fn          gp_DataIndAppendToList
 *
 * @brief       Append a DataInd to a list of DataInd (waiting for GP Sec Rsp List, 
 *              or list to filter duplicate packets)
 *
 * @param       gp_DataInd to be appended
 *
 * @return      None
 */
void gp_DataIndAppendToList(gp_DataInd_t *gp_DataInd, gp_DataInd_t **DataIndList)
{
  if(dgp_DataIndList == NULL)
  {
    *DataIndList = gp_DataInd;
  }
  else
  {
    gp_DataInd_t *dgp_DataIndTemp;
    
    dgp_DataIndTemp = *DataIndList;
    while(dgp_DataIndTemp->SecReqHandling.next != NULL)
    {
      dgp_DataIndTemp = dgp_DataIndTemp->SecReqHandling.next;
    }
    dgp_DataIndTemp->SecReqHandling.next = gp_DataInd;
  }
}


/*********************************************************************
 * @fn          gp_DataIndGet
 *
 * @brief       Search for a DataInd entry with matching handle
 *
 * @param       handle to search for
 *
 * @return      gp_DataInd entry, or NULL if not found
 */
gp_DataInd_t* gp_DataIndGet(uint8 handle)
{
  gp_DataInd_t* temp;  
 
  temp = dgp_DataIndList;
  
  if(temp != NULL)
  {
    while((temp->SecReqHandling.dGPStubHandle != handle) && (temp != NULL))
    {
      temp = temp->SecReqHandling.next;
    }
  }
  return temp;
}

/*********************************************************************
 * @fn          gp_FreeGpTxQueue
 *
 * @brief       Release the list of packets in the gpTxQueue
 *
 * @param       none
 *
 * @return      none
 */
void gp_FreeGpTxQueue(void)
{
  uint8 i;
  
  for (i = 0; i < gGP_TX_QUEUE_MAX_ENTRY; i++)
  {
    if(gpTxQueueList[i].gp_DataReq != NULL)
    {
      osal_msg_deallocate((void*)gpTxQueueList[i].gp_DataReq);
      gpTxQueueList[i].gp_DataReq = NULL;
    }
  }
}




/*********************************************************************
* @fn          gp_GetHandle
*
* @brief       Returns a new handle for the type of msg.
*
* @param       handleType - type of handle to request 
*
* @return      handle - returns the value of the handle, if 
*              0 the handle was not valid
*/
 uint8 gp_GetHandle(uint8 handleType)
 {
   uint8  tempHandle = 0;
   uint8* pHandleData = NULL;
   getHandleFunction_t  pGetHandleFunction = NULL;
   
   switch(handleType)
   {
     case DGP_HANDLE_TYPE:
       pGetHandleFunction = dGP_findHandle;
       pHandleData = &dGP_StubHandle;
     break;
     case GPEP_HANDLE_TYPE:
       pGetHandleFunction = GPEP_findHandle;
       pHandleData = &GPEP_Handle;
     break;
   }
   
   if((pGetHandleFunction == NULL) || (pHandleData == NULL))
   {
     return tempHandle;
   }
   
   do
   {
     tempHandle = (*pHandleData)++;
     //check if the handle is not in use by other msg
     if(pGetHandleFunction(tempHandle) != NULL)
     {
       tempHandle = 0;
     }
   }
   while ( tempHandle == 0);
   
   return tempHandle;
 }



uint8* dGP_findHandle(uint8 handle)
{
  gp_DataInd_t *temp = dgp_DataIndList;
  
  while(temp != NULL)
  {
    if(temp->SecReqHandling.dGPStubHandle == handle)
    {
      return (uint8*)temp;
    }
    temp = temp->SecReqHandling.next;
  }
  return (uint8*)temp;
}

uint8* GPEP_findHandle(uint8 handle)
{
  //No list of GPEP messages to check with. See GP-DataCnf
  return NULL;
}




 /*********************************************************************
 * @fn          gp_Init
 *
 * @brief       Initialization function for the Green Power Stubs.
 *
 * @param       task_id - gp_TaskID Task ID
 *
 * @return      none
 */
void gp_Init( byte task_id )
{
  uint8 i;
  gp_TaskID = task_id;
  


  
  for(i=0; i < gGP_TX_QUEUE_MAX_ENTRY; i++)
  {
    gpTxQueueList[i].gp_DataReq = NULL;
  }
  dgp_DataIndList = NULL;
}
 


/*********************************************************************
 * @fn      gp_event_loop
 *
 * @brief   Main event loop for the GP task. This function
 *          is called to process all events for the task.  Events
 *          include timers, messages and any other user defined events.
 *
 * @param   task_id  - The OSAL assigned task ID.
 * @param   events - events to process.  This is a bit map and can
 *                   contain more than one event.
 *
 * @return  none
 */
UINT16 gp_event_loop( uint8 task_id, UINT16 events )
{
  (void)task_id;  // Intentionally unreferenced parameter
  
  if ( events & SYS_EVENT_MSG )
  {
    gp_sys_event_processing();
    
    return ( events ^ SYS_EVENT_MSG );
  }
  

  if(events & GP_DUPLICATE_FILTERING_TIMEOUT_EVENT)
  {
    if(GP_expireDuplicateFilteringGCB)
    {
      GP_expireDuplicateFilteringGCB();
    }
    
    return ( events ^ GP_DUPLICATE_FILTERING_TIMEOUT_EVENT );
  }

  if(events & GP_COMMISSIONING_WINDOW_TIMEOUT)
  {
    if(GP_stopCommissioningModeGCB)
    {
      GP_stopCommissioningModeGCB();
    }

    return ( events ^ GP_COMMISSIONING_WINDOW_TIMEOUT );
  }

  if(events & GP_CHANNEL_CONFIGURATION_TIMEOUT)
  {
    if(GP_returnOperationalChannelGCB)
    {
      GP_returnOperationalChannelGCB();
    }
    return ( events ^ GP_CHANNEL_CONFIGURATION_TIMEOUT );
  }
  
  if(events & GP_PROXY_ALIAS_CONFLICT_TIMEOUT)
  {
    if(GP_aliasConflictAnnce != NULL)
    {
      ZDP_DeviceAnnce( GP_aliasConflictAnnce->nwkAddr, GP_aliasConflictAnnce->extAddr, 
                      GP_aliasConflictAnnce->capabilities, TRUE );
      GP_aliasConflictAnnce->nwkAddr = INVALID_NODE_ADDR;
    }
    return ( events ^ GP_PROXY_ALIAS_CONFLICT_TIMEOUT );
  }

  
  return 0;
}


static void gp_sys_event_processing(void)
{
  osal_event_hdr_t *msg_ptr;
  bool freeMsg = TRUE;

  if ( (msg_ptr = (osal_event_hdr_t *)osal_msg_receive( gp_TaskID )) != NULL )
  {
    if(msg_ptr->event == GP_MAC_MCPS_DATA_CNF)
    {
      uint8 status,handle;
      
      handle = ((macCbackEvent_t*)msg_ptr)->dataCnf.msduHandle;
      status = ((macCbackEvent_t*)msg_ptr)->dataCnf.hdr.status;
      
      CGP_DataCnf(status,handle);
    }
    
    if(msg_ptr->event == GP_MAC_MCPS_DATA_IND)
    {
      cGP_processMCPSDataInd((macMcpsDataInd_t *)msg_ptr);
    }
    //Here process other events
    if(msg_ptr->event == DGP_DATA_IND)
    {
      dGP_DataInd((dgp_DataInd_t*)msg_ptr);

      //Release the timestamps, those are already copied
      gpTimeTempBackoff = 0;
      gpTimeTempTimer = 0;
      gpLockTimestamp = FALSE;
    }

    if(msg_ptr->event == GP_SEC_RSP)
    {
      GP_SecRsp((gp_SecRsp_t*)msg_ptr);
    }

    if(msg_ptr->event == GP_DATA_REQ)
    {
      freeMsg = GP_DataReq((gp_DataReq_t*)msg_ptr);
    }
    
    if(msg_ptr->event == GP_DATA_IND)
    {
      if(GP_DataIndGCB)
      {
        freeMsg = GP_DataIndGCB((gp_DataInd_t*)msg_ptr);
      }

#if MT_GP_CB_FUNC
      MT_GPDataInd((gp_DataInd_t*)msg_ptr);
#endif
    }
    
    if(msg_ptr->event == GP_DATA_CNF)
    {
      if(GP_DataCnfGCB)
      {
        GP_DataCnfGCB((gp_DataCnf_t*)msg_ptr);
      }
      
#if MT_GP_CB_FUNC
      MT_GPDataCnf((gp_DataCnf_t*)msg_ptr);
#endif
    }
    
    if(msg_ptr->event == GP_SEC_REQ)
    {
      if(GP_SecReqGCB)
      {
        GP_SecReqGCB((gp_SecReq_t*)msg_ptr);
      }
      
#if MT_GP_CB_FUNC
      MT_GPSecReq((gp_SecReq_t*)msg_ptr);
#endif
    }    

  
    if(freeMsg)
    {
      osal_msg_deallocate( (uint8 *)msg_ptr );
    }
  }
}

 /*********************************************************************
*********************************************************************/

   
   