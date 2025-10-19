
/* ################## Include's ####################### */

    /* Include types */
    #include "libTypes_api.h"
    #include "dataFormat_api.h"
    #include <stdio.h>
    #include <string.h>

    /* Local prototypes */
    #include "iom_api.h"
    #include "iom_cfg.h"

    /* DFA's */
    #include "dfaIO_api.h"

    /* Include external API's */
    #include "mcalm_api.h"
    //
    #include "osd_api.h"
    #include "osd_cfg.h"


/* ################## Define's ######################### */


/* ################## Global variables ################# */
    __attribute__((section(".Ram_COMM"))) char iom_MsgTX_data[iom_MsgTX_length] = {NULL_CHARACTER};

    /* iom_debounce */
    T_bit iom_debounce_last[E_IOM_TOTAL_DI_SIGNALS];
    T_bit iom_debounce_n_1[E_IOM_TOTAL_DI_SIGNALS];
    T_bit iom_debounce_n_2[E_IOM_TOTAL_DI_SIGNALS];
    T_bit iom_processed[E_IOM_TOTAL_DI_SIGNALS];
    //
    T_u32 iom_PostInitInputs_ms = T_U32_MIN;

    /* iom_StartUpValue */
    T_bit iom_StartupValue[E_IOM_TOTAL_DI_SIGNALS];

/* ################## Local functions / Macros ######### */
    /* Local functions */
        /* Initialize the digital inputs and outputs */
        static inline void iom_InputsInit(void);
        static inline void iom_OutputsInit(void);

        /* Read Inputs */
        static inline T_bit iom_ProcessDebounce(E_IOM_DigitalInput i_input);

        /* Read/Set Outputs */
        static inline void iom_SetOutputs(void);



//#####################################################
//#####################  SW Code  #####################
//#####################################################

/* ********************************* INIT ********************************* */
void IOM_Init(void) {
    T_u32 i;

    // 1) Initialize swC variables
    for (i = T_U32_MIN; i < E_IOM_TOTAL_DI_SIGNALS; i++) {
        iom_debounce_last[i] = FALSE;
        iom_debounce_n_1[i]  = FALSE;
        iom_debounce_n_2[i]  = FALSE;
        iom_processed[i]     = FALSE;
    }

    // 2) Initialize Inputs
    iom_InputsInit();

    // 3) Disable Outputs
    iom_OutputsInit();
}


void IOM_DeInit(void) {
    IOM_Init();
}


static inline void iom_InputsInit(void) {
    //
    // 1) Read start-up values
    iom_StartupValue[E_IOM__DI_ENABLE_INTERCOM] = HAL_GPIO_ReadPin( IOM_PIN_INPUT_ENABLE_INTERCOM );
    iom_StartupValue[E_IOM__DI_SWITCH_INTERCOM] = HAL_GPIO_ReadPin( IOM_PIN_INPUT_SWITCH_INTERCOM );
    iom_StartupValue[E_IOM__DI_SWITCH_DOOR]     = HAL_GPIO_ReadPin( IOM_PIN_INPUT_SWITCH_DOOR );

    // 2) Initialize values
    iom_PostInitInputs_ms = T_U32_MIN;
    //
    SetB_iom_EnableIntercom_raw( FALSE );
    SetB_iom_SwitchIntercom_raw( FALSE );
    SetB_iom_SwitchDoor_raw(     FALSE );
    //
    SetB_iom_EnableIntercom( FALSE );
    SetB_iom_SwitchIntercom( FALSE );
    SetB_iom_SwitchDoor(     FALSE );
}

static inline void iom_OutputsInit(void) {
    //
    // 1) Initialize values
    SetB_iom_IntercomDetected( FALSE );
    SetB_iom_DoorDetected(     FALSE );
    SetB_iom_Buzzer(           FALSE );

    // 2) Set initial values at Outputs
    IOM_SetOutput__DO_PC13_LED( IOM_LED_PC13_OFF );
    //
    iom_SetOutputs();
    //
    IOM_SetOutput__DO_SW_TEST_01( IOM_LOW );
    IOM_SetOutput__DO_SW_TEST_02( IOM_LOW );
}


void IOM_PostInit_Inputs(void) {
    IOM_InputsTask_5ms();
    //
    iom_PostInitInputs_ms += OSD_TASK_TIME_BASE_ms;
}


void IOM_PostInit_Outputs(void) {
    IOM_OutputsTask_5ms();
}



/* ********************************* PERIODIC TASKS ********************************* */
void IOM_InputsTask_5ms(void) {
    //
    // 1) Read data
    SetB_iom_EnableIntercom_raw( iom_ProcessDebounce( E_IOM__DI_ENABLE_INTERCOM ) );
    SetB_iom_SwitchIntercom_raw( HAL_GPIO_ReadPin( IOM_PIN_INPUT_SWITCH_INTERCOM ) );  // Input is AC 50 Hz, so, no Debounce if >= 5 ms Task is used
    SetB_iom_SwitchDoor_raw(     HAL_GPIO_ReadPin( IOM_PIN_INPUT_SWITCH_DOOR ) );      // Input is AC 50 Hz, so, no Debounce if >= 5 ms Task is used

    // 2) Process Data
    SetB_iom_EnableIntercom( !GetB_iom_EnableIntercom_raw() );  /* Negated Logic */
    SetB_iom_SwitchIntercom( !GetB_iom_SwitchIntercom_raw() );  /* Negated Logic */
    SetB_iom_SwitchDoor(     !GetB_iom_SwitchDoor_raw() );      /* Negated Logic */
}


void IOM_OutputsTask_5ms(void) {
    iom_SetOutputs();
}


void IOM_OutputsTask_10ms(void) {
    /**/
}



/* ********************************* INPUTS ********************************* */
static inline T_bit iom_ProcessDebounce(E_IOM_DigitalInput i_input) {
    //
    // Check input ID  (in case of wrong ID return a FALSE)
    if ( i_input < E_IOM_TOTAL_DI_SIGNALS ) {
        // 1.1) Information MUX
        if ( i_input == E_IOM__DI_ENABLE_INTERCOM ) {
            iom_debounce_last[i_input] = (T_bit)HAL_GPIO_ReadPin( IOM_PIN_INPUT_ENABLE_INTERCOM );
        } else if ( i_input == E_IOM__DI_SWITCH_INTERCOM ) {
            iom_debounce_last[i_input] = (T_bit)HAL_GPIO_ReadPin( IOM_PIN_INPUT_SWITCH_INTERCOM );
        } else if ( i_input == E_IOM__DI_SWITCH_DOOR ) {
                iom_debounce_last[i_input] = (T_bit)HAL_GPIO_ReadPin( IOM_PIN_INPUT_SWITCH_DOOR );
        } else {  /* Nothing */ }

        // 1.2) Do debouncing
        if ( (!iom_debounce_last[i_input]) && (!iom_debounce_n_1[i_input]) && (!iom_debounce_n_2[i_input]) )  {  iom_processed[i_input] = FALSE;  }
        else if ( iom_debounce_last[i_input] && iom_debounce_n_1[i_input] && iom_debounce_n_2[i_input] )      {  iom_processed[i_input] = TRUE;   }
        else {  /* Nothing */ }

        // 1.3) Update needed variables
        iom_debounce_n_2[i_input] = iom_debounce_n_1[i_input];
        iom_debounce_n_1[i_input] = iom_debounce_last[i_input];
        //
        return( iom_processed[i_input] );
    } else {
        return( FALSE );
    }
}



/* ********************************* OUTPUTS ********************************* */
static inline void iom_SetOutputs(void) {
    HAL_GPIO_WritePin( IOM_PIN_OUTPUT_RGB_G__INTERCOM_DETECTED,  GetB_iom_IntercomDetected() );
    HAL_GPIO_WritePin( IOM_PIN_OUTPUT_RGB_R__DOOR_DETECTED,      GetB_iom_DoorDetected() );
    HAL_GPIO_WritePin( IOM_PIN_OUTPUT_BUZZER,                    GetB_iom_Buzzer() );
}
