/* Author:   Sergio Martinez Porras
 * Date:     29/08/2020
 */

#ifndef ECUALM_API_H_
#define ECUALM_API_H_

    #define ECUALM_MAJOR_VERSION        1
    #define ECUALM_MINOR_VERSION        0
    #define ECUALM_PATCH_VERSION        5


    /* Include's -----------------------------------------------------------------*/


    /* Public Defines ------------------------------------------------------------*/


    /* Enumerates / Structures ---------------------------------------------------*/


    /* Public functions ----------------------------------------------------------*/

        /* Init actions */
        void ECUALM_Init(void);
        void ECUALM_DeInit(void);
        void ECUALM_PostInit(void);


        /* Periodic ECUALM tasks */
        void ECUALM_TaskInputs_5ms(void);
        void ECUALM_TaskInputs_10ms(void);
        void ECUALM_TaskInputs_100ms(void);
        //
        void ECUALM_TaskOutputs_5ms(void);
        void ECUALM_TaskOutputs_10ms(void);
        void ECUALM_TaskOutputs_100ms(void);

#endif /* ECUALM_API_H_ */
