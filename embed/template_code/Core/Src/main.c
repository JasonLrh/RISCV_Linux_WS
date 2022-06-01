#include "main.h"

#include <stdio.h>

#include "rv32f0xx_hal.h"

// #define STDOUT_FILENO   1
// #define STDERR_FILENO   2
// int _write(int file, char *ptr, int len)
// {
//     switch (file)
//     {
//     case STDOUT_FILENO: /*stdout*/
//         // Send the string somewhere
//         break;
//     case STDERR_FILENO: /* stderr */
//         // Send the string somewhere
//         break;
//     default:
//         return -1;
//     }
//     return len;
// }

uint8_t cas[1000];
uint8_t dqdq[1000] = {0};

int main(void){
    // printf("hello world\n");
    for (int i = 0; i < 1000; i ++){
        cas[i] = dqdq[i] = i ;
    }
    TIM_HandleTypeDef htim1 = {
        .Instance = TIM1,
    };

    HAL_TIM_Base_Init(&htim1);

    while (1){

    }

    return 0;
}

void SystemInit(void){
    // clock function here
}