
/* ################## Include's ####################### */

    /* Include types */
    #include "libTypes_api.h"

    /* Local prototypes */
    #include "wdm_api.h"

    /* Include external API's */
    #include "mcalm_api.h"



/* ################## Define's ######################### */


/* ################## Global variables ################# */
    extern IWDG_HandleTypeDef hiwdg;


/* ################## Local functions / Macros ######### */



//#####################################################
//#####################  SW Code  #####################
//#####################################################

/* ********************************* INIT ********************************* */
void WDM_Init(void) {
    #ifdef DEBUG
        __HAL_DBGMCU_FREEZE_IWDG();  // During DEBUG disable the IWDG
    #endif

    /*
     * IWDG Configuration:
     *    Timeout = (Reload + 1) × Prescaler / LSI_Frequency
     *
     *    LSI_Frequency       = 32000 Hz (aprox)
     *    IWDG Timeout target = 3 seconds
     *      --> Prescaler = 128
     *      --> Reload    = 749
     */
}


void WDM_DeInit(void) {
    /* Nothing to do. The IWDG can't be stopped */
}



/* ********************************* PERIODIC TASKS ********************************* */
void WDM_Task_100ms(void) {
    HAL_IWDG_Refresh( &hiwdg );  /* Refresh Watchdog, otherwise at 3 seconds the MCU will restart itself */
}



/* ********************************* REPORT INFO ********************************* */



/* ********************************* TEST FUNCTIONS ********************************* */


