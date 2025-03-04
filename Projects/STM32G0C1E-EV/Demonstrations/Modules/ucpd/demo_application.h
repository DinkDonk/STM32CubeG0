/**
  ******************************************************************************
  * @file    demo_application.h
  * @author  MCD Application Team
  * @brief   Header file for demo_application.h file
  ******************************************************************************
   * @attention
   *
   * Copyright (c) 2018-2020 STMicroelectronics.
   * All rights reserved.
   *
   * This software is licensed under terms that can be found in the LICENSE file
   * in the root directory of this software component.
   * If no LICENSE file comes with this software, it is provided AS-IS.
   *
   ******************************************************************************
   */

#ifndef __DEMO_APPLICATION_H_
#define __DEMO_APPLICATION_H_

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
/** @addtogroup STM32_USBPD_APPLICATION
  * @{
  */

/** @addtogroup STM32_USBPD_APPLICATION_DEMO
  * @{
  */

/* Exported typedef ----------------------------------------------------------*/
/* Exported define -----------------------------------------------------------*/
/*  MMI
     - 15-0 id event                       */
#define DEMO_MMI_ACTION_Pos                   (0U)
#define DEMO_MMI_ACTION_Msk                   (0xFFU << DEMO_MMI_ACTION_Pos) /*!< 0x00FF */
#define DEMO_MMI_ACTION                       DPM_USER_ACTION_Msk
#define DEMO_MMI_ACTION_NONE                  (0U)
#define DEMO_MMI_ACTION_TAMPER_PRESS          (1U << DEMO_MMI_ACTION_Pos)
#define DEMO_MMI_ACTION_RIGHT_PRESS           (2U << DEMO_MMI_ACTION_Pos)
#define DEMO_MMI_ACTION_LEFT_PRESS            (3U << DEMO_MMI_ACTION_Pos)
#define DEMO_MMI_ACTION_UP_PRESS              (4U << DEMO_MMI_ACTION_Pos)
#define DEMO_MMI_ACTION_DOWN_PRESS            (5U << DEMO_MMI_ACTION_Pos)
#define DEMO_MMI_ACTION_SEL_PRESS             (6U << DEMO_MMI_ACTION_Pos)
#define DEMO_MMI_ACTION_HPD_DETECT_HIGH_PORT1 (7U << DEMO_MMI_ACTION_Pos)
#define DEMO_MMI_ACTION_HPD_DETECT_LOW_PORT1  (8U << DEMO_MMI_ACTION_Pos)
#define DEMO_MMI_ACTION_DISPLAY_VBUS_IBUS     (9U << DEMO_MMI_ACTION_Pos)
#define DEMO_MMI_ACTION_JOY_PRESS             (10U << DEMO_MMI_ACTION_Pos)
#define DEMO_MMI_ACTION_HPD_DETECT_HIGH_PORT0 (11U << DEMO_MMI_ACTION_Pos)
#define DEMO_MMI_ACTION_HPD_DETECT_LOW_PORT0  (12U << DEMO_MMI_ACTION_Pos)
#define DEMO_MMI_ACTION_ERROR_POWER           (13U << DEMO_MMI_ACTION_Pos)
#define DEMO_MMI_ACTION_ERROR_SETTINGS        (14U << DEMO_MMI_ACTION_Pos)

/* Demo Error types */
#define DEMO_ERROR_TYPE_POWER                 (0U)    /* Power Supply error */
#define DEMO_ERROR_TYPE_FLASH_SETTINGS        (1U)    /* Error in settings stored in flash */
#define DEMO_ERROR_TYPE_POWER_NMI             (2U)    /* Alarm detected in NMI Handler */
#define DEMO_ERROR_TYPE_POWER_HARD_FAULT      (3U)    /* Alarm detected in Hard Fault Handler */
#define DEMO_ERROR_TYPE_POWER_OVER_CURRENT    (4U)    /* Over current detected in Power monitoring */
#define DEMO_ERROR_ACDC_ADAPTER_REMOVED       (5U)    /* 19V removed detected in Power monitoring */
#define DEMO_ERROR_TYPE_MAXNBITEMS            (DEMO_ERROR_ACDC_ADAPTER_REMOVED + 1U)

/* Exported constants --------------------------------------------------------*/
typedef enum{
     DEMO_OK,
     DEMO_ERROR
} DEMO_ErrorCode;

/* Exported macro ------------------------------------------------------------*/
/* Exported variables --------------------------------------------------------*/
/* Exported functions --------------------------------------------------------*/
DEMO_ErrorCode DEMO_InitBSP(void);
DEMO_ErrorCode DEMO_InitTask(void);
void DEMO_PostCADMessage(uint8_t PortNum, USBPD_CAD_EVENT State, CCxPin_TypeDef Cc);
void DEMO_PostNotificationMessage(uint8_t PortNum, USBPD_NotifyEventValue_TypeDef EventVal);
void DEMO_PostMMIMessage(uint32_t EventVal);
void DEMO_SetCableInfo(uint8_t PortNum, USBPD_DiscoveryIdentity_TypeDef *pIdentity);
void DEMO_Display_Error(uint8_t PortNum, uint8_t ErrorType);

void DEMO_ExtiRisingEdgeDetection(uint16_t GPIO_Pin);
void DEMO_ExtiFallingEdgeDetection(uint16_t GPIO_Pin);

/**
  * @}
  */

/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /* __DEMO_APPLICATION_H_ */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
