/* Author:   Sergio Martinez Porras
 * Date:     29/08/2020
 */

#ifndef IOM_API_H
#define IOM_API_H

    #define IOM_MAJOR_VERSION       2
    #define IOM_MINOR_VERSION       1
    #define IOM_PATCH_VERSION       4


    /* Include's -----------------------------------------------------------------*/
        #include "iom_cfg.h"

    /* Public Defines ------------------------------------------------------------*/
        #define IOM_HIGH                            (1u)
        #define IOM_LOW                             (0u)
        //
        #define IOM_LED_PC13_ON                     (0u)
        #define IOM_LED_PC13_OFF                    (1u)


    /* Enumerates / Structures ---------------------------------------------------*/

        typedef enum {
            E_IOM__DI_SWITCH_DOOR,
            E_IOM__DI_ENABLE_INTERCOM,
            E_IOM__DI_SWITCH_INTERCOM,
            //
            E_IOM_TOTAL_DI_SIGNALS
        } E_IOM_DigitalInput;

        typedef enum {
            E_IOM__DO_PC13_LED,
            //
            E_IOM__DO_RGB_R__DOOR_DETECTION,
            E_IOM__DO_RGB_G__INTERCOM_DETECTION,
            E_IOM__DO_BUZZER,
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
        void IOM_SetOutput(E_IOM_DigitalOutput i_output, T_bit output_level);
        //
        #define IOM_SetOutput__DO_PC13_LED(out_value)       ( HAL_GPIO_WritePin( IOM_PIN_OUTPUT_PC13_LED, out_value ) )
        #define IOM_ToggleOutput__DO_PC13_LED()             ( HAL_GPIO_TogglePin( IOM_PIN_OUTPUT_PC13_LED ) )
        //
        #define IOM_SetOutput__DO_SW_TEST_01(out_value)     ( HAL_GPIO_WritePin( IOM_PIN_OUTPUT_DO_SW_TEST_01, out_value ) )
        #define IOM_SetOutput__DO_SW_TEST_02(out_value)     ( HAL_GPIO_WritePin( IOM_PIN_OUTPUT_DO_SW_TEST_02, out_value ) )

        /* Reporting tasks */
        void IOM_ReportInputReadings_RAW(void);

#endif /* IOM_API_H */
