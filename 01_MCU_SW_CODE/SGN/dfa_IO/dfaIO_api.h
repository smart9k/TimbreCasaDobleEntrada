/* Author:   Sergio Martinez Porras
 * Date:     01/04/2024
 */

#ifndef DFA_IO_API_H
#define DFA_IO_API_H

    #define DFAIO_MAJOR_VERSION     1
    #define DFAIO_MINOR_VERSION     0
    #define DFAIO_PATCH_VERSION     0


    /*-----------------------------------------------------------------------------
    ** Type definition
    */

        /* *** INPUTS *** */
        typedef struct {
            T_bit B_raw;
            T_bit B_processed;
        }T_dfaIO_DigitalSignalType;

        typedef union {
            struct {
                // Digital Inputs
                T_dfaIO_DigitalSignalType  EnableIntercom;
                T_dfaIO_DigitalSignalType  SwitchIntercom;
                T_dfaIO_DigitalSignalType  SwitchDoor;
            };
        }T_dfaIO_DigitalInputs;


        /* *** OUTPUTS *** */
        typedef union {
            struct {
                // Digital Outputs
                T_bit B_IntercomDetected;
                T_bit B_DoorDetected;
                T_bit B_Buzzer;
            };
        }T_dfaIO_DigitalOutputs;


    /*-----------------------------------------------------------------------------
    ** External Data
    */

        /* *** INPUTS *** */
        extern T_dfaIO_DigitalInputs       dfaIO_DigitalInputs;

        /* *** OUTPUTS *** */
        extern T_dfaIO_DigitalOutputs      dfaIO_DigitalOutputs;


    /*-----------------------------------------------------------------------------
    ** Macros
    */

        /* *** INPUTS (raw) *** */
        #define SetB_iom_EnableIntercom_raw(x)          dfaIO_DigitalInputs.EnableIntercom.B_raw = ((T_bit)x)
        #define GetB_iom_EnableIntercom_raw()           dfaIO_DigitalInputs.EnableIntercom.B_raw
        #define SetB_iom_SwitchIntercom_raw(x)          dfaIO_DigitalInputs.SwitchIntercom.B_raw = ((T_bit)x)
        #define GetB_iom_SwitchIntercom_raw()           dfaIO_DigitalInputs.SwitchIntercom.B_raw
        #define SetB_iom_SwitchDoor_raw(x)              dfaIO_DigitalInputs.SwitchDoor.B_raw = ((T_bit)x)
        #define GetB_iom_SwitchDoor_raw()               dfaIO_DigitalInputs.SwitchDoor.B_raw

        /* *** INPUTS (processed) *** */
        #define SetB_iom_EnableIntercom(x)              dfaIO_DigitalInputs.EnableIntercom.B_processed = ((T_bit)x)
        #define GetB_iom_EnableIntercom()               dfaIO_DigitalInputs.EnableIntercom.B_processed
        #define SetB_iom_SwitchIntercom(x)              dfaIO_DigitalInputs.SwitchIntercom.B_processed = ((T_bit)x)
        #define GetB_iom_SwitchIntercom()               dfaIO_DigitalInputs.SwitchIntercom.B_processed
        #define SetB_iom_SwitchDoor(x)                  dfaIO_DigitalInputs.SwitchDoor.B_processed = ((T_bit)x)
        #define GetB_iom_SwitchDoor()                   dfaIO_DigitalInputs.SwitchDoor.B_processed


        /* *** OUTPUTS *** */
        #define SetB_iom_IntercomDetected(x)            dfaIO_DigitalOutputs.B_IntercomDetected = ((T_bit)x)
        #define GetB_iom_IntercomDetected()             dfaIO_DigitalOutputs.B_IntercomDetected
        #define SetB_iom_DoorDetected(x)                dfaIO_DigitalOutputs.B_DoorDetected = ((T_bit)x)
        #define GetB_iom_DoorDetected()                 dfaIO_DigitalOutputs.B_DoorDetected
        #define SetB_iom_Buzzer(x)                      dfaIO_DigitalOutputs.B_Buzzer = ((T_bit)x)
        #define GetB_iom_Buzzer()                       dfaIO_DigitalOutputs.B_Buzzer


    /*-----------------------------------------------------------------------------
    ** Public functions
    */

        /* Init actions */
        void DFA_IO_init(void);

#endif
