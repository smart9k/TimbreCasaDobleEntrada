/* Author:   Sergio Martinez Porras
 * Date:     29/08/2020
 */


/* Configuration Defines -------------------------------------------------------------------*/

    /* Compilation defines */
        #define OSD_TEST_PERIODIC_TASK_100MS_ENABLED    /* Comment to disable it */
        /*#define OSD_TEST_PERIODIC_TASK_10MS_ENABLED*/     /* Comment to disable it */
        /*#define OSD_TEST_PERIODIC_TASK_5MS_ENABLED*/      /* Comment to disable it */
        /*#define OSD_TEST_PERIODIC_TICK__CPU_LOAD_CHECK*/      /* Comment to disable it */


    /* General Options */
        #define OSD_TASK_TIME_BASE_ms          (5u)
        //
        #define OSD_INIT_STATE_WAIT_ms         (0u)
        #define OSD_POST_INIT_STATE_WAIT_ms    (15u)  //For IOM Input Debounce

    /* Other */
