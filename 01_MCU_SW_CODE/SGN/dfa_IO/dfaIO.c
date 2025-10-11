
/* ################## Include's ################## */

    /* Include types */
    #include "libTypes_api.h"

    /* Local prototypes */
    #include "dfaIO_api.h"

    /* Include external API's */
    #include "iom_api.h"


/* ################## Define's ######################### */


/* ################## Global variables ################# */

    /* *** INPUTS *** */
        __attribute__((section(".Ram_DFA"))) T_dfaIO_DigitalInputs       dfaIO_DigitalInputs;

    /* *** OUTPUTS *** */
        __attribute__((section(".Ram_DFA"))) T_dfaIO_DigitalOutputs      dfaIO_DigitalOutputs;


/* ################## Local functions / Macros ######### */
    void dfa_Init_DI(void);
    void dfa_Init_DO(void);



//#####################################################
//#####################  SW Code  #####################
//#####################################################

/* ********************************* INIT ********************************* */
void DFA_IO_init(void) {
    dfa_Init_DI();
    dfa_Init_DO();
}



/* ********************************* INPUTS ********************************* */
void dfa_Init_DI(void) {
    //
    // 1) Raw values
    SetB_iom_EnableIntercom_raw( FALSE );
    SetB_iom_SwitchIntercom_raw( FALSE );
    SetB_iom_SwitchDoor_raw(     FALSE );

    // 2) Processed values
    SetB_iom_EnableIntercom( FALSE );
    SetB_iom_SwitchIntercom( FALSE );
    SetB_iom_SwitchDoor(     FALSE );
}



/* ********************************* OUTPUTS ********************************* */
void dfa_Init_DO(void) {
    SetB_iom_IntercomDetected( FALSE );
    SetB_iom_DoorDetected(     FALSE );
    SetB_iom_Buzzer(           FALSE );
}
