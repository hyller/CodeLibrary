/**************************************************************************************************
  Filename:       bdb_FindingAndBinding.c
  Revised:        $Date: 2016-02-25 11:51:49 -0700 (Thu, 25 Feb 2016) $
  Revision:       $Revision: - $

  Description:    This file contains the Base Device Behavior functions and attributes.


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

#include "bdb.h"
#include "ZDObject.h"
#include "bdb_interface.h"
   
#if (BDB_FINDING_BINDING_CAPABILITY_ENABLED==1)   
   
/*********************************************************************
 * MACROS
 */
 
/*********************************************************************
 * CONSTANTS
 */
/*********************************************************************
 * TYPEDEFS
 */
 
 
/*********************************************************************
 * GLOBAL VARIABLES
 */

uint8 grpName[6] = {'G','r','o','u','p','\0'};
bdbGCB_IdentifyTimeChange_t      pfnIdentifyTimeChangeCB = NULL; 
bdbGCB_BindNotification_t        pfnBindNotificationCB = NULL;

/*********************************************************************
 * EXTERNAL VARIABLES
 */

/*********************************************************************
 * EXTERNAL FUNCTIONS
 */


/*********************************************************************
 * LOCAL VARIABLES
 */

SimpleDescriptionFormat_t  bdb_FindingBindingTargetSimpleDesc;

uint8 bdbIndentifyActiveEndpoint  = 0xFF;

//Your JOB:
//Remove the clusters that your application do not use. This will save some flash and processing
//when looking into matching clusters during the finding & binding procedure
const cId_t bdb_ZclType1Clusters[] =
{
  ZCL_CLUSTER_ID_GEN_SCENES,
  ZCL_CLUSTER_ID_GEN_ON_OFF,
  ZCL_CLUSTER_ID_GEN_LEVEL_CONTROL,
  ZCL_CLUSTER_ID_GEN_ALARMS,
  ZCL_CLUSTER_ID_GEN_PARTITION,
  ZCL_CLUSTER_ID_CLOSURES_WINDOW_COVERING,
  ZCL_CLUSTER_ID_HVAC_FAN_CONTROL,
  ZCL_CLUSTER_ID_HVAC_DIHUMIDIFICATION_CONTROL,
  ZCL_CLUSTER_ID_LIGHTING_COLOR_CONTROL,
  ZCL_CLUSTER_ID_LIGHTING_BALLAST_CONFIG,
  ZCL_CLUSTER_ID_SS_IAS_ACE,
  ZCL_CLUSTER_ID_SS_IAS_WD,
  ZCL_CLUSTER_ID_PI_GENERIC_TUNNEL,
  ZCL_CLUSTER_ID_PI_BACNET_PROTOCOL_TUNNEL,
  ZCL_CLUSTER_ID_HA_ELECTRICAL_MEASUREMENT,
  ZCL_CLUSTER_ID_PI_11073_PROTOCOL_TUNNEL,
  ZCL_CLUSTER_ID_PI_ISO7818_PROTOCOL_TUNNEL,
  ZCL_CLUSTER_ID_PI_RETAIL_TUNNEL,
  ZCL_CLUSTER_ID_SE_PRICE,
  ZCL_CLUSTER_ID_SE_DRLC,
  ZCL_CLUSTER_ID_SE_METERING,
  ZCL_CLUSTER_ID_SE_MESSAGING,
  ZCL_CLUSTER_ID_TELECOMMUNICATIONS_INFORMATION,
  ZCL_CLUSTER_ID_TELECOMMUNICATIONS_VOICE_OVER_ZIGBEE,
};

//Your JOB:
//Remove the clusters that your application do not use. This will save some flash and processing
//when looking into matching clusters during the finding & binding procedure
const cId_t bdb_ZclType2Clusters[] =
{
  ZCL_CLUSTER_ID_GEN_ON_OFF_SWITCH_CONFIG,
  ZCL_CLUSTER_ID_GEN_TIME,
  ZCL_CLUSTER_ID_GEN_ANALOG_INPUT_BASIC,
  ZCL_CLUSTER_ID_GEN_ANALOG_OUTPUT_BASIC,
  ZCL_CLUSTER_ID_GEN_ANALOG_VALUE_BASIC,
  ZCL_CLUSTER_ID_GEN_BINARY_INPUT_BASIC,
  ZCL_CLUSTER_ID_GEN_BINARY_OUTPUT_BASIC,
  ZCL_CLUSTER_ID_GEN_BINARY_VALUE_BASIC,
  ZCL_CLUSTER_ID_GEN_MULTISTATE_INPUT_BASIC,
  ZCL_CLUSTER_ID_GEN_MULTISTATE_OUTPUT_BASIC,
  ZCL_CLUSTER_ID_GEN_MULTISTATE_VALUE_BASIC,
  ZCL_CLUSTER_ID_OTA,
  ZCL_CLUSTER_ID_GEN_APPLIANCE_CONTROL,
  ZCL_CLUSTER_ID_CLOSURES_SHADE_CONFIG,
  ZCL_CLUSTER_ID_CLOSURES_DOOR_LOCK,
  ZCL_CLUSTER_ID_HVAC_PUMP_CONFIG_CONTROL,
  ZCL_CLUSTER_ID_HVAC_THERMOSTAT,
  ZCL_CLUSTER_ID_MS_TEMPERATURE_MEASUREMENT,
  ZCL_CLUSTER_ID_MS_ILLUMINANCE_MEASUREMENT,
  ZCL_CLUSTER_ID_MS_ILLUMINANCE_LEVEL_SENSING_CONFIG,
  ZCL_CLUSTER_ID_MS_PRESSURE_MEASUREMENT,
  ZCL_CLUSTER_ID_MS_FLOW_MEASUREMENT,
  ZCL_CLUSTER_ID_MS_RELATIVE_HUMIDITY,
  ZCL_CLUSTER_ID_MS_OCCUPANCY_SENSING,
  ZCL_CLUSTER_ID_SS_IAS_ZONE,
  ZCL_CLUSTER_ID_PI_ANALOG_INPUT_BACNET_REG,
  ZCL_CLUSTER_ID_PI_ANALOG_INPUT_BACNET_EXT,
  ZCL_CLUSTER_ID_PI_ANALOG_OUTPUT_BACNET_REG,
  ZCL_CLUSTER_ID_PI_ANALOG_OUTPUT_BACNET_EXT,
  ZCL_CLUSTER_ID_PI_ANALOG_VALUE_BACNET_REG,
  ZCL_CLUSTER_ID_PI_ANALOG_VALUE_BACNET_EXT,
  ZCL_CLUSTER_ID_PI_BINARY_INPUT_BACNET_REG,
  ZCL_CLUSTER_ID_PI_BINARY_INPUT_BACNET_EXT,
  ZCL_CLUSTER_ID_PI_BINARY_OUTPUT_BACNET_REG,
  ZCL_CLUSTER_ID_PI_BINARY_OUTPUT_BACNET_EXT,
  ZCL_CLUSTER_ID_PI_BINARY_VALUE_BACNET_REG,
  ZCL_CLUSTER_ID_PI_BINARY_VALUE_BACNET_EXT,
  ZCL_CLUSTER_ID_PI_MULTISTATE_INPUT_BACNET_REG,
  ZCL_CLUSTER_ID_PI_MULTISTATE_INPUT_BACNET_EXT,
  ZCL_CLUSTER_ID_PI_MULTISTATE_OUTPUT_BACNET_REG,
  ZCL_CLUSTER_ID_PI_MULTISTATE_OUTPUT_BACNET_EXT,
  ZCL_CLUSTER_ID_PI_MULTISTATE_VALUE_BACNET_REG,
  ZCL_CLUSTER_ID_PI_MULTISTATE_VALUE_BACNET_EXT,
  ZCL_CLUSTER_ID_SE_TUNNELING,
  ZCL_CLUSTER_ID_TELECOMMUNICATIONS_INFORMATION,
  ZCL_CLUSTER_ID_HA_APPLIANCE_IDENTIFICATION,
  ZCL_CLUSTER_ID_HA_METER_IDENTIFICATION,
  ZCL_CLUSTER_ID_HA_APPLIANCE_EVENTS_ALERTS,
  ZCL_CLUSTER_ID_HA_APPLIANCE_STATISTICS,
};

 /*********************************************************************
 * LOCAL FUNCTIONS
 */
static ZStatus_t bdb_zclFindingBindingAddBindEntry( byte SrcEndpInt,
                                  uint16 BindClusterId,
                                  byte Cnt,                 
                                  uint16 * ClusterList,
                                  zAddrType_t *DstAddr, byte DstEndpInt );

uint8 bdb_FindIfAppCluster( cId_t ClusterId );


static void bdb_zclSimpleDescClusterListClean( SimpleDescriptionFormat_t *pSimpleDesc );
bdbFindingBindingRespondent_t* bdb_findRespondentNode(uint8 endpoint, uint16 shortAddress);
bdbFindingBindingRespondent_t* bdb_getRespondentRetry(bdbFindingBindingRespondent_t* pRespondentHead);
 /*********************************************************************
 * PUBLIC FUNCTIONS
 *********************************************************************/
void bdb_BindIfMatch( bdbInMsg_t *msgPtr );


/*********************************************************************
 * @fn      bdb_SetIdentifyActiveEndpoint
 *
 * @brief   Set the endpoint which will perform the finding and binding (either Target or Initiator)
 *
 * @param   Active endpoint with which perform F&B. If set to 0xFF all endpoints with Identify will be attempted.
 *
 * @return  ZFailure - F&B commissioning mode already requested
 *          ZInvalidParameter - Endpoint specified not found or reserved by Zigbee
 *          ZSuccess - 
 */
ZStatus_t bdb_SetIdentifyActiveEndpoint(uint8 activeEndpoint)
{
  epList_t *bdb_EpDescriptorListTemp = NULL;
  
  //Cannot process the request if no endpoints or F&B is under process
  if(bdbAttributes.bdbCommissioningMode & BDB_COMMISSIONING_MODE_FINDING_BINDING)
  {
    return ZFailure;
  }
  
  if(activeEndpoint == 0xFF)
  {
    bdbIndentifyActiveEndpoint = activeEndpoint;
    return ZSuccess;
  }
  
  if((activeEndpoint != 0) && (activeEndpoint < BDB_ZIGBEE_RESERVED_ENDPOINTS_START))
  {
    bdb_EpDescriptorListTemp = bdb_HeadEpDescriptorList;
    
    while(bdb_EpDescriptorListTemp != NULL)
    {
      if(bdb_EpDescriptorListTemp->epDesc->endPoint == activeEndpoint)
      {
        bdbIndentifyActiveEndpoint = activeEndpoint;
        return ZSuccess;
      }
      bdb_EpDescriptorListTemp = bdb_EpDescriptorListTemp->nextDesc;
    }
  }
  
  return ZInvalidParameter;
}


/*********************************************************************
 * @fn      bdb_setEpDescListToActiveEndpoint
 *
 * @brief   Set the endpoint list to the active endpoint selected by the application for F&B process
 *
 * @return  Current endpoint descriptor
 */

endPointDesc_t* bdb_setEpDescListToActiveEndpoint(void)
{
  bdb_CurrEpDescriptorList = bdb_HeadEpDescriptorList;
 
  //Check which active endpoit is being requested
  if(bdbIndentifyActiveEndpoint != 0xFF)
  {
    //Search for an specific endpoint
    while(bdb_CurrEpDescriptorList != NULL)
    {
      if(bdb_CurrEpDescriptorList->epDesc->endPoint == bdbIndentifyActiveEndpoint)
      {
        return bdb_CurrEpDescriptorList->epDesc;
      }
      bdb_CurrEpDescriptorList = bdb_CurrEpDescriptorList->nextDesc;
    }
  }
  else
  {
    //Look for the first endpoint that has Identify cluster
    while(bdb_CurrEpDescriptorList != NULL)
    {
      if((bdb_CurrEpDescriptorList->epDesc->endPoint != 0) && (bdb_CurrEpDescriptorList->epDesc->endPoint < BDB_ZIGBEE_RESERVED_ENDPOINTS_START))
      {
        return bdb_CurrEpDescriptorList->epDesc;
      }
      bdb_CurrEpDescriptorList = bdb_CurrEpDescriptorList->nextDesc;
    }
  }
  //not found
  return NULL;
}



/*********************************************************************
 * @fn      bdb_BindIfMatch
 *
 * @brief   To add binds in local table if a cluster in a simple descriptor
 *          from a remote finding and binding respondent matches
 *
 * @param   msgPtr - pointer to simple descriptor response indication message
 *
 * @return  none
 */
void bdb_BindIfMatch( bdbInMsg_t *msgPtr )
{
  ZStatus_t status;
  zAddrType_t dstAddr;
  uint8 i;
  endPointDesc_t *bdb_CurrEpDescriptor;
  bdbFindingBindingRespondent_t *pCurr;
#ifdef ZCL_GROUPS  
  afAddrType_t afDstAddr;
  uint8 isBindAdded;
#endif  
  
  dstAddr.addr.shortAddr = BUILD_UINT16( msgPtr->buf[1], msgPtr->buf[2] );
  dstAddr.addrMode = Addr16Bit;
  
  ZDO_ParseSimpleDescBuf( &msgPtr->buf[4], &bdb_FindingBindingTargetSimpleDesc );
  
  pCurr = bdb_findRespondentNode(bdb_FindingBindingTargetSimpleDesc.EndPoint, dstAddr.addr.shortAddr);
  
  //Just for safety check this is valid
  if(pCurr != NULL) 
  {
    //Mark as processed
    pCurr->attempts = FINDING_AND_BINDING_MAX_ATTEMPTS;
  }
  
  while(bdb_CurrEpDescriptorList != NULL)
  {
#ifdef ZCL_GROUPS  
    isBindAdded = FALSE;
#endif

    bdb_CurrEpDescriptor = bdb_CurrEpDescriptorList->epDesc;
  
    for(i = 0; i < bdb_CurrEpDescriptor->simpleDesc->AppNumOutClusters; i++)
    {
      //Filter for Application clusters (to bind app clusters only)
      status = bdb_zclFindingBindingAddBindEntry( bdb_CurrEpDescriptor->endPoint,
                              bdb_CurrEpDescriptor->simpleDesc->pAppOutClusterList[i],
                              bdb_FindingBindingTargetSimpleDesc.AppNumInClusters,
                              bdb_FindingBindingTargetSimpleDesc.pAppInClusterList,
                              &dstAddr, bdb_FindingBindingTargetSimpleDesc.EndPoint );
#ifdef ZCL_GROUPS      
      if(status == ZSuccess)
      {
        isBindAdded = TRUE;
      }
#endif
      
      if ( status == ZApsTableFull )
      {
        break;
      }
      
    }
    
    if(status != ZApsTableFull)
    {
      for(i = 0; i < bdb_CurrEpDescriptor->simpleDesc->AppNumInClusters; i++)
      {
        //Filter for Application clusters (to bind app clusters only)
        status = bdb_zclFindingBindingAddBindEntry( bdb_CurrEpDescriptor->endPoint,
                                bdb_CurrEpDescriptor->simpleDesc->pAppInClusterList[i],
                                bdb_FindingBindingTargetSimpleDesc.AppNumOutClusters,
                                bdb_FindingBindingTargetSimpleDesc.pAppOutClusterList,
                                &dstAddr, bdb_FindingBindingTargetSimpleDesc.EndPoint );
  #ifdef ZCL_GROUPS      
        if(status == ZSuccess)
        {
          isBindAdded = TRUE;
        }
  #endif
        
        if ( status == ZApsTableFull )
        {
          break;
        }
      }
    }


#ifdef ZCL_GROUPS
    // Configure Group

    if ( ( isBindAdded == TRUE ) && ( bdbAttributes.bdbCommissioningGroupID != 0xFFFF ) )
    {
      afDstAddr.addr.shortAddr = dstAddr.addr.shortAddr;
      afDstAddr.addrMode = afAddr16Bit;
      afDstAddr.endPoint = bdb_FindingBindingTargetSimpleDesc.EndPoint;
          
      zclGeneral_SendAddGroupRequest( bdb_CurrEpDescriptor->endPoint, &afDstAddr,
                                  COMMAND_GROUP_ADD, bdbAttributes.bdbCommissioningGroupID, grpName,
                                  TRUE, 0x00 );
    }
#endif
    
    if ( status == ZApsTableFull )
    {
      //If periodic was triggered, then finish it
      if(FINDING_AND_BINDING_PERIODIC_ENABLE == TRUE)                                  
      {
        bdb_FB_InitiatorCurrentCyclesNumber = 0;
        osal_stop_timerEx(bdb_TaskID, BDB_FINDING_AND_BINDING_PERIOD_TIMEOUT);
      }      
      
      // free messages
      osal_msg_deallocate( (uint8*)msgPtr );
      bdb_zclSimpleDescClusterListClean( &bdb_FindingBindingTargetSimpleDesc );
      osal_stop_timerEx( bdb_TaskID, BDB_RESPONDENT_SIMPLEDESC_TIMEOUT );
      bdb_exitFindingBindingWStatus( BDB_COMMISSIONING_FB_BINDING_TABLE_FULL );
      
      return;
    }
    
    if(bdbIndentifyActiveEndpoint != 0xFF)
    {
      break;
    }
    
    bdb_CurrEpDescriptorList = bdb_CurrEpDescriptorList->nextDesc;
  }
  
  // free messages
  osal_msg_deallocate( (uint8*)msgPtr );
  bdb_zclSimpleDescClusterListClean( &bdb_FindingBindingTargetSimpleDesc );  
}

/*********************************************************************
 * @fn      bdb_zclFindingBindingEpType
 *
 * @brief   Gives the Ep Type according to application clusters in
 *          simple descriptor
 *
 * @return  epType - If Target, Initiator or both
 */
uint8 bdb_zclFindingBindingEpType( endPointDesc_t *epDesc )
{
  uint8 epType = 0;
  uint8 status;
  uint8 type1ClusterCnt;
  uint8 type2ClusterCnt;
  
  type1ClusterCnt = sizeof( bdb_ZclType1Clusters )/sizeof( uint16 );
  type2ClusterCnt = sizeof( bdb_ZclType2Clusters )/sizeof( uint16 );
  

  // Are there matching type 1 on server side?
  status = ZDO_AnyClusterMatches( epDesc->simpleDesc->AppNumInClusters, 
                                  epDesc->simpleDesc->pAppInClusterList,
                                  type1ClusterCnt,
                                  (uint16*)bdb_ZclType1Clusters);
  
  if( status == TRUE )
  {
    epType |= BDB_FINDING_AND_BINDING_TARGET;
  }
  
  // Are there matching type 1 on client side?
  status = ZDO_AnyClusterMatches( epDesc->simpleDesc->AppNumOutClusters, 
                                  epDesc->simpleDesc->pAppOutClusterList,
                                  type1ClusterCnt,
                                  (uint16*)bdb_ZclType1Clusters);
  
  if( status == TRUE )
  {
    epType |= BDB_FINDING_AND_BINDING_INITIATOR;
  }
  
  // Are there matching type 2 on server side?
  status = ZDO_AnyClusterMatches( epDesc->simpleDesc->AppNumInClusters, 
                                  epDesc->simpleDesc->pAppInClusterList,
                                  type2ClusterCnt,
                                  (uint16*)bdb_ZclType2Clusters);
  
  if( status == TRUE )
  {
    epType |= BDB_FINDING_AND_BINDING_INITIATOR;
  }
  
  // Are there matching type 2 on client side?
  status = ZDO_AnyClusterMatches( epDesc->simpleDesc->AppNumOutClusters, 
                                  epDesc->simpleDesc->pAppOutClusterList,
                                  type2ClusterCnt,
                                  (uint16*)bdb_ZclType2Clusters);
  
  if( status == TRUE )
  {
    epType |= BDB_FINDING_AND_BINDING_TARGET;
  }

  return epType;

}

/*********************************************************************
 * @fn      bdb_zclFindingBindingAddBindEntry
 *
 * @brief   This function is used to Add an entry to the binding table
 *
 * @param   SrcEndpInt - source endpoint
 * @param   BindClusterId - cluster to try bind
 * @param   Cnt - list of remote clusters
 * @param   ClusterList - pointer to the Object ID list
 * @param   DstAddr - Address of remote node
 * @param   DstEndpInt - EndPoint of remote node
 *
 * @return  status - Success if added
 */
static ZStatus_t bdb_zclFindingBindingAddBindEntry( byte SrcEndpInt,
                                  uint16 BindClusterId,
                                  byte Cnt,                 
                                  uint16 * ClusterList,
                                  zAddrType_t *DstAddr, byte DstEndpInt )
{
  uint8 status;

  if ( bdb_FindIfAppCluster ( BindClusterId ) != SUCCESS )
  {
    return ( ZApsFail ); // No App cluster with reportable Attributes
  }

  // Are there matching clusters?
  status = ZDO_AnyClusterMatches( Cnt, 
                                  ClusterList,
                                  1,
                                 &BindClusterId);
  if ( status == FALSE )
  {
    return ( ZApsFail ); // No matched Cluster
  }
  
  if ( pbindAddEntry )
  {
    // Add the entry into the binding table
    if ( pbindAddEntry( SrcEndpInt, DstAddr, DstEndpInt,
                           1, &BindClusterId ) )
    {
      return ( ZSuccess );
    }
    else
    {
      return ( ZApsTableFull );
    }
  }
  else
  {
    return ( ZApsNotSupported );
  }
}

/*********************************************************************
 * @fn      bdb_exitFindingBindingWStatus
 *
 * @brief   Clean respondent list and reports the status to bdb state machine
 *
 * @return  
 */
void bdb_exitFindingBindingWStatus( uint8 status )
{
  // bdb report status
  bdbAttributes.bdbCommissioningStatus = status;
  
  bdb_reportCommissioningState( BDB_COMMISSIONING_STATE_FINDING_BINDING, TRUE );
}

/*********************************************************************
 * @fn      bdb_zclSimpleDescClusterListClean
 *
 * @brief   This function free Simple Descriptor cluster lists
 *
 * @param   pSimpleDesc - pointer to simple descriptor
 *
 * @return  status
 */
static void bdb_zclSimpleDescClusterListClean( SimpleDescriptionFormat_t *pSimpleDesc )
{
  if(pSimpleDesc->pAppInClusterList != NULL)
  {
    osal_mem_free( pSimpleDesc->pAppInClusterList );
    pSimpleDesc->pAppInClusterList = ( cId_t* )NULL;
  }
  if(pSimpleDesc->pAppOutClusterList != NULL)
  {
    osal_mem_free( pSimpleDesc->pAppOutClusterList );
    pSimpleDesc->pAppOutClusterList = ( cId_t* )NULL;
  }
}

/*********************************************************************
 * @fn      bdb_RegisterIdentifyTimeChangeCB
 *
 * @brief   Register an Application's Identify Time change callback function
 *          to let know the application when identify is active or not.
 *
 * @param   pfnIdentify - application callback
 *
 * @return  none
 */
void bdb_RegisterIdentifyTimeChangeCB( bdbGCB_IdentifyTimeChange_t pfnIdentifyTimeChange )
{
  pfnIdentifyTimeChangeCB = pfnIdentifyTimeChange;
}

#if (FINDING_AND_BINDING_PERIODIC_ENABLE==TRUE)
/*********************************************************************
 * @fn      bdb_GetFBInitiatorStatus
 *
 * @brief   Get the F&B initiator status for periodic requests.
 *
 * @param   RemainingTime - in seconds
 * @param   AttemptsLeft - number of attempts to be done
 * @param   MatchesFound - Add the number of matches to this parameter
 *                         since the last bdb_GetFBInitiatorStatus call
 *
 * @return  none
 */
void bdb_GetFBInitiatorStatus(uint8 *RemainingTime, uint8* AttemptsLeft)
{
  if(RemainingTime != NULL)  
  {
    if (bdb_FB_InitiatorCurrentCyclesNumber == 0)
    {
      *RemainingTime = 0;
    }
    else
    {
      *RemainingTime = (bdb_FB_InitiatorCurrentCyclesNumber - 1) * FINDING_AND_BINDING_PERIODIC_TIME + ((osal_get_timeoutEx(bdb_TaskID, BDB_FINDING_AND_BINDING_PERIOD_TIMEOUT) + 999) / 1000);
    }
  }
  
  if(AttemptsLeft != NULL)
  {
    *AttemptsLeft = bdb_FB_InitiatorCurrentCyclesNumber;
  }
}
#endif

/*********************************************************************
 * @fn      bdb_RegisterBindNotificationCB
 *
 * @brief   Register an Application's notification callback function to let 
 *          know the application when a new bind is added to the binding table.
 *
 * @param   pfnIdentify - application callback
 *
 * @return  none
 */
void bdb_RegisterBindNotificationCB( bdbGCB_BindNotification_t pfnBindNotification )
{
  pfnBindNotificationCB = pfnBindNotification;
}

/*********************************************************************
 * @fn      bdb_SendIdentifyQuery
 *
 * @brief   Sends Identify query from the given endpoint
 *
 * @param   endpoint
 *
 * @return  ZStatus_t
 */
ZStatus_t bdb_SendIdentifyQuery( uint8 endpoint )
{
  afAddrType_t dstAddr;
  ZStatus_t    status;
  
  dstAddr.addr.shortAddr = NWK_BROADCAST_SHORTADDR_DEVALL;
  dstAddr.addrMode = afAddr16Bit;
  dstAddr.endPoint = 0xFF;

  status = zclGeneral_SendIdentifyQuery( endpoint, &dstAddr, TRUE, bdb_getZCLFrameCounter() ); 
  
  if(status == ZSuccess)
  {
    osal_start_timerEx( bdb_TaskID, BDB_RESPONDENT_SIMPLEDESC_TIMEOUT, IDENTIFY_QUERY_RSP_TIMEOUT );
  }
  
  return status;
}

/*********************************************************************
 * @fn      bdb_ZclIdentifyQueryCmdInd
 *
 * @brief   Callback from the ZCL General Cluster Library when
 *          it received an Identity Query Response Command for this 
 *          application.
 *
 * @param   srcAddr - source address and endpoint of the response message
 * @param   identifyTime - the number of seconds to identify yourself
 *
 * @return  none
 */
void bdb_ZclIdentifyQueryCmdInd( zclIdentifyQueryRsp_t *pCmd )
{
  bdbFindingBindingRespondent_t *pCurr;
  
  // Stop the timer before refresh
  osal_stop_timerEx( bdb_TaskID, BDB_RESPONDENT_SIMPLEDESC_TIMEOUT );
  
  // add new node to the list
  pCurr = bdb_AddRespondentNode( &pRespondentHead, pCmd );
  
  if(pCurr != NULL)
  {
    pCurr->data.addrMode = pCmd->srcAddr->addrMode;
    pCurr->data.addr.shortAddr = pCmd->srcAddr->addr.shortAddr;
    pCurr->data.endPoint = pCmd->srcAddr->endPoint;
    pCurr->data.panId = pCmd->srcAddr->panId;
    pCurr->attempts = 0;
  }
  
  //Process the identify query rsp
  osal_set_event(bdb_TaskID, BDB_RESPONDENT_SIMPLEDESC_TIMEOUT);
}

/*********************************************************************
 * @fn      bdb_SendSimpleDescReq
 *
 * @brief   Send Simple Descriptor request to current Finding and Binding
 *          respondent in the list.
 *
 * @param   none
 *
 * @return  none
 */
void bdb_SendSimpleDescReq( void )
{
zAddrType_t dstAddr = { 0 };
  
  // Look for the first respondent
  if ( pRespondentCurr == NULL )
  {
    pRespondentCurr = bdb_getRespondentRetry(pRespondentHead);
    
    // If null, then no responses from Identify query request
    if ( (pRespondentCurr == NULL) )
    {
      //No responses, then no responses
      if(pRespondentHead == NULL)
      {
        bdb_exitFindingBindingWStatus( BDB_COMMISSIONING_FB_NO_IDENTIFY_QUERY_RESPONSE );
      }
      //Responses and binded to all clusters possible
      else
      {
        bdb_exitFindingBindingWStatus( BDB_COMMISSIONING_SUCCESS );
      }
      return;
    }
  }
  else
  {
    if(pRespondentNext == NULL)
    {
      //Review the whole list if we have simple desc that we need to attempt.
      pRespondentCurr = bdb_getRespondentRetry(pRespondentHead);
        
      if(pRespondentCurr == NULL)
      {
        bdb_exitFindingBindingWStatus( BDB_COMMISSIONING_SUCCESS );
        return;
      }
    }
    else
    {
      pRespondentCurr = pRespondentNext;
    }
  }
  
  //If ParentLost is reported, then do not attempt send SimpleDesc, mark those as pending, 
  //if Parent Lost is restored, then these simpleDesc attempts will be restored to 0
  if(bdbCommissioningProcedureState.bdbCommissioningState != BDB_PARENT_LOST)
  {
    dstAddr.addr.shortAddr = pRespondentCurr->data.addr.shortAddr;
    dstAddr.addrMode = pRespondentCurr->data.addrMode;
    
    ZDP_SimpleDescReq( &dstAddr, pRespondentCurr->data.addr.shortAddr, pRespondentCurr->data.endPoint, 0 );
    
    //Update the attempts
    pRespondentCurr->attempts++;
  }
  else
  {
    pRespondentCurr->attempts = BDB_SIMPLE_DESC_PENDING_PARENT_LOST;
  }
  
  
  //Search for the next respondant that has not enough tries in the list
  pRespondentNext = bdb_getRespondentRetry(pRespondentCurr->pNext);
  
  osal_start_timerEx( bdb_TaskID, BDB_RESPONDENT_SIMPLEDESC_TIMEOUT, SIMPLEDESC_RESPONSE_TIMEOUT );
  
}

/*********************************************************************
 * @fn      bdb_FindIfAppCluster
 *
 * @brief   To verify if cluster is application type
 *
 * @param   none
 *
 * @return  true if success
 */
uint8 bdb_FindIfAppCluster( cId_t ClusterId )
{
  uint8 i;
  uint8 ClusterCnt;

  ClusterCnt = sizeof( bdb_ZclType1Clusters )/sizeof( uint16 );
  
  for ( i = 0; i < ClusterCnt; i++ )
  {
    if ( bdb_ZclType1Clusters[i] == ClusterId )
    {
      return ( SUCCESS );
    }
  }
  
  ClusterCnt = sizeof( bdb_ZclType2Clusters )/sizeof( uint16 );
  
  for ( i = 0; i < ClusterCnt; i++ )
  {
    if ( bdb_ZclType2Clusters[i] == ClusterId )
    {
      return ( SUCCESS );
    }
  }
  
  // If not found, take it as application cluster it will be filtered
  // by simple descriptor at some point
  return ( FAILURE );
}


/*********************************************************************
 * @fn      bdb_getRespondentRetry
 *
 * @brief   Get the next Respondant entry to retry
 *
 * @param   pHead - pointer to a pointer of the list head
 *
 * @return  respondant entry if found, otherwise NULL
 */
bdbFindingBindingRespondent_t* bdb_getRespondentRetry(bdbFindingBindingRespondent_t* pRespondentHead)
{
  bdbFindingBindingRespondent_t *pTemp;
  
  pTemp = pRespondentHead;
  
  while(pTemp != NULL)
  {
    if(pTemp->attempts < FINDING_AND_BINDING_MAX_ATTEMPTS)
    {
      return pTemp;
    }
    pTemp = pTemp->pNext;
  }
  return NULL;
}


bdbFindingBindingRespondent_t* bdb_findRespondentNode(uint8 endpoint, uint16 shortAddress)
{
  bdbFindingBindingRespondent_t* pTemp = pRespondentHead;
  
  while(pTemp != NULL)  
  {
    if((pTemp->data.addr.shortAddr == shortAddress) && (pTemp->data.endPoint == endpoint))
    {
      return pTemp;
    }
    
    pTemp = pTemp->pNext;
  }
  
  return NULL;
}

#endif  

/*********************************************************************
*********************************************************************/
