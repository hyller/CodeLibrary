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

//GP_UPDATE
   
#include "ZComDef.h"
#include "cGP_stub.h"
#include "gp_interface.h"
#include "OSAL.h"
#include "gp_common.h"
#include "dGP_stub.h"

 /*********************************************************************
 * MACROS
 */

 
 /*********************************************************************
 * CONSTANTS
 */

const uint32 gpTxOffset = 63; //20ms  A.1.5.2.1.2  Converted to Backoff units is 62.5, rounded to 63
const uint32 gpRxOffset = 63; //20ms  A.1.6.3.1

const uint32 gpMaxTxOffsetVariation = 5;  //5 ms  A.1.5.2.1.3
const uint32 gpTxDuration           = 10; //10ms  A.1.5.2.1.4

/*********************************************************************
 * TYPEDEFS
 */
 
 
 /*********************************************************************
 * GLOBAL VARIABLES
 */

uint32 gpTimeTempBackoff;
uint16 gpTimeTempTimer;
bool   gpLockTimestamp = FALSE;    

uint32 gpdfTimestamp  = 0;               // The time, in backoffs, at which the gpdf were received


 /*********************************************************************
 * EXTERNAL VARIABLES
 */



/*********************************************************************
 * EXTERNAL FUNCTIONS
 */


/*********************************************************************
 * LOCAL VARIABLES
 */

 /*********************************************************************
 * LOCAL FUNCTIONS
 */
  

/*********************************************************************
 * PUBLIC FUNCTIONS
 *********************************************************************/



/*********************************************************************
 * @fn          CGP_DataReq
 *
 * @brief       Allows dGP or dLPED stub send GPDF to GPD or LPED
 *
 * @param       TxOptions  - 
 * @param       SrcAddr    - 
 * @param       SrcPanID   - 
 * @param       dstAddr    - 
 * @param       DstPanID   - 
 * @param       mpdu_len   - 
 * @param       mpdu       - 
 * @param       mpduHandle - 
 *
 * @return      ZStatus_t
 */
uint16 gpTimeTempTimer2;
uint32 gpTimeTempBackoff2;
ZStatus_t CGP_DataReq(uint8 TxOptions, zAddrType_t *srcAddr, uint16 SrcPanID,  zAddrType_t *dstAddr, uint16 DstPanID, uint8 mpdu_len, uint8*  mpdu, uint8 mpduHandle,uint32 timestamp)
{
  ZMacDataReq_t macReq;
  
#ifdef TESTING_MAC_TIMERS
  gpTimeTempTimer2 = MAC_RADIO_TIMER_CAPTURE_CURRENT();
  gpTimeTempBackoff2 = MAC_RADIO_BACKOFF_CAPTURE_CURRENT();
  //HAL_TURN_OFF_LED1();
  //HAL_TURN_ON_LED1();
  //HAL_TURN_OFF_LED1();
  //HAL_TURN_ON_LED1();
  //HAL_TURN_OFF_LED1();
#endif  
  
  osal_memset( &macReq, 0, sizeof( ZMacDataReq_t ) );

  if( !(TxOptions & CGP_OPT_USE_CSMA_CA_MASK))
  {  
  
#ifdef GP_FIXED_TIME
    if(timestamp == 0)
    {
      //Maintenance frame
      macReq.GpOffset   = gpTxOffset;//TransmitWindowTimeout;//MAC_MIN_GREEN_PWR_DELAY; 
    }
    else if(timestamp == 1)
    {
      //Commissioning with RxAfterTx = 1
      macReq.GpOffset   = MAC_MIN_GREEN_PWR_DELAY;// gpTxOffset;//TransmitWindowTimeout;//MAC_MIN_GREEN_PWR_DELAY; 
    }
    else
    {
      //???
      macReq.GpOffset   = MAC_MIN_GREEN_PWR_DELAY; //gpTxOffset;//TransmitWindowTimeout;//MAC_MIN_GREEN_PWR_DELAY; 
    }
#else
    uint32  TimeSinceMacReception;
    uint32  TimeTemp;
    uint32  TransmitWindowTimeout;

    //TODO: Setting to keep the MAC counter running, do we need to stop it?
    //Get the current backoff counter
    TimeTemp = MAC_RADIO_BACKOFF_CAPTURE_CURRENT();
    

    if(TimeTemp < gpdfTimestamp)
    {
      //TODO: Validate with Suyash
      //Adjust the overflow, considering that this is 3 byte register
      TimeTemp += 0x01000000;
    }

    TimeSinceMacReception = TimeTemp - gpdfTimestamp;

    //Convertion to ms may not be necesary, backoff units in use
#if 0
    //TODO: Convert to ms divided by 1024
    //TODO: or perform operation of division by 1000
    //Convert to ms
    //TimeSinceMacReception = TimeSinceMacReception >> 10;    //Conver by dividing by 1024
    TimeSinceMacReception = TimeSinceMacReception / 1000;   //convert by dividing by 1000
    TimeSinceMacReception *= MAC_SPEC_USECS_PER_BACKOFF;
#endif
    //Calculate the time to transmit the frame

    //abort!!!
    if(TimeSinceMacReception > gpTxOffset)
    {
      return ZFailure;
    }
    TransmitWindowTimeout = gpTxOffset - TimeSinceMacReception;
    macReq.GpOffset   = TransmitWindowTimeout;//MAC_MIN_GREEN_PWR_DELAY; 
    
    
    //Restart the mac timestamp
    gpTimeTempBackoff = 0;
    gpTimeTempTimer = 0;
    gpLockTimestamp = FALSE;  
    
#endif
    
  macReq.GpDuration = 0;

  macReq.TxOptions |= MAC_TXOPTION_GREEN_PWR;
    
  }
  if(TxOptions & CGP_OPT_USE_MAC_ACK_MASK)
  {
    macReq.TxOptions |= MAC_TXOPTION_ACK;
  }

  
  osal_memcpy(&macReq.DstAddr, dstAddr,sizeof(zAddrType_t));
  
  macReq.DstPANId = DstPanID;
  macReq.SrcAddrMode = Addr16Bit;  

  macReq.Handle = mpduHandle;
  macReq.msdu = mpdu;
  macReq.msduLength = mpdu_len;
  
  return ZMacDataReqSec(&macReq,NULL);
  
}

/*********************************************************************
 * @fn          CGP_DataCnf
 *
 * @brief       This function reports the results CGP Data request being 
 *              handled by the cGP stub
 *
 * @param       status  - status returned by the MAC layer
 * @param       GPmpduHandle  - handle of the data request
 *
 * @return      none
 */
void CGP_DataCnf(uint8 Status, uint8 GPmpduHandle)
{
  uint8 GP_DataCnfStatus = GP_DATA_CNF_GPDF_SENDING_FINALIZED;
  
  dGP_DataCnf(GP_DataCnfStatus, GPmpduHandle);
    
  //TODO: Notify via serial interface.
}







 /*********************************************************************
 * PRIVATE FUNCTIONS
 *********************************************************************/


/*********************************************************************
 * dGP stub
 *********************************************************************/










  






/*********************************************************************
 * cGP stub
 *********************************************************************/


void cGP_processMCPSDataInd(macMcpsDataInd_t *pData)
{
  dgp_DataInd_t *dgp_DataInd;
  
  uint8 *pMsdu = pData->msdu.p;
  uint8 nwkFrameCtrl = *pMsdu;
  pMsdu++;
  
  //is GP frame
  if(((nwkFrameCtrl & GP_ZIGBEE_PROTOCOL_VERSION_MASK) >> GP_ZIGBEE_PROTOCOL_VERSION_POS) != GP_ZIGBEE_PROTOCOL_VER)
  {
    return;
  }
  
  //does the frame has nwk extension
  if((nwkFrameCtrl & GP_NWK_FRAME_CTRL_EXT_MASK) >> GP_NWK_FRAME_CTRL_EXT_POS)
  {
    uint8 ExtNwkFrameCtrl;
    uint8 AppId;
    
    ExtNwkFrameCtrl = *pMsdu;
    pMsdu++;
    AppId = (ExtNwkFrameCtrl & GP_EXT_NWK_APP_ID_MASK) >> GP_EXT_NWK_APP_ID_POS;
    
    //LPED app not supported
    if(AppId == GP_APP_ID_LPED)
    {
      return;
    }

    //AppID not defined yet, must be dropped
    if(AppId > GP_APP_ID_GP)
    {
      return;
    }
    //Drop frames with direction set to 1
    if(ExtNwkFrameCtrl & GP_EXT_NWK_APP_DIRECTION_MASK)
    {
      return;
    }
  }
  
  //Size of the structure, - 1 to hold mpdu + msdu length
  dgp_DataInd = (dgp_DataInd_t*)osal_msg_allocate(sizeof(dgp_DataInd_t)-1 + pData->msdu.len);
  
  if(dgp_DataInd!= NULL)
  {
    dgp_DataInd->hdr.status = 0;
    dgp_DataInd->hdr.event = DGP_DATA_IND;
  
    osal_memcpy(&dgp_DataInd->dstAddr,&pData->mac.dstAddr,sizeof(sAddr_t));
    osal_memcpy(&dgp_DataInd->srcAddr,&pData->mac.srcAddr,sizeof(sAddr_t));
    
    dgp_DataInd->dstPanID = pData->mac.dstPanId;
    dgp_DataInd->srcPanID = pData->mac.srcPanId;
    dgp_DataInd->LinkQuality = pData->mac.mpduLinkQuality;
    dgp_DataInd->Rssi = pData->mac.rssi;
    dgp_DataInd->SeqNumber = pData->mac.dsn;
      
    osal_memcpy(&dgp_DataInd->mpdu,pData->msdu.p,pData->msdu.len);
    dgp_DataInd->mpduLen = pData->msdu.len;
      
    osal_msg_send( gp_TaskID, (uint8 *)dgp_DataInd );
  }
}





/*********************************************************************
*********************************************************************/

