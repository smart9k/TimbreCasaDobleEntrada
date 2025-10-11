/* Author:   Sergio Martinez Porras
 * Date:     29/08/2020
 */

#ifndef APPM_API_H_
#define APPM_API_H_

    #define APPM_MAJOR_VERSION      1
    #define APPM_MINOR_VERSION      1
    #define APPM_PATCH_VERSION      0


    /* Include's -----------------------------------------------------------------*/


    /* Public Defines ------------------------------------------------------------*/


    /* Enumerates / Structures ---------------------------------------------------*/


    /* Public functions ----------------------------------------------------------*/

        /* Init actions */
        void APPM_Init(void);
        void APPM_DeInit(void);
        void APPM_PostInit(void);


        /* Periodic APPM tasks */
        void APPM_Task_5ms(void);
        void APPM_Task_10ms(void);

#endif /* APPM_API_H_ */
