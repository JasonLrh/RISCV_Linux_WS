#ifndef RV32F0XX_HAL_TIM_H
#define RV32F0XX_HAL_TIM_H

#ifdef __cplusplus
 extern "C" {
#endif

#include "rv32f0xx_hal_def.h"

typedef struct
{
  uint32_t Prescaler;         /*!< Specifies the prescaler value used to divide the TIM clock.
                                   This parameter can be a number between Min_Data = 0x0000 and Max_Data = 0xFFFF */

  uint32_t CounterMode;       /*!< Specifies the counter mode.
                                   This parameter can be a value of @ref TIM_Counter_Mode */

  uint32_t Period;            /*!< Specifies the period value to be loaded into the active
                                   Auto-Reload Register at the next update event.
                                   This parameter can be a number between Min_Data = 0x0000 and Max_Data = 0xFFFF.  */

  uint32_t ClockDivision;     /*!< Specifies the clock division.
                                   This parameter can be a value of @ref TIM_ClockDivision */

  uint32_t RepetitionCounter;  /*!< Specifies the repetition counter value. Each time the RCR downcounter
                                    reaches zero, an update event is generated and counting restarts
                                    from the RCR value (N).
                                    This means in PWM mode that (N+1) corresponds to:
                                        - the number of PWM periods in edge-aligned mode
                                        - the number of half PWM period in center-aligned mode
                                     GP timers: this parameter must be a number between Min_Data = 0x00 and
                                     Max_Data = 0xFF.
                                     Advanced timers: this parameter must be a number between Min_Data = 0x0000 and
                                     Max_Data = 0xFFFF. */

  uint32_t AutoReloadPreload;  /*!< Specifies the auto-reload preload.
                                   This parameter can be a value of @ref TIM_AutoReloadPreload */
} TIM_Base_InitTypeDef;

typedef enum
{
  HAL_TIM_STATE_RESET             = 0x00U,    /*!< Peripheral not yet initialized or disabled  */
  HAL_TIM_STATE_READY             = 0x01U,    /*!< Peripheral Initialized and ready for use    */
  HAL_TIM_STATE_BUSY              = 0x02U,    /*!< An internal process is ongoing              */
  HAL_TIM_STATE_TIMEOUT           = 0x03U,    /*!< Timeout state                               */
  HAL_TIM_STATE_ERROR             = 0x04U     /*!< Reception process is ongoing                */
} HAL_TIM_StateTypeDef;

typedef enum
{
  HAL_TIM_CHANNEL_STATE_RESET             = 0x00U,    /*!< TIM Channel initial state                         */
  HAL_TIM_CHANNEL_STATE_READY             = 0x01U,    /*!< TIM Channel ready for use                         */
  HAL_TIM_CHANNEL_STATE_BUSY              = 0x02U,    /*!< An internal process is ongoing on the TIM channel */
} HAL_TIM_ChannelStateTypeDef;

typedef enum
{
  HAL_TIM_ACTIVE_CHANNEL_1        = 0x01U,    /*!< The active channel is 1     */
  HAL_TIM_ACTIVE_CHANNEL_2        = 0x02U,    /*!< The active channel is 2     */
  HAL_TIM_ACTIVE_CHANNEL_3        = 0x04U,    /*!< The active channel is 3     */
  HAL_TIM_ACTIVE_CHANNEL_4        = 0x08U,    /*!< The active channel is 4     */
  HAL_TIM_ACTIVE_CHANNEL_5        = 0x10U,    /*!< The active channel is 5     */
  HAL_TIM_ACTIVE_CHANNEL_6        = 0x20U,    /*!< The active channel is 6     */
  HAL_TIM_ACTIVE_CHANNEL_CLEARED  = 0x00U     /*!< All active channels cleared */
} HAL_TIM_ActiveChannel;

typedef struct __TIM_HandleTypeDef
{
  TIM_TypeDef                        *Instance;         /*!< Register base address                             */
  TIM_Base_InitTypeDef               Init;              /*!< TIM Time Base required parameters                 */
  HAL_TIM_ActiveChannel              Channel;           /*!< Active channel                                    */
  HAL_LockTypeDef                    Lock;              /*!< Locking object                                    */
  __IO HAL_TIM_StateTypeDef          State;             /*!< TIM operation state                               */
  __IO HAL_TIM_ChannelStateTypeDef   ChannelState[6];   /*!< TIM channel operation state                       */
  __IO HAL_TIM_ChannelStateTypeDef   ChannelNState[4];  /*!< TIM complementary channel operation state         */

  void (* Base_MspInitCallback)(struct __TIM_HandleTypeDef *htim);              /*!< TIM Base Msp Init Callback                              */
  void (* Base_MspDeInitCallback)(struct __TIM_HandleTypeDef *htim);            /*!< TIM Base Msp DeInit Callback                            */
  void (* IC_MspInitCallback)(struct __TIM_HandleTypeDef *htim);                /*!< TIM IC Msp Init Callback                                */
  void (* IC_MspDeInitCallback)(struct __TIM_HandleTypeDef *htim);              /*!< TIM IC Msp DeInit Callback                              */
  void (* OC_MspInitCallback)(struct __TIM_HandleTypeDef *htim);                /*!< TIM OC Msp Init Callback                                */
  void (* OC_MspDeInitCallback)(struct __TIM_HandleTypeDef *htim);              /*!< TIM OC Msp DeInit Callback                              */
  void (* PWM_MspInitCallback)(struct __TIM_HandleTypeDef *htim);               /*!< TIM PWM Msp Init Callback                               */
  void (* PWM_MspDeInitCallback)(struct __TIM_HandleTypeDef *htim);             /*!< TIM PWM Msp DeInit Callback                             */
  void (* OnePulse_MspInitCallback)(struct __TIM_HandleTypeDef *htim);          /*!< TIM One Pulse Msp Init Callback                         */
  void (* OnePulse_MspDeInitCallback)(struct __TIM_HandleTypeDef *htim);        /*!< TIM One Pulse Msp DeInit Callback                       */
  void (* Encoder_MspInitCallback)(struct __TIM_HandleTypeDef *htim);           /*!< TIM Encoder Msp Init Callback                           */
  void (* Encoder_MspDeInitCallback)(struct __TIM_HandleTypeDef *htim);         /*!< TIM Encoder Msp DeInit Callback                         */
  void (* HallSensor_MspInitCallback)(struct __TIM_HandleTypeDef *htim);        /*!< TIM Hall Sensor Msp Init Callback                       */
  void (* HallSensor_MspDeInitCallback)(struct __TIM_HandleTypeDef *htim);      /*!< TIM Hall Sensor Msp DeInit Callback                     */
  void (* PeriodElapsedCallback)(struct __TIM_HandleTypeDef *htim);             /*!< TIM Period Elapsed Callback                             */
  void (* PeriodElapsedHalfCpltCallback)(struct __TIM_HandleTypeDef *htim);     /*!< TIM Period Elapsed half complete Callback               */
  void (* TriggerCallback)(struct __TIM_HandleTypeDef *htim);                   /*!< TIM Trigger Callback                                    */
  void (* TriggerHalfCpltCallback)(struct __TIM_HandleTypeDef *htim);           /*!< TIM Trigger half complete Callback                      */
  void (* IC_CaptureCallback)(struct __TIM_HandleTypeDef *htim);                /*!< TIM Input Capture Callback                              */
  void (* IC_CaptureHalfCpltCallback)(struct __TIM_HandleTypeDef *htim);        /*!< TIM Input Capture half complete Callback                */
  void (* OC_DelayElapsedCallback)(struct __TIM_HandleTypeDef *htim);           /*!< TIM Output Compare Delay Elapsed Callback               */
  void (* PWM_PulseFinishedCallback)(struct __TIM_HandleTypeDef *htim);         /*!< TIM PWM Pulse Finished Callback                         */
  void (* PWM_PulseFinishedHalfCpltCallback)(struct __TIM_HandleTypeDef *htim); /*!< TIM PWM Pulse Finished half complete Callback           */
  void (* ErrorCallback)(struct __TIM_HandleTypeDef *htim);                     /*!< TIM Error Callback                                      */
  void (* CommutationCallback)(struct __TIM_HandleTypeDef *htim);               /*!< TIM Commutation Callback                                */
  void (* CommutationHalfCpltCallback)(struct __TIM_HandleTypeDef *htim);       /*!< TIM Commutation half complete Callback                  */
  void (* BreakCallback)(struct __TIM_HandleTypeDef *htim);                     /*!< TIM Break Callback                                      */
  void (* Break2Callback)(struct __TIM_HandleTypeDef *htim);                    /*!< TIM Break2 Callback                                     */
} TIM_HandleTypeDef;

typedef enum
{
  HAL_TIM_BASE_MSPINIT_CB_ID              = 0x00U   /*!< TIM Base MspInit Callback ID                              */
  , HAL_TIM_BASE_MSPDEINIT_CB_ID          = 0x01U   /*!< TIM Base MspDeInit Callback ID                            */
  , HAL_TIM_IC_MSPINIT_CB_ID              = 0x02U   /*!< TIM IC MspInit Callback ID                                */
  , HAL_TIM_IC_MSPDEINIT_CB_ID            = 0x03U   /*!< TIM IC MspDeInit Callback ID                              */
  , HAL_TIM_OC_MSPINIT_CB_ID              = 0x04U   /*!< TIM OC MspInit Callback ID                                */
  , HAL_TIM_OC_MSPDEINIT_CB_ID            = 0x05U   /*!< TIM OC MspDeInit Callback ID                              */
  , HAL_TIM_PWM_MSPINIT_CB_ID             = 0x06U   /*!< TIM PWM MspInit Callback ID                               */
  , HAL_TIM_PWM_MSPDEINIT_CB_ID           = 0x07U   /*!< TIM PWM MspDeInit Callback ID                             */
  , HAL_TIM_ONE_PULSE_MSPINIT_CB_ID       = 0x08U   /*!< TIM One Pulse MspInit Callback ID                         */
  , HAL_TIM_ONE_PULSE_MSPDEINIT_CB_ID     = 0x09U   /*!< TIM One Pulse MspDeInit Callback ID                       */
  , HAL_TIM_ENCODER_MSPINIT_CB_ID         = 0x0AU   /*!< TIM Encoder MspInit Callback ID                           */
  , HAL_TIM_ENCODER_MSPDEINIT_CB_ID       = 0x0BU   /*!< TIM Encoder MspDeInit Callback ID                         */
  , HAL_TIM_HALL_SENSOR_MSPINIT_CB_ID     = 0x0CU   /*!< TIM Hall Sensor MspDeInit Callback ID                     */
  , HAL_TIM_HALL_SENSOR_MSPDEINIT_CB_ID   = 0x0DU   /*!< TIM Hall Sensor MspDeInit Callback ID                     */
  , HAL_TIM_PERIOD_ELAPSED_CB_ID          = 0x0EU   /*!< TIM Period Elapsed Callback ID                             */
  , HAL_TIM_PERIOD_ELAPSED_HALF_CB_ID     = 0x0FU   /*!< TIM Period Elapsed half complete Callback ID               */
  , HAL_TIM_TRIGGER_CB_ID                 = 0x10U   /*!< TIM Trigger Callback ID                                    */
  , HAL_TIM_TRIGGER_HALF_CB_ID            = 0x11U   /*!< TIM Trigger half complete Callback ID                      */

  , HAL_TIM_IC_CAPTURE_CB_ID              = 0x12U   /*!< TIM Input Capture Callback ID                              */
  , HAL_TIM_IC_CAPTURE_HALF_CB_ID         = 0x13U   /*!< TIM Input Capture half complete Callback ID                */
  , HAL_TIM_OC_DELAY_ELAPSED_CB_ID        = 0x14U   /*!< TIM Output Compare Delay Elapsed Callback ID               */
  , HAL_TIM_PWM_PULSE_FINISHED_CB_ID      = 0x15U   /*!< TIM PWM Pulse Finished Callback ID           */
  , HAL_TIM_PWM_PULSE_FINISHED_HALF_CB_ID = 0x16U   /*!< TIM PWM Pulse Finished half complete Callback ID           */
  , HAL_TIM_ERROR_CB_ID                   = 0x17U   /*!< TIM Error Callback ID                                      */
  , HAL_TIM_COMMUTATION_CB_ID             = 0x18U   /*!< TIM Commutation Callback ID                                */
  , HAL_TIM_COMMUTATION_HALF_CB_ID        = 0x19U   /*!< TIM Commutation half complete Callback ID                  */
  , HAL_TIM_BREAK_CB_ID                   = 0x1AU   /*!< TIM Break Callback ID                                      */
  , HAL_TIM_BREAK2_CB_ID                  = 0x1BU   /*!< TIM Break2 Callback ID                                     */
} HAL_TIM_CallbackIDTypeDef;

HAL_StatusTypeDef HAL_TIM_Base_Init(TIM_HandleTypeDef *htim);
HAL_StatusTypeDef HAL_TIM_Base_DeInit(TIM_HandleTypeDef *htim);

HAL_StatusTypeDef HAL_TIM_PWM_Init(TIM_HandleTypeDef *htim);
HAL_StatusTypeDef HAL_TIM_PWM_DeInit(TIM_HandleTypeDef *htim);

#ifdef __cplusplus
}
#endif

#endif