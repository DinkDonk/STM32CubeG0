/**
  ******************************************************************************
  * @file    optionbytes_interface.h
  * @author  MCD Application Team
  * @brief   Header for optionbytes_interface.c module
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2020 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef OPTIONBYTES_INTERFACE_H
#define OPTIONBYTES_INTERFACE_H

/* Includes ------------------------------------------------------------------*/
/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
/* Exported macro ------------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */
uint8_t OPENBL_OB_Read(uint32_t Address);
void OPENBL_OB_Write(uint32_t Address, uint8_t *Data, uint32_t DataLength);

#endif /* OPTIONBYTES_INTERFACE_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
