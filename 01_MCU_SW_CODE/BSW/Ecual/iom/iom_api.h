/* Author:   Sergio Martinez Porras
 * Date:     29/08/2020
 */

#ifndef IOM_API_H
#define IOM_API_H

    #define IOM_MAJOR_VERSION       2
    #define IOM_MINOR_VERSION       2
    #define IOM_PATCH_VERSION       0


    /* Include's -----------------------------------------------------------------*/
        #include "main.h"        // Needed for pinout names (from ioc file)
        #include "iom_cfg.h"

    /* Public Defines ------------------------------------------------------------*/
        #define IOM_HIGH                            (1u)
        #define IOM_LOW                             (0u)
        //
        #define IOM_LED_PC13_ON                     (0u)
        #define IOM_LED_PC13_OFF                    (1u)


    /* Enumerates / Structures ---------------------------------------------------*/

        typedef enum {
            E_IOM__DI_ENABLE_INTERCOM,
            E_IOM__DI_SWITCH_INTERCOM,
            E_IOM__DI_SWITCH_DOOR,
            //
            E_IOM_TOTAL_DI_SIGNALS
        } E_IOM_DigitalInput;

        typedef enum {
            E_IOM__DO_BUZZER,
            //
            E_IOM__DO_PC13_LED,
            //
            E_IOM__DO_SW_TEST_01,
            E_IOM__DO_SW_TEST_02,
            //
            E_IOM_TOTAL_DO_SIGNALS
        } E_IOM_DigitalOutput;


    /* Public functions ----------------------------------------------------------*/

        /* Init actions */
        void IOM_Init(void);
        void IOM_DeInit(void);
        //
        void IOM_PostInit_Inputs(void);
        void IOM_PostInit_Outputs(void);

        /* Periodic IOM tasks */
        void IOM_InputsTask_5ms(void);
        void IOM_OutputsTask_5ms(void);
        void IOM_OutputsTask_10ms(void);

        /* Inputs functions */

        /* Outputs functions */
        #define IOM_ReadInput__DI_EnableIntercom()          ( HAL_GPIO_ReadPin( DI_ENABLE_INTERCOM_GPIO_Port, DI_ENABLE_INTERCOM_Pin ) )
        #define IOM_ReadInput__DI_SwitchIntercom()          ( HAL_GPIO_ReadPin( DI_SWITCH_INTERCOM_GPIO_Port, DI_SWITCH_INTERCOM_Pin ) )
        #define IOM_ReadInput__DI_SwitchDoor()              ( HAL_GPIO_ReadPin( DI_SWITCH_DOOR_GPIO_Port,     DI_SWITCH_DOOR_Pin ) )

        /* Pinout Digital Outputs */
        #define IOM_SetOutput__DO_BUZZER(out_value)         ( HAL_GPIO_WritePin( DO_BUZZER_GPIO_Port, DO_BUZZER_Pin, out_value ) )
        //
        #define IOM_SetOutput__DO_PC13_LED(out_value)       ( HAL_GPIO_WritePin(  DO_PC13_LED_GPIO_Port, DO_PC13_LED_Pin, out_value ) )
        #define IOM_ToggleOutput__DO_PC13_LED()             ( HAL_GPIO_TogglePin( DO_PC13_LED_GPIO_Port, DO_PC13_LED_Pin ) )
        //
        #define IOM_SetOutput__DO_SW_TEST_01(out_value)     ( HAL_GPIO_WritePin( DO_SW_TEST_01_GPIO_Port, DO_SW_TEST_01_Pin, out_value ) )
        #define IOM_SetOutput__DO_SW_TEST_02(out_value)     ( HAL_GPIO_WritePin( DO_SW_TEST_02_GPIO_Port, DO_SW_TEST_02_Pin, out_value ) )

        /* Reporting tasks */
        void IOM_ReportInputReadings_RAW(void);

#endif /* IOM_API_H */
