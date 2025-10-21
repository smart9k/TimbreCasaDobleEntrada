
/* ################## Include's ####################### */

    /* Include types */
    #include "libTypes_api.h"

    /* Local prototypes */
    #include "osd_api.h"
    #include "osd_cfg.h"

    /* DFA's */
    #include "dfaIO_api.h"

    /* Include external API's */
    #include "mcalm_api.h"
    //
    #include "ecualm_api.h"
    #include "iom_api.h"
    #include "iom_cfg.h"
    //
    #include "srvm_api.h"
    //
    #include "ver_api.h"
    //
    #include "appm_api.h"


/* ################## Define's ######################### */
    #define OSD_TASK_TIME_10_ms             (10u)
    #define OSD_TASK_TIME_100_ms            (100u)


/* ################## Global variables ################# */

    // External
        extern HAL_TickFreqTypeDef uwTickFreq;
        extern uint32_t uwTickPrio;

    // swC Variables
        __attribute__((section(".Ram_OSD"))) static E_OSD_State osd_state                 = E_OSD_STATE__DISABLED;
        __attribute__((section(".Ram_OSD"))) static T_u32 osd_Scheduler_cntInitWait       = T_U32_MIN;
        __attribute__((section(".Ram_OSD"))) static T_u32 osd_Scheduler_cntPostInitWait   = T_U32_MIN;
        __attribute__((section(".Ram_OSD"))) static T_u32 osd_NormalState_cnt_Tasks10ms   = T_U32_MIN;
        __attribute__((section(".Ram_OSD"))) static T_u32 osd_NormalState_cnt_Tasks100ms  = T_U32_MIN;
        __attribute__((section(".Ram_OSD"))) static T_u32 osd_NormalState_FreeRunCnt_ms   = T_U32_MIN;
        __attribute__((section(".Ram_OSD"))) static T_bit osd_NormalState_10_100msGapDone = FALSE;

    // Not initialized variables
        __attribute__((section(".noinit"))) volatile T_u32 osd_firstPowerOn;


/* ################## Local functions / Macros ######### */
    static inline void osd_InitState(void);
    static inline void osd_PostInitState(void);
    static inline void osd_NormalState(void);



//#####################################################
//#####################  SW Code  #####################
//#####################################################

/* ********************************* INIT ********************************* */
void OSD_Init(void) {
    //
    // 1) Disable SysTick
    HAL_SuspendTick();

    // 2) Restart swC variables
    osd_Scheduler_cntInitWait       = T_U32_MIN;
    osd_Scheduler_cntPostInitWait   = T_U32_MIN;
    osd_NormalState_cnt_Tasks10ms   = T_U32_MIN;
    osd_NormalState_cnt_Tasks100ms  = T_U32_MIN;
    osd_NormalState_FreeRunCnt_ms   = T_U32_MIN;
    osd_NormalState_10_100msGapDone = FALSE;

    // 3) Initialize OSD
    osd_state = E_OSD_STATE__INIT;

    // 4) Reconfigure SysTick interrupt time and re-enable SysTick
    if (OSD_TASK_TIME_BASE_ms > T_U32_MIN ) {
        uwTickFreq = OSD_TASK_TIME_BASE_ms;
        HAL_InitTick(uwTickPrio);
        HAL_ResumeTick();
    } else {  /* Keep OSD execution stopped due to a wrong tick time (0 ms is not possible) */  }
}


void OSD_DeInit(void) {
    osd_state = E_OSD_STATE__DISABLED;
    HAL_SuspendTick();
}



/* ********************************* PERIODIC TASKS ********************************* */
void OSD_SchedulerTask(void) {
    /*IOM_SetOutput__DO_SW_TEST_01( TRUE );*/  // Only for SW Testing
    //
    if ( osd_state == E_OSD_STATE__NORMAL ) {
        // OSD State = NORMAL
        #ifdef OSD_TEST_PERIODIC_TICK__CPU_LOAD_CHECK
            IOM_SetOutput__DO_PC13_LED( IOM_HIGH );
        #endif
        //
        osd_NormalState_FreeRunCnt_ms += OSD_TASK_TIME_BASE_ms;
        osd_NormalState();
        //
        #ifdef OSD_TEST_PERIODIC_TICK__CPU_LOAD_CHECK
            IOM_SetOutput__DO_PC13_LED( IOM_LOW );
        #endif
    }
    else if ( osd_state == E_OSD_STATE__POST_INIT ) {
        // OSD State = POST_INIT
        osd_PostInitState();    // Executed multiple times during this state
        //
        osd_Scheduler_cntPostInitWait += OSD_TASK_TIME_BASE_ms;
        if ( osd_Scheduler_cntPostInitWait >= OSD_POST_INIT_STATE_WAIT_ms ) {
            IOM_SetOutput__DO_PC13_LED( IOM_LED_PC13_OFF );    // Disable PC13_LED after leave POST_INIT state
            osd_state = E_OSD_STATE__NORMAL;
        }
        //
        if ( osd_Scheduler_cntPostInitWait % 50u == T_U32_MIN ) {   // Toggle PC13_LED during POST_INIT state each 50 ms to know that the uC/OSD has been restarted or waken up
            IOM_ToggleOutput__DO_PC13_LED();
        }
    }
    else if ( osd_state == E_OSD_STATE__INIT ) {
        // OSD State = INIT
        osd_Scheduler_cntInitWait += OSD_TASK_TIME_BASE_ms;
        if ( osd_Scheduler_cntInitWait <= OSD_TASK_TIME_BASE_ms ) {
            osd_InitState();
        }
        //
        if ( osd_Scheduler_cntInitWait >= OSD_INIT_STATE_WAIT_ms ) {
            osd_state = E_OSD_STATE__POST_INIT;
        }
    }
    else {
        // Do OSD State transition from DISABLED to INIT
        osd_state = E_OSD_STATE__INIT;
    }
    //
    /*IOM_SetOutput__DO_SW_TEST_01( FALSE );*/  // Only for SW Testing
}


E_OSD_State OSD_GetState(void) {
    return( osd_state );
}


T_u32 OSD_GetValue_FreeRunCounter_ms(void) {
    return( osd_NormalState_FreeRunCnt_ms );
}



/* ********************************* EXECUTION TASKS ********************************* */
static inline void osd_InitState(void) {
    MCALM_PeripheralsInit();
    //
    DFA_IO_init();
    //
    ECUALM_Init();
    SRVM_Init();
    //
    VER_Init();
    //
    APPM_Init();
}


static inline void osd_PostInitState(void) {
    //MCALM_PostInit();
    ECUALM_PostInit();
    SRVM_PostInit();
    //
    //VER_PostInit();
    //
    APPM_PostInit();
}


static inline void osd_NormalState(void) {
    //
    /*IOM_SetOutput__DO_SW_TEST_01( TRUE );*/  // Only for SW Testing

    /* TASKS  @ 5 ms */
    ECUALM_TaskInputs_5ms();
    APPM_Task_5ms();
    ECUALM_TaskOutputs_5ms();
    //
    #ifdef OSD_TEST_PERIODIC_TASK_5MS_ENABLED
        #ifndef OSD_TEST_PERIODIC_TASK_10MS_ENABLED
            #ifndef OSD_TEST_PERIODIC_TASK_100MS_ENABLED
                IOM_ToggleOutput__DO_PC13_LED();   // OSD TEST:  Toggle testpoint 5 ms
            #endif
        #endif
    #endif

    /* TASKS  @ 10 ms */
    if ( osd_NormalState_cnt_Tasks10ms >= OSD_TASK_TIME_10_ms ) {
        osd_NormalState_cnt_Tasks10ms = T_U32_MIN;     // Restart 10 ms counter
        //
        //ECUALM_TaskInputs_10ms();
        //APPM_Task_10ms();
        //ECUALM_TaskOutputs_10ms();
        //
        #ifdef OSD_TEST_PERIODIC_TASK_10MS_ENABLED
            #ifndef OSD_TEST_PERIODIC_TASK_100MS_ENABLED
                #ifndef OSD_TEST_PERIODIC_TASK_5MS_ENABLED
                    IOM_ToggleOutput__DO_PC13_LED();   // OSD TEST:  Toggle testpoint 10 ms
                #endif
            #endif
        #endif
    }

    /* TASKS  @ 100 ms */
    if ( osd_NormalState_10_100msGapDone ) {    // Variable used to avoid CPU Load over-peaks (to avoid have at same tick the 10 ms tasks and the 100 ms tasks)
        if ( osd_NormalState_cnt_Tasks100ms >= OSD_TASK_TIME_100_ms ) {
            osd_NormalState_cnt_Tasks100ms = T_U32_MIN;     // Restart 100 ms counter
            //
            //ECUALM_TaskInputs_100ms();
            SRVM_Task_100ms();
            //APPM_Task_100ms();
            //ECUALM_TaskOutputs_100ms();

            #ifdef OSD_TEST_PERIODIC_TASK_100MS_ENABLED
                #ifndef OSD_TEST_PERIODIC_TASK_5MS_ENABLED
                    #ifndef OSD_TEST_PERIODIC_TASK_10MS_ENABLED
                        IOM_ToggleOutput__DO_PC13_LED();   // OSD TEST:  Toggle testpoint 100 ms
                    #endif
                #endif
            #endif
        }
    } else {
        osd_NormalState_10_100msGapDone = TRUE;
    }
    //
    osd_NormalState_cnt_Tasks10ms  += OSD_TASK_TIME_BASE_ms;
    osd_NormalState_cnt_Tasks100ms += OSD_TASK_TIME_BASE_ms;

    /*IOM_SetOutput__DO_SW_TEST_01( FALSE );*/  /* Only for SW Testing */
}



/* ********************************* REPORT INFO ********************************* */



/* ********************************* TEST FUNCTIONS ********************************* */


