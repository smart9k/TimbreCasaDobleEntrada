/* Author:   Sergio Martinez Porras
 * Date:     20/05/2023
 */

#ifndef AAA_API_H_
#define AAA_API_H_

    #define AAA_MAJOR_VERSION       1
    #define AAA_MINOR_VERSION       0
    #define AAA_PATCH_VERSION       0


    /* Include's -----------------------------------------------------------------*/
        #include "aaa_cfg.h"


    /* Public Defines ------------------------------------------------------------*/


    /* Enumerates / Structures ---------------------------------------------------*/


    /* Public functions ----------------------------------------------------------*/

        /* Init actions */
        void AAA_Init(void);
        void AAA_DeInit(void);
        void AAA_PostInit(void);

        /* Periodic AAA tasks */
        void AAA_Task_10ms(void);
        void AAA_Task_50ms(void);
        void AAA_Task_100ms(void);

        /* Test functions */
        #ifdef AAA_TEST_FUNCTIONS_ENABLED
            void AAA_Test_01(void);
            void AAA_Test_02(void);
        #endif

#endif /* AAA_API_H_ */

