/*-----------------------------------------------------------------------------------------------*/
/* Includes                                                                                      */
/*-----------------------------------------------------------------------------------------------*/
#include "stm32f7xx_hal.h"

/*-----------------------------------------------------------------------------------------------*/
/* Defines                                                                                       */
/*-----------------------------------------------------------------------------------------------*/
#define LED_PIN            (GPIO_PIN_0)
#define LED_GPIO_PORT      (GPIOB)
#define LED_BLINK_DELAY_MS (200)

/*-----------------------------------------------------------------------------------------------*/
/* Public functions                                                                              */
/*-----------------------------------------------------------------------------------------------*/
/**
  * @brief Application entry point
  * @param None
  * @retval None
  */
int main(void) {
  GPIO_InitTypeDef gpioInit = {0};

  /* Setup Flash, Systick and NVIC */
  HAL_Init();

  /* Enable GPIO port B clock used for LED pin */
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /* Configure LED pin as output */
  gpioInit.Pin = LED_PIN;
  gpioInit.Mode = GPIO_MODE_OUTPUT_PP;
  gpioInit.Pull = GPIO_PULLUP;
  gpioInit.Speed = GPIO_SPEED_FREQ_HIGH;
  HAL_GPIO_Init(LED_GPIO_PORT, &gpioInit);

  while (1) {
    HAL_GPIO_TogglePin(LED_GPIO_PORT, LED_PIN);
    HAL_Delay(LED_BLINK_DELAY_MS);
  }
}

/**
  * @brief This function handles System tick timer
  * @param None
  * @retval None
  */
void SysTick_Handler(void) {
  HAL_IncTick();
}

/**
  * @brief This function handles Non maskable interrupts
  * @param None
  * @retval None
  */
void NMI_Handler(void) { }

/**
  * @brief This function handles System service call via SWI instruction
  * @param None
  * @retval None
  */
void SVC_Handler(void) { }

/**
  * @brief This function handles Debug monitor
  * @param None
  * @retval None
  */
void DebugMon_Handler(void) { }

/**
  * @brief This function handles Pendable request for system service
  * @param None
  * @retval None
  */
void PendSV_Handler(void) { }

/**
  * @brief This function handles Hard fault interrupt
  * @param None
  * @retval None
  */
void HardFault_Handler(void) { while (1); }

/**
  * @brief This function handles Memory management fault
  * @param None
  * @retval None
  */
void MemManage_Handler(void) { while (1); }

/**
  * @brief This function handles Pre-fetch fault, memory access fault
  * @param None
  * @retval None
  */
void BusFault_Handler(void) { while (1); }

/**
  * @brief This function handles Undefined instruction or illegal state
  * @param None
  * @retval None
  */
void UsageFault_Handler(void) { while (1); }
