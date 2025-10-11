/* Author:   Sergio Martinez Porras
 * Date:     29/08/2020
 */


/* Includes --------------------------------------------------------------------------------*/
    #include "main.h"        // Needed for pinout names (from ioc file)


/* Configuration Defines -------------------------------------------------------------------*/

    /* Pinout Digital Inputs */
        #define IOM_PIN_INPUT_SWITCH_DOOR                   DI_SWITCH_DOOR_GPIO_Port,               DI_SWITCH_DOOR_Pin
        #define IOM_PIN_INPUT_ENABLE_INTERCOM               DI_ENABLE_INTERCOM_GPIO_Port,           DI_ENABLE_INTERCOM_Pin
        #define IOM_PIN_INPUT_SWITCH_INTERCOM               DI_SWITCH_INTERCOM_GPIO_Port,           DI_SWITCH_INTERCOM_Pin


    /* Pinout Digital Outputs */
        #define IOM_PIN_OUTPUT_PC13_LED                     DO_PC13_LED_GPIO_Port,                  DO_PC13_LED_Pin
        //
        #define IOM_PIN_OUTPUT_RGB_R__DOOR_DETECTED         DO_RGB_R__DOOR_DETECTED_GPIO_Port,      DO_RGB_R__DOOR_DETECTED_Pin
        #define IOM_PIN_OUTPUT_RGB_G__INTERCOM_DETECTED     DO_RGB_G__INTERCOM_DETECTED_GPIO_Port,  DO_RGB_G__INTERCOM_DETECTED_Pin
        #define IOM_PIN_OUTPUT_BUZZER                       DO_BUZZER_GPIO_Port,                    DO_BUZZER_Pin
        //
        #define IOM_PIN_OUTPUT_DO_SW_TEST_01                DO_SW_TEST_01_GPIO_Port,                DO_SW_TEST_01_Pin
        #define IOM_PIN_OUTPUT_DO_SW_TEST_02                DO_SW_TEST_02_GPIO_Port,                DO_SW_TEST_02_Pin


    /* Comm */
        #define iom_MsgTX_length                            (80u)
