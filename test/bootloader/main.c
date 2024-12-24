/*-----------------------------------------------------------------------------------------------*/
/* Includes                                                                                      */
/*-----------------------------------------------------------------------------------------------*/
#include "stm32f7xx_hal.h"
#include "bootutil/bootutil.h"

/*-----------------------------------------------------------------------------------------------*/
/* Public functions                                                                              */
/*-----------------------------------------------------------------------------------------------*/
/**
  * @brief Application entry point
  * @param None
  * @retval None
  */
int main(void) {
  struct boot_rsp rsp = {0};

  /* Setup Flash, Systick and NVIC */
  HAL_Init();

  /* Call MCUboot's boot process */
  if (boot_go(&rsp) == 0) {
    void (*app_entry)(void) = (void (*)(void))rsp.br_image_addr;
    app_entry();
  }

  while (1) {}
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
