/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    usbpd_pwr_if.c
  * @author  MCD Application Team
  * @brief   This file contains power interface control functions.
  ******************************************************************************
  *
  * Copyright (c) 2018 STMicroelectronics. All rights reserved.
  *
  * This software component is licensed by ST under Ultimate Liberty license
  * SLA0044, the "License"; You may not use this file except in compliance with
  * the License. You may obtain a copy of the License at:
  *                               www.st.com/SLA0044
  *
  ******************************************************************************
  */
/* USER CODE END Header */

#define __USBPD_PWR_IF_C

/* Includes ------------------------------------------------------------------*/
#include "usbpd_pwr_if.h"
#include "usbpd_hw_if.h"
#include "usbpd_dpm_core.h"
#include "usbpd_dpm_conf.h"
#include "usbpd_pdo_defs.h"
#include "usbpd_core.h"
#if defined(_TRACE)
#include "usbpd_trace.h"
#endif /* _TRACE */
#include "string.h"
/* USER CODE BEGIN Include */
#include "string.h"
/* USER CODE END Include */

/** @addtogroup STM32_USBPD_APPLICATION
  * @{
  */

/** @addtogroup STM32_USBPD_APPLICATION_POWER_IF
  * @{
  */

/* Private typedef -----------------------------------------------------------*/
/** @addtogroup STM32_USBPD_APPLICATION_POWER_IF_Private_TypeDef
  * @{
  */
/* USER CODE BEGIN Private_Typedef */

/* USER CODE END Private_Typedef */
/**
  * @}
  */

/* Private define ------------------------------------------------------------*/
/** @addtogroup STM32_USBPD_APPLICATION_POWER_IF_Private_Defines
  * @{
  */
/* USER CODE BEGIN Private_Define */

/* USER CODE END Private_Define */
/**
  * @}
  */

/* Private macros ------------------------------------------------------------*/
/** @addtogroup STM32_USBPD_APPLICATION_POWER_IF_Private_Macros
  * @{
  */
#if defined(_TRACE)
#define PWR_IF_DEBUG_TRACE(_PORT_, __MESSAGE__)  USBPD_TRACE_Add(USBPD_TRACE_DEBUG, (_PORT_), 0u, (uint8_t*)(__MESSAGE__), sizeof(__MESSAGE__) - 1u)
#else
#define PWR_IF_DEBUG_TRACE(_PORT_, __MESSAGE__)
#endif /* _TRACE */
/* USER CODE BEGIN Private_Macro */

/* USER CODE END Private_Macro */
/**
  * @}
  */

/* Private variables ---------------------------------------------------------*/
/** @addtogroup STM32_USBPD_APPLICATION_POWER_IF_Private_Variables
  * @{
  */
/* USER CODE BEGIN Private_Variables */

/* USER CODE END Private_Variables */
/**
  * @}
  */

/* Private function prototypes -----------------------------------------------*/
/** @addtogroup STM32_USBPD_APPLICATION_POWER_IF_Private_Functions
  * @{
  */
/* USER CODE BEGIN USBPD_USER_PRIVATE_FUNCTIONS_Prototypes */

/* Functions to initialize Source PDOs */
uint32_t _PWR_SRCFixedPDO(float  _C_, float _V_,
                          USBPD_CORE_PDO_PeakCurr_TypeDef _PK_,
                          USBPD_CORE_PDO_DRDataSupport_TypeDef DRDSupport,
                          USBPD_CORE_PDO_USBCommCapable_TypeDef UsbCommCapable,
                          USBPD_CORE_PDO_ExtPowered_TypeDef ExtPower,
                          USBPD_CORE_PDO_USBSuspendSupport_TypeDef UsbSuspendSupport,
                          USBPD_CORE_PDO_DRPowerSupport_TypeDef DRPSupport);

uint32_t _PWR_SRCVariablePDO(float _MAXV_, float _MINV_, float _C_);

uint32_t _PWR_SRCBatteryPDO(float _MAXV_,float _MINV_,float _PWR_);
/* Functions to initialize Sink PDOs */

uint32_t _PWR_SNKFixedPDO(float  _C_, float _V_,
                          USBPD_CORE_PDO_DRDataSupport_TypeDef DRDSupport,
                          USBPD_CORE_PDO_USBCommCapable_TypeDef UsbCommCapable,
                          USBPD_CORE_PDO_ExtPowered_TypeDef ExtPower,
                          USBPD_CORE_PDO_HigherCapability_TypeDef HigherCapab,
                          USBPD_CORE_PDO_DRPowerSupport_TypeDef DRPSupport);

uint32_t _PWR_SNKVariablePDO(float  _MAXV_,float _MINV_,float _C_);

uint32_t _PWR_SNKBatteryPDO(float _MAXV_,float _MINV_,float _PWR_);

/* USER CODE END USBPD_USER_PRIVATE_FUNCTIONS_Prototypes */
/**
  * @}
  */

/** @addtogroup STM32_USBPD_APPLICATION_POWER_IF_Exported_Functions
  * @{
  */

/**
  * @brief  Initialize structures and variables related to power board profiles
  *         used by Sink and Source, for all available ports.
  * @retval USBPD status
  */
USBPD_StatusTypeDef USBPD_PWR_IF_Init(void)
{
/* USER CODE BEGIN USBPD_PWR_IF_Init */
  return USBPD_ERROR;
/* USER CODE END USBPD_PWR_IF_Init */
}

/**
  * @brief  Sets the required power profile, now it works only with Fixed ones
  * @param  PortNum Port number
  * @retval USBPD status
*/
USBPD_StatusTypeDef USBPD_PWR_IF_SetProfile(uint8_t PortNum)
{
/* USER CODE BEGIN USBPD_PWR_IF_SetProfile */
  USBPD_StatusTypeDef      _ret = USBPD_ERROR;
  USBPD_PDO_TypeDef        _pdo;
  USBPD_SNKRDO_TypeDef     _rdo;

  _rdo.d32 = DPM_Ports[PortNum].DPM_RcvRequestDOMsg;
  if (0 == PortNum)
    _pdo.d32 = PORT0_PDO_ListSRC[0];
  else
    _pdo.d32 = PORT0_PDO_ListSRC[0];

  if(PWR_OK == BSP_USBPD_PWR_VBUSSetVoltage_Fixed(PortNum, _pdo.SRCFixedPDO.VoltageIn50mVunits * 50,
                                                     (_rdo.FixedVariableRDO.OperatingCurrentIn10mAunits * 10),
                                                     (_rdo.FixedVariableRDO.MaxOperatingCurrent10mAunits * 10)))
  {
     _ret = USBPD_OK;
  }

  return _ret;
/* USER CODE END USBPD_PWR_IF_SetProfile */
}

/**
  * @brief  Checks if the power on a specified port is ready
  * @param  PortNum Port number
  * @param  Vsafe   Vsafe status based on @ref USBPD_VSAFE_StatusTypeDef
  * @retval USBPD status
  */
USBPD_StatusTypeDef USBPD_PWR_IF_SupplyReady(uint8_t PortNum, USBPD_VSAFE_StatusTypeDef Vsafe)
{
/* USER CODE BEGIN USBPD_PWR_IF_SupplyReady */
  return USBPD_ERROR;
/* USER CODE END USBPD_PWR_IF_SupplyReady */
}

/**
  * @brief  Enables VBUS power on a specified port
  * @param  PortNum Port number
  * @retval USBPD status
  */
USBPD_StatusTypeDef USBPD_PWR_IF_VBUSEnable(uint8_t PortNum)
{
/* USER CODE BEGIN USBPD_PWR_IF_VBUSEnable */
  USBPD_StatusTypeDef _status = (USBPD_StatusTypeDef)HW_IF_PWR_Enable(PortNum, USBPD_ENABLE, CCNONE, USBPD_FALSE, USBPD_PORTPOWERROLE_SRC);
  return _status;
/* USER CODE END USBPD_PWR_IF_VBUSEnable */
}

/**
  * @brief  Disable VBUS/VCONN the power on a specified port
  * @param  PortNum Port number
  * @retval USBPD status
  */
USBPD_StatusTypeDef USBPD_PWR_IF_VBUSDisable(uint8_t PortNum)
{
/* USER CODE BEGIN USBPD_PWR_IF_VBUSDisable */
  USBPD_StatusTypeDef _status = (USBPD_StatusTypeDef)HW_IF_PWR_Enable(PortNum, USBPD_DISABLE, CCNONE, USBPD_FALSE, USBPD_PORTPOWERROLE_SRC);
  return _status;
/* USER CODE END USBPD_PWR_IF_VBUSDisable */
}

/**
  * @brief  Checks if the power on a specified port is enabled
  * @param  PortNum Port number
  * @retval USBPD_ENABLE or USBPD_DISABLE
  */
USBPD_FunctionalState USBPD_PWR_IF_VBUSIsEnabled(uint8_t PortNum)
{
  /* Get the Status of the port */
  return USBPD_PORT_IsValid(PortNum) ? (USBPD_FunctionalState)HW_IF_PWR_VBUSIsEnabled(PortNum) : USBPD_DISABLE;
}

/**
  * @brief  Reads the voltage and the current on a specified port
  * @param  PortNum Port number
  * @param  pVoltage: The Voltage in mV
  * @param  pCurrent: The Current in mA
  * @retval USBPD_ERROR or USBPD_OK
  */
USBPD_StatusTypeDef USBPD_PWR_IF_ReadVA(uint8_t PortNum, uint16_t *pVoltage, uint16_t *pCurrent)
{
/* USER CODE BEGIN USBPD_PWR_IF_ReadVA */
  return USBPD_ERROR;
/* USER CODE END USBPD_PWR_IF_ReadVA */
}

/**
  * @brief  Enables the VConn on the port.
  * @param  PortNum Port number
  * @param  CC      Specifies the CCx to be selected based on @ref CCxPin_TypeDef structure
  * @retval USBPD status
  */
USBPD_StatusTypeDef USBPD_PWR_IF_Enable_VConn(uint8_t PortNum, CCxPin_TypeDef CC)
{
/* USER CODE BEGIN USBPD_PWR_IF_Enable_VConn */
  return USBPD_ERROR;
/* USER CODE END USBPD_PWR_IF_Enable_VConn */
}

/**
  * @brief  Disable the VConn on the port.
  * @param  PortNum Port number
  * @param  CC      Specifies the CCx to be selected based on @ref CCxPin_TypeDef structure
  * @retval USBPD status
  */
USBPD_StatusTypeDef USBPD_PWR_IF_Disable_VConn(uint8_t PortNum, CCxPin_TypeDef CC)
{
/* USER CODE BEGIN USBPD_PWR_IF_Disable_VConn */
  return USBPD_ERROR;
/* USER CODE END USBPD_PWR_IF_Disable_VConn */
}

/**
  * @brief  Allow PDO data reading from PWR_IF storage.
  * @param  PortNum Port number
  * @param  DataId Type of data to be read from PWR_IF
  *         This parameter can be one of the following values:
  *           @arg @ref USBPD_CORE_DATATYPE_SRC_PDO Source PDO reading requested
  *           @arg @ref USBPD_CORE_DATATYPE_SNK_PDO Sink PDO reading requested
  * @param  Ptr Pointer on address where PDO values should be written (u8 pointer)
  * @param  Size Pointer on nb of u32 written by PWR_IF (nb of PDOs)
  * @retval None
  */
void USBPD_PWR_IF_GetPortPDOs(uint8_t PortNum, USBPD_CORE_DataInfoType_TypeDef DataId, uint8_t *Ptr, uint32_t *Size)
{
    if (DataId == USBPD_CORE_DATATYPE_SRC_PDO)
    {
      *Size = PORT0_NB_SOURCEPDO;
      memcpy(Ptr,PORT0_PDO_ListSRC, sizeof(uint32_t) * PORT0_NB_SOURCEPDO);
    }
/* USER CODE BEGIN USBPD_PWR_IF_GetPortPDOs */
  *Size = 0;
  switch(DataId)
  {
  case USBPD_CORE_DATATYPE_SRC_PDO :
    {
      memcpy(Ptr,(uint8_t*)&PORT0_PDO_ListSRC[0],sizeof(uint32_t));
      *Size = 1;
    }
    break;
  default :
    break;
  }
/* USER CODE END USBPD_PWR_IF_GetPortPDOs */
}

/**
  * @brief  Find out SRC PDO pointed out by a position provided in a Request DO (from Sink).
  * @param  PortNum Port number
  * @param  RdoPosition RDO Position in list of provided PDO
  * @param  Pdo Pointer on PDO value pointed out by RDO position (u32 pointer)
  * @retval Status of search
  *         USBPD_OK : Src PDO found for requested DO position (output Pdo parameter is set)
  *         USBPD_FAIL : Position is not compliant with current Src PDO for this port (no corresponding PDO value)
  */
USBPD_StatusTypeDef USBPD_PWR_IF_SearchRequestedPDO(uint8_t PortNum, uint32_t RdoPosition, uint32_t *Pdo)
{
/* USER CODE BEGIN USBPD_PWR_IF_SearchRequestedPDO */
  if(1 == RdoPosition)
  {
    *Pdo = PORT0_PDO_ListSRC[0];

    return USBPD_OK;
  }

  return USBPD_FAIL;
/* USER CODE END USBPD_PWR_IF_SearchRequestedPDO */
}

/**
  * @brief  Function called in case of critical issue is detected to switch in safety mode.
  * @param  ErrorType Type of error detected by monitoring (based on @ref USBPD_PWR_IF_ERROR)
  * @retval None
  */
void USBPD_PWR_IF_AlarmType(USBPD_PWR_IF_ERROR ErrorType)
{
/* USER CODE BEGIN USBPD_PWR_IF_AlarmType */

/* USER CODE END USBPD_PWR_IF_AlarmType */
}

/**
  * @brief  the function is called in case of critical issue is detected to switch in safety mode.
  * @retval None
  */
void USBPD_PWR_IF_Alarm()
{
/* USER CODE BEGIN USBPD_PWR_IF_Alarm */

/* USER CODE END USBPD_PWR_IF_Alarm */
}

/**
  * @brief Function is called to get VBUS power status.
  * @param PortNum Port number
  * @param PowerTypeStatus  Power type status based on @ref USBPD_VBUSPOWER_STATUS
  * @retval UBBPD_TRUE or USBPD_FALSE
  */
uint8_t USBPD_PWR_IF_GetVBUSStatus(uint8_t PortNum, USBPD_VBUSPOWER_STATUS PowerTypeStatus)
{
/* USER CODE BEGIN USBPD_PWR_IF_GetVBUSStatus */
  uint8_t _status = USBPD_FALSE;
  uint32_t _vbus = HW_IF_PWR_GetVoltage(PortNum);

  switch(PowerTypeStatus)
  {
  case USBPD_PWR_BELOWVSAFE0V :
    if (_vbus < USBPD_PWR_LOW_VBUS_THRESHOLD) _status = USBPD_TRUE;
    break;
  case USBPD_PWR_VSAFE5V :
    if (_vbus >= USBPD_PWR_HIGH_VBUS_THRESHOLD) _status = USBPD_TRUE;
    break;
  case USBPD_PWR_SNKDETACH:
    if (_vbus < USBPD_PWR_HIGH_VBUS_THRESHOLD) _status = USBPD_TRUE;
    break;
  default :
    break;
  }
  return _status;
/* USER CODE END USBPD_PWR_IF_GetVBUSStatus */
}

/**
  * @brief Function is called to set the VBUS threshold when a request has been accepted.
  * @param PortNum Port number
  * @retval None
  */
void USBPD_PWR_IF_UpdateVbusThreshold(uint8_t PortNum)
{
/* USER CODE BEGIN USBPD_PWR_IF_UpdateVbusThreshold */
/* USER CODE END USBPD_PWR_IF_UpdateVbusThreshold */
}

/**
  * @brief Function is called to reset the VBUS threshold when there is a power reset.
  * @param PortNum Port number
  * @retval None
  */
void USBPD_PWR_IF_ResetVbusThreshold(uint8_t PortNum)
{
/* USER CODE BEGIN USBPD_PWR_IF_ResetVbusThreshold */
/* USER CODE END USBPD_PWR_IF_ResetVbusThreshold */
}

/* USER CODE BEGIN USBPD_USER_EXPORTED_FUNCTIONS_Definition */

/* USER CODE END USBPD_USER_EXPORTED_FUNCTIONS_Definition */
/**
  * @}
  */

/** @addtogroup STM32_USBPD_APPLICATION_POWER_IF_Private_Functions
  * @{
  */
/* USER CODE BEGIN USBPD_USER_PRIVATE_FUNCTIONS_Definition */

/* USER CODE END USBPD_USER_PRIVATE_FUNCTIONS_Definition */
/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
