/* Author:   Sergio Martinez Porras
 * Date:     29/08/2020
 */

#ifndef WDM_API_H_
#define WDM_API_H_

    #define WDM_MAJOR_VERSION       1
    #define WDM_MINOR_VERSION       0
    #define WDM_PATCH_VERSION       0


    /* Include's -----------------------------------------------------------------*/


    /* Public Defines ------------------------------------------------------------*/


    /* Enumerates / Structures ---------------------------------------------------*/


    /* Public functions ----------------------------------------------------------*/

        /* Init actions */
        void WDM_Init(void);
        void WDM_DeInit(void);

        /* Other functions */
        void WDM_RefreshWatchdog(void);

#endif /* WDM_API_H_ */
