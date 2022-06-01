#ifndef RV32F0XX_HAL_DEF_H
#define RV32F0XX_HAL_DEF_H

#ifdef __cplusplus
 extern "C" {
#endif

#include "rv32f0xx.h"

typedef enum
{
  HAL_OK       = 0x00,
  HAL_ERROR    = 0x01,
  HAL_BUSY     = 0x02,
  HAL_TIMEOUT  = 0x03
} HAL_StatusTypeDef;

typedef enum
{
  HAL_UNLOCKED = 0x00,
  HAL_LOCKED   = 0x01
} HAL_LockTypeDef;

#define HAL_MAX_DELAY      0xFFFFFFFFU

#define HAL_IS_BIT_SET(REG, BIT)         (((REG) & (BIT)) == (BIT))
#define HAL_IS_BIT_CLR(REG, BIT)         (((REG) & (BIT)) == 0U)

#define __HAL_LINKDMA(__HANDLE__, __PPP_DMA_FIELD__, __DMA_HANDLE__)               \
                        do{                                                      \
                              (__HANDLE__)->__PPP_DMA_FIELD__ = &(__DMA_HANDLE__); \
                              (__DMA_HANDLE__).Parent = (__HANDLE__);             \
                          } while(0)

#define UNUSED(x) ((void)(x))
#define __HAL_RESET_HANDLE_STATE(__HANDLE__) ((__HANDLE__)->State = 0)

#if (USE_RTOS == 1)
  #error " USE_RTOS should be 0 in the current HAL release "
#else
  #define __HAL_LOCK(__HANDLE__)                                           \
                                do{                                        \
                                    if((__HANDLE__)->Lock == HAL_LOCKED)   \
                                    {                                      \
                                       return HAL_BUSY;                    \
                                    }                                      \
                                    else                                   \
                                    {                                      \
                                       (__HANDLE__)->Lock = HAL_LOCKED;    \
                                    }                                      \
                                  }while (0)

  #define __HAL_UNLOCK(__HANDLE__)                                          \
                                  do{                                       \
                                      (__HANDLE__)->Lock = HAL_UNLOCKED;    \
                                    }while (0)
#endif /* USE_RTOS */

#define __weak   __attribute__((weak))
#define __ALIGN_END    __attribute__ ((aligned (4)))
#define ALIGN_32BYTES(buf)  buf __attribute__ ((aligned (32))) 
#define __RAM_FUNC __attribute__((section(".RamFunc")))
#define __NOINLINE __attribute__ ( (noinline) )

#ifdef __cplusplus
}
#endif

#endif