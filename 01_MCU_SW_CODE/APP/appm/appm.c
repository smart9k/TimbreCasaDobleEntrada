
/* ################## Include's ####################### */

    /* Include types */
    #include "libTypes_api.h"

    /* Local prototypes */
    #include "appm_api.h"

    /* Include external API's */
    #include "timbre_api.h"


/* ################## Define's ######################### */


/* ################## Global variables ################# */


/* ################## Local functions / Macros ######### */



//#####################################################
//#####################  SW Code  #####################
//#####################################################

/* ********************************* INIT ********************************* */
void APPM_Init(void) {
    // 1) Communication Handlers

    // 2) Applications
    TIMBRE_Init();
}


void APPM_DeInit(void) {
    // 1) Communication Handlers

    // 2) Applications
    TIMBRE_DeInit();
}


void APPM_PostInit(void) {
    // 1) Communication Handlers

    // 2) Applications
    TIMBRE_PostInit();
}



/* ********************************* PERIODIC TASKS ********************************* */
void APPM_Task_5ms(void) {
    // 1) Communication Handlers

    // 2) Applications
    TIMBRE_Task_5ms();
}


void APPM_Task_10ms(void) {
    // 1) Communication Handlers

    // 2) Applications
}



/* ********************************* REPORT INFO ********************************* */



/* ********************************* TEST FUNCTIONS ********************************* */


