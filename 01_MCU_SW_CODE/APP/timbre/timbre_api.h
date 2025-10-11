/* Author:   Sergio Martinez Porras
 * Date:     11/10/2025
 */

#ifndef TIMBRE_API_H_
#define TIMBRE_API_H_

    #define TIMBRE_MAJOR_VERSION       1
    #define TIMBRE_MINOR_VERSION       0
    #define TIMBRE_PATCH_VERSION       0


    /* Include's -----------------------------------------------------------------*/
        #include "timbre_cfg.h"


    /* Public Defines ------------------------------------------------------------*/


    /* Enumerates / Structures ---------------------------------------------------*/
        typedef struct {
            T_bit Now;
            T_bit Old;
            T_bit Triggered;
            T_u32 timer_ms;
        } S_Timbre_DI_Status;

    /* Public functions ----------------------------------------------------------*/

        /* Init actions */
        void TIMBRE_Init(void);
        void TIMBRE_DeInit(void);
        void TIMBRE_PostInit(void);

        /* Periodic TIMBRE tasks */
        void TIMBRE_Task_5ms(void);

#endif /* TIMBRE_API_H_ */

