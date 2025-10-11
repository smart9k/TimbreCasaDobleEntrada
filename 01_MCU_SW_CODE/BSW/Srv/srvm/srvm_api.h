/* Author:   Sergio Martinez Porras
 * Date:     29/08/2020
 */

#ifndef SRVM_API_H_
#define SRVM_API_H_

    #define SRVM_MAJOR_VERSION      1
    #define SRVM_MINOR_VERSION      0
    #define SRVM_PATCH_VERSION      1


    /* Include's -----------------------------------------------------------------*/


    /* Public Defines ------------------------------------------------------------*/


    /* Enumerates / Structures ---------------------------------------------------*/


    /* Public functions ----------------------------------------------------------*/

        /* Init actions */
        void SRVM_Init(void);
        void SRVM_DeInit(void);
        void SRVM_PostInit(void);

        /* Periodic SRVM tasks */
        void SRVM_Task_100ms(void);

#endif /* SRVM_API_H_ */
