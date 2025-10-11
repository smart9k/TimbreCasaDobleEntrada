/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2025 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define DO_PC13_LED_Pin GPIO_PIN_13
#define DO_PC13_LED_GPIO_Port GPIOC
#define DI_SWITCH_DOOR_Pin GPIO_PIN_0
#define DI_SWITCH_DOOR_GPIO_Port GPIOA
#define DI_ENABLE_INTERCOM_Pin GPIO_PIN_1
#define DI_ENABLE_INTERCOM_GPIO_Port GPIOA
#define DI_SWITCH_INTERCOM_Pin GPIO_PIN_2
#define DI_SWITCH_INTERCOM_GPIO_Port GPIOA
#define DO_RGB_R__DOOR_DETECTED_Pin GPIO_PIN_2
#define DO_RGB_R__DOOR_DETECTED_GPIO_Port GPIOB
#define DO_RGB_G__INTERCOM_DETECTED_Pin GPIO_PIN_10
#define DO_RGB_G__INTERCOM_DETECTED_GPIO_Port GPIOB
#define DO_BUZZER_Pin GPIO_PIN_12
#define DO_BUZZER_GPIO_Port GPIOB
#define DO_SW_TEST_01_Pin GPIO_PIN_14
#define DO_SW_TEST_01_GPIO_Port GPIOB
#define DO_SW_TEST_02_Pin GPIO_PIN_15
#define DO_SW_TEST_02_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
