#ifndef RV32_HAL_CONF_H
#define RV32_HAL_CONF_H

#ifdef __cplusplus
 extern "C" {
#endif 

#define HAL_TIM_MODULE_ENABLED
#define HAL_UART_MODULE_ENABLED
#define HAL_GPIO_MODULE_ENABLED


#if !defined  (HSE_VALUE)
#define HSE_VALUE    (50000000UL) /*!< Value of the External oscillator in Hz : FPGA case fixed to 60MHZ */
#endif /* HSE_VALUE */


#ifdef HAL_TIM_MODULE_ENABLED
    #include "rv32f0xx_hal_tim.h"
#endif


#ifdef __cplusplus
}
#endif 

#endif