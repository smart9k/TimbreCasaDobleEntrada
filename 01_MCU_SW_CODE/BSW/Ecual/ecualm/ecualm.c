
/* ################## Include's ####################### */

    /* Include types */
    #include "libTypes_api.h"

    /* Local prototypes */
    #include "ecualm_api.h"

    /* Include external API's */
    #include "iom_api.h"


/* ################## Define's ######################### */


/* ################## Global variables ################# */


/* ################## Local functions / Macros ######### */



//#####################################################
//#####################  SW Code  #####################
//#####################################################

/* ********************************* INIT ********************************* */
void ECUALM_Init(void) {
    /* Inputs / Outputs */
    IOM_Init();

    /* Communications */
}


void ECUALM_DeInit(void) {
    /* Inputs / Outputs */
    IOM_DeInit();

    /* Communications */
}


void ECUALM_PostInit(void) {
    /* Inputs */
    IOM_PostInit_Inputs();

    /* Communications */

    /* Outputs */
    IOM_PostInit_Outputs();
}



/* ********************************* PERIODIC TASKS INPUTS ********************************* */
void ECUALM_TaskInputs_5ms(void) {
    /* Inputs */
    IOM_InputsTask_5ms();
}


void ECUALM_TaskInputs_10ms(void) {
    /* Inputs */
}


void ECUALM_TaskInputs_100ms(void) {
    /* Inputs */
}



/* ********************************* PERIODIC TASKS OUTPUTS ********************************* */
void ECUALM_TaskOutputs_5ms(void) {
    /* Outputs */
    IOM_OutputsTask_5ms();

    /* Communications */
}


void ECUALM_TaskOutputs_10ms(void) {
    /* Outputs */

    /* Communications */
}


void ECUALM_TaskOutputs_100ms(void) {
    /* Outputs */

    /* Communications */
}



/* ********************************* REPORT INFO ********************************* */



/* ********************************* TEST FUNCTIONS ********************************* */


