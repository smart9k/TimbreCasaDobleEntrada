/* Author:   Sergio Martinez Porras
 * Date:     29/08/2020
 */

#ifndef OSD_API_H_
#define OSD_API_H_

    #define OSD_MAJOR_VERSION       1
    #define OSD_MINOR_VERSION       5
    #define OSD_PATCH_VERSION       0


    /* Include's -----------------------------------------------------------------*/
        #include "libTypes_api.h"

    /* Public Defines ------------------------------------------------------------*/

        /* OSD states */
        typedef enum {
            E_OSD_STATE__DISABLED,
            E_OSD_STATE__INIT,
            E_OSD_STATE__POST_INIT,
            E_OSD_STATE__NORMAL
        } E_OSD_State;


    /* Enumerates / Structures ---------------------------------------------------*/


    /* Public functions ----------------------------------------------------------*/

        /* Init/DeInit actions */
        void OSD_Init(void);
        void OSD_DeInit(void);

        /* Periodic OSD tasks */
        void OSD_SchedulerTask(void);
        E_OSD_State OSD_GetState(void);

        /* Free Run Counter (in ms) */
        T_u32 OSD_GetValue_FreeRunCounter_ms(void);

#endif /* OSD_API_H_ */
