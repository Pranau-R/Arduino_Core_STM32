/**
  ******************************************************************************
  * @file    clock.c
  * @author  WI6LABS
  * @version V1.0.0
  * @date    01-August-2016
  * @brief   provide clock services for time purpose
  *
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; COPYRIGHT(c) 2016 STMicroelectronics</center></h2>
  * <h2><center>&copy; COPYRIGHT(c) 2019 MCCI Corporation</center></h2>
  *
  * Redistribution and use in source and binary forms, with or without modification,
  * are permitted provided that the following conditions are met:
  *   1. Redistributions of source code must retain the above copyright notice,
  *      this list of conditions and the following disclaimer.
  *   2. Redistributions in binary form must reproduce the above copyright notice,
  *      this list of conditions and the following disclaimer in the documentation
  *      and/or other materials provided with the distribution.
  *   3. Neither the name of STMicroelectronics nor the names of its contributors
  *      may be used to endorse or promote products derived from this software
  *      without specific prior written permission.
  *
  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  ******************************************************************************
  */
#include "stm32_def.h"

#ifdef __cplusplus
 extern "C" {
#endif

/**
  * @brief  Function called to read the current micro second
  * @param  None
  * @retval None
  */
uint32_t GetCurrentMicro(void)
{
  /* Ensure COUNTFLAG is reset by reading SysTick control and status register */
  LL_SYSTICK_IsActiveCounterFlag();
  uint32_t m = HAL_GetTick();
  uint32_t t = SysTick->LOAD + 1;
  uint32_t u = t - SysTick->VAL;
  if(LL_SYSTICK_IsActiveCounterFlag()) {
    m = HAL_GetTick();
    u = t - SysTick->VAL;
  }
  return ( m * 1000 + (u * 1000) / t);
}

/**
  * @brief  Function called wto read the current millisecond
  * @param  None
  * @retval None
  */
uint32_t GetCurrentMilli(void)
{
  return HAL_GetTick();
}

void noOsSystickHandler(){

}

void osSystickHandler() __attribute__((weak, alias("noOsSystickHandler")));
/**
  * @brief  Function called when t he tick interruption falls
  * @param  None
  * @retval None
  */
void SysTick_Handler(void)
{
  HAL_IncTick();
  HAL_SYSTICK_IRQHandler();
  osSystickHandler();
}

/**
  * @brief  Function provides us delay (required by some arduino libraries).
  *         Can be called inside an interrupt.
  * @param  None
  * @retval None
  */
void delayInsideIT(uint32_t delay_us)
{
  uint32_t nb_loop;
#if defined (STM32F0xx) || defined (STM32L0xx)
  nb_loop = (((HAL_RCC_GetHCLKFreq() / 1000000)/5)*delay_us)+1; /* uS (divide by 4 because each loop take about 4 cycles including nop +1 is here to avoid delay of 0 */
  __asm__ volatile(
  "1: " "\n\t"
  " nop " "\n\t"
  " sub %0, %0, #1 " "\n\t"
  " bne 1b " "\n\t"
  : "=r" (nb_loop)
  : "0"(nb_loop)
  : "r3"
  );
#else
  nb_loop = (((HAL_RCC_GetHCLKFreq() / 1000000)/4)*delay_us)+1; /* uS (divide by 4 because each loop take about 4 cycles including nop +1 is here to avoid delay of 0 */
  __asm__ volatile(
  "1: " "\n\t"
  " nop " "\n\t"
  " subs.w %0, %0, #1 " "\n\t"
  " bne 1b " "\n\t"
  : "=r" (nb_loop)
  : "0"(nb_loop)
  : "r3"
  );
#endif
}

#ifdef __cplusplus
}
#endif

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
