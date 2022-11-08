/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2022 STMicroelectronics.
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
#include "stm32f1xx_hal.h"

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
#define BUTTON_1_Pin GPIO_PIN_13
#define BUTTON_1_GPIO_Port GPIOC
#define Select_Pin GPIO_PIN_2
#define Select_GPIO_Port GPIOA
#define Mod_Pin GPIO_PIN_3
#define Mod_GPIO_Port GPIOA
#define Set_Pin GPIO_PIN_4
#define Set_GPIO_Port GPIOA
#define RED_A_Pin GPIO_PIN_5
#define RED_A_GPIO_Port GPIOA
#define AMBER_A_Pin GPIO_PIN_6
#define AMBER_A_GPIO_Port GPIOA
#define GREEN_A_Pin GPIO_PIN_7
#define GREEN_A_GPIO_Port GPIOA
#define SegA_Pin GPIO_PIN_0
#define SegA_GPIO_Port GPIOB
#define SegB_Pin GPIO_PIN_1
#define SegB_GPIO_Port GPIOB
#define SegC_Pin GPIO_PIN_2
#define SegC_GPIO_Port GPIOB
#define SegDD_Pin GPIO_PIN_10
#define SegDD_GPIO_Port GPIOB
#define SegEE_Pin GPIO_PIN_11
#define SegEE_GPIO_Port GPIOB
#define SegFF_Pin GPIO_PIN_12
#define SegFF_GPIO_Port GPIOB
#define SegGG_Pin GPIO_PIN_13
#define SegGG_GPIO_Port GPIOB
#define RED_B_Pin GPIO_PIN_8
#define RED_B_GPIO_Port GPIOA
#define AMBER_B_Pin GPIO_PIN_9
#define AMBER_B_GPIO_Port GPIOA
#define GREEN_B_Pin GPIO_PIN_10
#define GREEN_B_GPIO_Port GPIOA
#define EN0_Pin GPIO_PIN_11
#define EN0_GPIO_Port GPIOA
#define EN1_Pin GPIO_PIN_12
#define EN1_GPIO_Port GPIOA
#define EN2_Pin GPIO_PIN_13
#define EN2_GPIO_Port GPIOA
#define EN3_Pin GPIO_PIN_14
#define EN3_GPIO_Port GPIOA
#define SegD_Pin GPIO_PIN_3
#define SegD_GPIO_Port GPIOB
#define SegE_Pin GPIO_PIN_4
#define SegE_GPIO_Port GPIOB
#define SegF_Pin GPIO_PIN_5
#define SegF_GPIO_Port GPIOB
#define SegG_Pin GPIO_PIN_6
#define SegG_GPIO_Port GPIOB
#define SegAA_Pin GPIO_PIN_7
#define SegAA_GPIO_Port GPIOB
#define SegBB_Pin GPIO_PIN_8
#define SegBB_GPIO_Port GPIOB
#define SegCC_Pin GPIO_PIN_9
#define SegCC_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
