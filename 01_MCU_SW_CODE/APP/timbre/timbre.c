
/* ################## Include's ####################### */

    /* Include types */
    #include "libTypes_api.h"
    #include "dataFormat_api.h"

    /* Local prototypes */
    #include "timbre_api.h"
    #include "timbre_cfg.h"

    /* DFA's */
    #include "dfaIO_api.h"

    /* Include external API's */


/* ################## Define's ######################### */


/* ################## Global variables ################# */
    S_Timbre_DI_Status timbre_DI_EnableIntercom;
    S_Timbre_DI_Status timbre_DI_SwitchIntercom;
    S_Timbre_DI_Status timbre_DI_SwitchDoor;


/* ################## Local functions / Macros ######### */
    static inline void timbre_APP(void);


//#####################################################
//#####################  SW Code  #####################
//#####################################################

/* ********************************* INIT ********************************* */
void TIMBRE_Init(void) {
    //
    // 1) Initialize swC variables
    timbre_DI_EnableIntercom.Now        = FALSE;
    timbre_DI_EnableIntercom.Old        = FALSE;
    timbre_DI_EnableIntercom.Triggered  = FALSE;
    timbre_DI_EnableIntercom.timer_ms   = T_U32_MIN;
    //
    timbre_DI_SwitchIntercom.Now        = FALSE;
    timbre_DI_SwitchIntercom.Old        = FALSE;
    timbre_DI_SwitchIntercom.Triggered  = FALSE;
    timbre_DI_SwitchIntercom.timer_ms   = T_U32_MIN;
    //
    timbre_DI_SwitchDoor.Now            = FALSE;
    timbre_DI_SwitchDoor.Old            = FALSE;
    timbre_DI_SwitchDoor.Triggered      = FALSE;
    timbre_DI_SwitchDoor.timer_ms       = T_U32_MIN;
}


void TIMBRE_DeInit(void) {
    // Add code
}


void TIMBRE_PostInit(void) {
    // Add code
}



/* ********************************* PERIODIC TASKS ********************************* */
void TIMBRE_Task_5ms(void) {
    timbre_APP();
}



/* ********************************* OTHER TASKS ********************************* */
static inline void timbre_APP(void) {
    //
    // 1) Read Inputs and set Input triggers
    timbre_DI_EnableIntercom.Now = GetB_iom_EnableIntercom();
    timbre_DI_SwitchIntercom.Now = GetB_iom_SwitchIntercom();
    timbre_DI_SwitchDoor.Now     = GetB_iom_SwitchDoor();
    //
    if( timbre_DI_EnableIntercom.Now ) {
        if( (timbre_DI_SwitchIntercom.Old == FALSE) && timbre_DI_SwitchIntercom.Now ) {
            if( timbre_DI_SwitchIntercom.Triggered == FALSE ) {
                timbre_DI_SwitchIntercom.Triggered = TRUE;
                timbre_DI_SwitchIntercom.timer_ms  = T_U32_MIN;
            }
        }
    } else {
        timbre_DI_SwitchIntercom.Triggered = FALSE;
        timbre_DI_SwitchIntercom.timer_ms  = T_U32_MIN;
    }
    //
    if( (timbre_DI_SwitchDoor.Old == FALSE) && timbre_DI_SwitchDoor.Now ) {
        if( timbre_DI_SwitchDoor.Triggered == FALSE ) {
            timbre_DI_SwitchDoor.Triggered = TRUE;
            timbre_DI_SwitchDoor.timer_ms  = T_U32_MIN;
        }
    }


    // 2) Buzzer APP
    // 2.1) DI_SwitchIntercomm vs Buzzer Timming
    if( timbre_DI_SwitchIntercom.Triggered ) {
        timbre_DI_SwitchIntercom.timer_ms += TIMBRE_PERIOD_TASK_5ms;
        SetB_iom_IntercomDetected( TRUE );
        //
        if( timbre_DI_SwitchIntercom.timer_ms <= 1250u ) {
            SetB_iom_Buzzer( TRUE );
        }
        else if( timbre_DI_SwitchIntercom.timer_ms <= 2500u ) {
            SetB_iom_Buzzer( FALSE );
        }
        else if( timbre_DI_SwitchIntercom.timer_ms <= 3750u ) {
            SetB_iom_Buzzer( TRUE );
        }
        else if( timbre_DI_SwitchIntercom.timer_ms <= 5000u ) {
            SetB_iom_Buzzer( FALSE );
        }
        else {
            timbre_DI_SwitchIntercom.Triggered = FALSE;
            timbre_DI_SwitchIntercom.timer_ms  = T_U32_MIN;
            SetB_iom_Buzzer( FALSE );
        }
    } else {
        timbre_DI_SwitchIntercom.timer_ms = T_U32_MIN;
        SetB_iom_IntercomDetected( FALSE );
    }


    // 2.2) DI_SwitchDoor vs Buzzer Timming
    if( timbre_DI_SwitchIntercom.Triggered == FALSE ) {  // Wait until Buzzer sound of SwitchIntercom detection finishes
        if( timbre_DI_SwitchDoor.Triggered ) {
            timbre_DI_SwitchDoor.timer_ms += TIMBRE_PERIOD_TASK_5ms;
            SetB_iom_DoorDetected( TRUE );
            //
            if( timbre_DI_SwitchDoor.timer_ms <= 2000u ) {
                SetB_iom_Buzzer( TRUE );
            }
            else if( timbre_DI_SwitchDoor.timer_ms <= 5000u ) {
                SetB_iom_Buzzer( FALSE );
            }
            else {
                timbre_DI_SwitchDoor.Triggered = FALSE;
                timbre_DI_SwitchDoor.timer_ms  = T_U32_MIN;
                SetB_iom_Buzzer( FALSE );
            }
        }
        else {
            timbre_DI_SwitchDoor.timer_ms = T_U32_MIN;
            SetB_iom_DoorDetected( FALSE );
        }
    }
    else {
        timbre_DI_SwitchDoor.timer_ms = T_U32_MIN;
        SetB_iom_DoorDetected( FALSE );
    }


    // 3) Update Variables
    timbre_DI_EnableIntercom.Old = timbre_DI_EnableIntercom.Now;
    timbre_DI_SwitchIntercom.Old = timbre_DI_SwitchIntercom.Now;
    timbre_DI_SwitchDoor.Old     = timbre_DI_SwitchDoor.Now;
}

