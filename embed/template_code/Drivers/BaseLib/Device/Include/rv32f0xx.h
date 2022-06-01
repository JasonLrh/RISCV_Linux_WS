#ifndef RV32F0XX_H
#define RV32F0XX_H

#ifdef __cplusplus
 extern "C" {
#endif 

#if defined(RV32F0EC)
#include "rv32f0ec.h"
#else
 #error "Please select first the target STM32H7xx device used in your application (in stm32h7xx.h file)"
#endif


#ifdef __cplusplus
}
#endif 

#endif