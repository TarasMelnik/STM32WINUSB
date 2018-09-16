/**
  ******************************************************************************
  * @file           : usbd_desc.c
  * @version        : v2.0_Cube
  * @brief          : This file implements the USB device descriptors.
  ******************************************************************************
  * This notice applies to any and all portions of this file
  * that are not between comment pairs USER CODE BEGIN and
  * USER CODE END. Other portions of this file, whether 
  * inserted by the user or by software development tools
  * are owned by their respective copyright owners.
  *
  * Copyright (c) 2018 STMicroelectronics International N.V. 
  * All rights reserved.
  *
  * Redistribution and use in source and binary forms, with or without 
  * modification, are permitted, provided that the following conditions are met:
  *
  * 1. Redistribution of source code must retain the above copyright notice, 
  *    this list of conditions and the following disclaimer.
  * 2. Redistributions in binary form must reproduce the above copyright notice,
  *    this list of conditions and the following disclaimer in the documentation
  *    and/or other materials provided with the distribution.
  * 3. Neither the name of STMicroelectronics nor the names of other 
  *    contributors to this software may be used to endorse or promote products 
  *    derived from this software without specific written permission.
  * 4. This software, including modifications and/or derivative works of this 
  *    software, must execute solely and exclusively on microcontroller or
  *    microprocessor devices manufactured by or for STMicroelectronics.
  * 5. Redistribution and use of this software other than as permitted under 
  *    this license is void and will automatically terminate your rights under 
  *    this license. 
  *
  * THIS SOFTWARE IS PROVIDED BY STMICROELECTRONICS AND CONTRIBUTORS "AS IS" 
  * AND ANY EXPRESS, IMPLIED OR STATUTORY WARRANTIES, INCLUDING, BUT NOT 
  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A 
  * PARTICULAR PURPOSE AND NON-INFRINGEMENT OF THIRD PARTY INTELLECTUAL PROPERTY
  * RIGHTS ARE DISCLAIMED TO THE FULLEST EXTENT PERMITTED BY LAW. IN NO EVENT 
  * SHALL STMICROELECTRONICS OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
  * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, 
  * OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF 
  * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING 
  * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
  * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "usbd_conf.h"
#include "usbd_core.h"
#include "usbd_desc.h"
#include "usbd_conf.h"

/* USER CODE BEGIN INCLUDE */

/* USER CODE END INCLUDE */

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/

/* USER CODE BEGIN PV */
/* Private variables ---------------------------------------------------------*/

/* USER CODE END PV */

/** @addtogroup STM32_USB_OTG_DEVICE_LIBRARY
  * @{
  */

/** @addtogroup USBD_DESC
  * @{
  */

/** @defgroup USBD_DESC_Private_TypesDefinitions USBD_DESC_Private_TypesDefinitions
  * @brief Private types.
  * @{
  */

/* USER CODE BEGIN PRIVATE_TYPES */

/* USER CODE END PRIVATE_TYPES */

/**
  * @}
  */

/** @defgroup USBD_DESC_Private_Defines USBD_DESC_Private_Defines
  * @brief Private defines.
  * @{
  */

#define USBD_VID     0x4701
#define USBD_LANGID_STRING     1033
#define USBD_MANUFACTURER_STRING     "STMicroelectronics"
#define USBD_PID_FS     0x290
#define USBD_PRODUCT_STRING_FS     "STM32 WINUSB"
#define USBD_SERIALNUMBER_STRING_FS     "00000000001A"
#define USBD_CONFIGURATION_STRING_FS     "WINUSB Config"
#define USBD_INTERFACE_STRING_FS     "WINUSB Interface"

/* USER CODE BEGIN PRIVATE_DEFINES */

/* USER CODE END PRIVATE_DEFINES */

/**
  * @}
  */

/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/** @defgroup USBD_DESC_Private_Macros USBD_DESC_Private_Macros
  * @brief Private macros.
  * @{
  */

/* USER CODE BEGIN PRIVATE_MACRO */

/* USER CODE END PRIVATE_MACRO */

/**
  * @}
  */

/** @defgroup USBD_DESC_Private_FunctionPrototypes USBD_DESC_Private_FunctionPrototypes
  * @brief Private functions declaration.
  * @{
  */

uint8_t * USBD_FS_DeviceDescriptor(USBD_SpeedTypeDef speed, uint16_t *length);
uint8_t * USBD_FS_LangIDStrDescriptor(USBD_SpeedTypeDef speed, uint16_t *length);
uint8_t * USBD_FS_ManufacturerStrDescriptor(USBD_SpeedTypeDef speed, uint16_t *length);
uint8_t * USBD_FS_ProductStrDescriptor(USBD_SpeedTypeDef speed, uint16_t *length);
uint8_t * USBD_FS_SerialStrDescriptor(USBD_SpeedTypeDef speed, uint16_t *length);
uint8_t * USBD_FS_ConfigStrDescriptor(USBD_SpeedTypeDef speed, uint16_t *length);
uint8_t * USBD_FS_InterfaceStrDescriptor(USBD_SpeedTypeDef speed, uint16_t *length);

#ifdef USB_SUPPORT_USER_STRING_DESC
uint8_t * USBD_FS_USRStringDesc(USBD_SpeedTypeDef speed, uint8_t idx, uint16_t *length);
#endif /* USB_SUPPORT_USER_STRING_DESC */

#if (USBD_SUPPORT_WINUSB==1)
uint8_t *USBD_WinUSBOSStrDescriptor(uint16_t *length);
uint8_t *USBD_WinUSBOSFeatureDescriptor(uint16_t *length);
uint8_t *USBD_WinUSBOSPropertyDescriptor(uint16_t *length);
#endif // (USBD_SUPPORT_WINUSB==1)

/**
  * @}
  */

/** @defgroup USBD_DESC_Private_Variables USBD_DESC_Private_Variables
  * @brief Private variables.
  * @{
  */

USBD_DescriptorsTypeDef FS_Desc =
{
  USBD_FS_DeviceDescriptor
, USBD_FS_LangIDStrDescriptor
, USBD_FS_ManufacturerStrDescriptor
, USBD_FS_ProductStrDescriptor
, USBD_FS_SerialStrDescriptor
, USBD_FS_ConfigStrDescriptor
, USBD_FS_InterfaceStrDescriptor
#if (USBD_SUPPORT_WINUSB == 1) 
, USBD_WinUSBOSFeatureDescriptor
, USBD_WinUSBOSPropertyDescriptor
#endif // (USBD_SUPPORT_WINUSB==1)
   
};

#if defined ( __ICCARM__ ) /* IAR Compiler */
  #pragma data_alignment=4
#endif /* defined ( __ICCARM__ ) */
/** USB standard device descriptor. */
__ALIGN_BEGIN uint8_t USBD_FS_DeviceDesc[USB_LEN_DEV_DESC] __ALIGN_END =
{
  0x12,                       /*bLength */
  USB_DESC_TYPE_DEVICE,       /*bDescriptorType*/
  0x00,                       /*bcdUSB */
  0x02,
  0x00,                       /*bDeviceClass*/
  0x00,                       /*bDeviceSubClass*/
  0x00,                       /*bDeviceProtocol*/
  USB_MAX_EP0_SIZE,           /*bMaxPacketSize*/
  LOBYTE(USBD_VID),           /*idVendor*/
  HIBYTE(USBD_VID),           /*idVendor*/
  LOBYTE(USBD_PID_FS),        /*idProduct*/
  HIBYTE(USBD_PID_FS),        /*idProduct*/
  0x10,                       /*bcdDevice rel. 0.10*/
  0x00,
  USBD_IDX_MFC_STR,           /*Index of manufacturer  string*/
  USBD_IDX_PRODUCT_STR,       /*Index of product string*/
  USBD_IDX_SERIAL_STR,        /*Index of serial number string*/
  USBD_MAX_NUM_CONFIGURATION  /*bNumConfigurations*/
};

/* USB_DeviceDescriptor */

#define USB_LEN_OS_FEATURE_DESC 0x28
#if defined ( __ICCARM__ ) /* IAR Compiler */
  #pragma data_alignment=4
#endif /* defined ( __ICCARM__ ) */

__ALIGN_BEGIN uint8_t USBD_WINUSB_OSFeatureDesc[USB_LEN_OS_FEATURE_DESC] __ALIGN_END =
{
   0x28, 0, 0, 0, // length
   0, 1,          // bcd version 1.0
   4, 0,          // windex: extended compat ID descritor
   1,             // no of function
   0, 0, 0, 0, 0, 0, 0, // reserve 7 bytes
// function
   0,             // interface no
   0,             // reserved
   'W', 'I', 'N', 'U', 'S', 'B', 0, 0, //  first ID
     0,   0,   0,   0,   0,   0, 0, 0,  // second ID
     0,   0,   0,   0,   0,   0 // reserved 6 bytes      
};
#define USB_LEN_OS_PROPERTY_DESC 0x8E
#if defined ( __ICCARM__ ) /* IAR Compiler */
  #pragma data_alignment=4
#endif /* defined ( __ICCARM__ ) */
__ALIGN_BEGIN uint8_t USBD_WINUSB_OSPropertyDesc[USB_LEN_OS_PROPERTY_DESC] __ALIGN_END =
{
      0x8E, 0, 0, 0,  // length 246 byte
      0x00, 0x01,   // BCD version 1.0
      0x05, 0x00,   // Extended Property Descriptor Index(5)
      0x01, 0x00,   // number of section (1)
//; property section        
      0x84, 0x00, 0x00, 0x00,   // size of property section
      0x1, 0, 0, 0,   //; property data type (1)
      0x28, 0,        //; property name length (42)
      'D', 0,
      'e', 0,
      'v', 0,
      'i', 0,
      'c', 0,
      'e', 0,
      'I', 0,
      'n', 0,
      't', 0,
      'e', 0,
      'r', 0,
      'f', 0,
      'a', 0,
      'c', 0,
      'e', 0,
      'G', 0,
      'U', 0,
      'I', 0,
      'D', 0,
      0, 0,
      // D6805E56-0447-4049-9848-46D6B2AC5D28
      0x4E, 0, 0, 0,  // ; property data length
      '{', 0,
      '1', 0,
      '3', 0,
      'E', 0,
      'B', 0,
      '3', 0,
      '6', 0,
      '0', 0,
      'B', 0,
      '-', 0,
      'B', 0,
      'C', 0,
      '1', 0,
      'E', 0,
      '-', 0,
      '4', 0,
      '6', 0,
      'C', 0,
      'B', 0,
      '-', 0,
      'A', 0,
      'C', 0,
      '8', 0,
      'B', 0,
      '-', 0,
      'E', 0,
      'F', 0,
      '3', 0,
      'D', 0,
      'A', 0,
      '4', 0,
      '7', 0,
      'B', 0,
      '4', 0,
      '0', 0,
      '6', 0,
      '2', 0,
      '}', 0,
      0, 0,
      
};

/**
  * @}
  */

/** @defgroup USBD_DESC_Private_Variables USBD_DESC_Private_Variables
  * @brief Private variables.
  * @{
  */

#if defined ( __ICCARM__ ) /* IAR Compiler */
  #pragma data_alignment=4
#endif /* defined ( __ICCARM__ ) */

/** USB lang indentifier descriptor. */
__ALIGN_BEGIN uint8_t USBD_LangIDDesc[USB_LEN_LANGID_STR_DESC] __ALIGN_END =
{
     USB_LEN_LANGID_STR_DESC,
     USB_DESC_TYPE_STRING,
     LOBYTE(USBD_LANGID_STRING),
     HIBYTE(USBD_LANGID_STRING)
};

#if defined ( __ICCARM__ ) /* IAR Compiler */
  #pragma data_alignment=4
#endif /* defined ( __ICCARM__ ) */
/* Internal string descriptor. */
__ALIGN_BEGIN uint8_t USBD_StrDesc[USBD_MAX_STR_DESC_SIZ] __ALIGN_END;

/**
  * @}
  */

/** @defgroup USBD_DESC_Private_Functions USBD_DESC_Private_Functions
  * @brief Private functions.
  * @{
  */

/**
  * @brief  Return the device descriptor
  * @param  speed : Current device speed
  * @param  length : Pointer to data length variable
  * @retval Pointer to descriptor buffer
  */
uint8_t * USBD_FS_DeviceDescriptor(USBD_SpeedTypeDef speed, uint16_t *length)
{
  *length = sizeof(USBD_FS_DeviceDesc);
  return USBD_FS_DeviceDesc;
}

/**
  * @brief  Return the LangID string descriptor
  * @param  speed : Current device speed
  * @param  length : Pointer to data length variable
  * @retval Pointer to descriptor buffer
  */
uint8_t * USBD_FS_LangIDStrDescriptor(USBD_SpeedTypeDef speed, uint16_t *length)
{
  *length = sizeof(USBD_LangIDDesc);
  return USBD_LangIDDesc;
}

/**
  * @brief  Return the product string descriptor
  * @param  speed : Current device speed
  * @param  length : Pointer to data length variable
  * @retval Pointer to descriptor buffer
  */
uint8_t * USBD_FS_ProductStrDescriptor(USBD_SpeedTypeDef speed, uint16_t *length)
{
  if(speed == 0)
  {
    USBD_GetString((uint8_t *)USBD_PRODUCT_STRING_FS, USBD_StrDesc, length);
  }
  else
  {
    USBD_GetString((uint8_t *)USBD_PRODUCT_STRING_FS, USBD_StrDesc, length);
  }
  return USBD_StrDesc;
}

/**
  * @brief  Return the manufacturer string descriptor
  * @param  speed : Current device speed
  * @param  length : Pointer to data length variable
  * @retval Pointer to descriptor buffer
  */
uint8_t * USBD_FS_ManufacturerStrDescriptor(USBD_SpeedTypeDef speed, uint16_t *length)
{
  USBD_GetString((uint8_t *)USBD_MANUFACTURER_STRING, USBD_StrDesc, length);
  return USBD_StrDesc;
}

/**
  * @brief  Return the serial number string descriptor
  * @param  speed : Current device speed
  * @param  length : Pointer to data length variable
  * @retval Pointer to descriptor buffer
  */
uint8_t * USBD_FS_SerialStrDescriptor(USBD_SpeedTypeDef speed, uint16_t *length)
{
  if(speed == USBD_SPEED_HIGH)
  {
    USBD_GetString((uint8_t *)USBD_SERIALNUMBER_STRING_FS, USBD_StrDesc, length);
  }
  else
  {
    USBD_GetString((uint8_t *)USBD_SERIALNUMBER_STRING_FS, USBD_StrDesc, length);
  }
  return USBD_StrDesc;
}

/**
  * @brief  Return the configuration string descriptor
  * @param  speed : Current device speed
  * @param  length : Pointer to data length variable
  * @retval Pointer to descriptor buffer
  */
uint8_t * USBD_FS_ConfigStrDescriptor(USBD_SpeedTypeDef speed, uint16_t *length)
{
  if(speed == USBD_SPEED_HIGH)
  {
    USBD_GetString((uint8_t *)USBD_CONFIGURATION_STRING_FS, USBD_StrDesc, length);
  }
  else
  {
    USBD_GetString((uint8_t *)USBD_CONFIGURATION_STRING_FS, USBD_StrDesc, length);
  }
  return USBD_StrDesc;
}

/**
  * @brief  Return the interface string descriptor
  * @param  speed : Current device speed
  * @param  length : Pointer to data length variable
  * @retval Pointer to descriptor buffer
  */
uint8_t * USBD_FS_InterfaceStrDescriptor(USBD_SpeedTypeDef speed, uint16_t *length)
{
  if(speed == 0)
  {
    USBD_GetString((uint8_t *)USBD_INTERFACE_STRING_FS, USBD_StrDesc, length);
  }
  else
  {
    USBD_GetString((uint8_t *)USBD_INTERFACE_STRING_FS, USBD_StrDesc, length);
  }
  return USBD_StrDesc;
}

#if (USBD_SUPPORT_WINUSB==1)
const uint8_t USBD_OS_STRING[8] = { 
   'M',
   'S',
   'F',
   'T',
   '1',
   '0',
   '0',
   USB_REQ_MS_VENDOR_CODE, 
}; 
uint8_t *USBD_WinUSBOSStrDescriptor(uint16_t *length)
{
   USBD_GetString((uint8_t *)USBD_OS_STRING, USBD_StrDesc, length);
   return USBD_StrDesc;
}
uint8_t *USBD_WinUSBOSFeatureDescriptor(uint16_t *length)
{
  *length = USB_LEN_OS_FEATURE_DESC;
  return USBD_WINUSB_OSFeatureDesc;
}
uint8_t *USBD_WinUSBOSPropertyDescriptor(uint16_t *length)
{
  *length = USB_LEN_OS_PROPERTY_DESC;
   return USBD_WINUSB_OSPropertyDesc;
}
#endif // (USBD_SUPPORT_WINUSB==1)
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