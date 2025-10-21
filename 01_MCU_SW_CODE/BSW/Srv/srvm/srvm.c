
/* ################## Include's ####################### */

    /* Include types */
    #include "libTypes_api.h"

    /* Local prototypes */
    #include "srvm_api.h"

    /* Include external API's */
    #include "wdm_api.h"


/* ################## Define's ######################### */


/* ################## Global variables ################# */


/* ################## Local functions / Macros ######### */



//#####################################################
//#####################  SW Code  #####################
//#####################################################

/* ********************************* INIT ********************************* */
void SRVM_Init(void) {
    WDM_Init();
}


void SRVM_DeInit(void) {
    /* Nothing */
}


void SRVM_PostInit(void) {
    /* Nothing */
}



/* ********************************* PERIODIC TASKS ********************************* */
void SRVM_Task_100ms(void) {
    WDM_Task_100ms();
}



/* ********************************* REPORT INFO ********************************* */



/* ********************************* TEST FUNCTIONS ********************************* */


