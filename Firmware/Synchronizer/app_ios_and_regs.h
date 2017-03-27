#ifndef _APP_IOS_AND_REGS_H_
#define _APP_IOS_AND_REGS_H_
#include "cpu.h"

void init_ios(void);
/************************************************************************/
/* Definition of input pins                                             */
/************************************************************************/
// INPUT0                 Description: Input 0
// INPUT1                 Description: Input 1
// INPUT2                 Description: Input 2
// INPUT3                 Description: Input 3
// INPUT4                 Description: Input 4
// INPUT5                 Description: Input 5
// INPUT6                 Description: Input 6
// INPUT7                 Description: Input 7
// INPUT8                 Description: Input 8
// ADD0                   Description: Address 0
// ADD1                   Description: Address 1

#define get_INPUT0 read_io(PORTA, 0)            // INPUT0
#define get_INPUT1 read_io(PORTA, 1)            // INPUT1
#define get_INPUT2 read_io(PORTA, 2)            // INPUT2
#define get_INPUT3 read_io(PORTA, 3)            // INPUT3
#define get_INPUT4 read_io(PORTA, 4)            // INPUT4
#define get_INPUT5 read_io(PORTA, 5)            // INPUT5
#define get_INPUT6 read_io(PORTB, 0)            // INPUT6
#define get_INPUT7 read_io(PORTB, 1)            // INPUT7
#define get_INPUT8 read_io(PORTB, 2)            // INPUT8
#define get_ADD0 read_io(PORTA, 7)              // ADD0
#define get_ADD1 read_io(PORTC, 1)              // ADD1

/************************************************************************/
/* Definition of output pins                                            */
/************************************************************************/
// LEDIN0                 Description: Board's LED for Input 0
// LEDIN1                 Description: Board's LED for Input 1
// LEDIN2                 Description: Board's LED for Input 2
// LEDIN3                 Description: Board's LED for Input 3
// LEDIN4                 Description: Board's LED for Input 4
// LEDIN5                 Description: Board's LED for Input 5
// LEDIN6                 Description: Board's LED for Input 6
// LEDIN7                 Description: Board's LED for Input 7
// LEDIN8                 Description: Board's LED for Input 8
// LEDOUT0                Description: Board's LED for Output 0
// OUTPUT0                Description: Output 0

/* LEDIN0 */
#define set_LEDIN0 clear_io(PORTD, 0)
#define clr_LEDIN0 set_io(PORTD, 0)
#define tgl_LEDIN0 toogle_io(PORTD, 0)
#define get_LEDIN0 read_io(PORTD, 0)

/* LEDIN1 */
#define set_LEDIN1 clear_io(PORTD, 1)
#define clr_LEDIN1 set_io(PORTD, 1)
#define tgl_LEDIN1 toogle_io(PORTD, 1)
#define get_LEDIN1 read_io(PORTD, 1)

/* LEDIN2 */
#define set_LEDIN2 clear_io(PORTD, 2)
#define clr_LEDIN2 set_io(PORTD, 2)
#define tgl_LEDIN2 toogle_io(PORTD, 2)
#define get_LEDIN2 read_io(PORTD, 2)

/* LEDIN3 */
#define set_LEDIN3 clear_io(PORTD, 3)
#define clr_LEDIN3 set_io(PORTD, 3)
#define tgl_LEDIN3 toogle_io(PORTD, 3)
#define get_LEDIN3 read_io(PORTD, 3)

/* LEDIN4 */
#define set_LEDIN4 clear_io(PORTD, 4)
#define clr_LEDIN4 set_io(PORTD, 4)
#define tgl_LEDIN4 toogle_io(PORTD, 4)
#define get_LEDIN4 read_io(PORTD, 4)

/* LEDIN5 */
#define set_LEDIN5 clear_io(PORTD, 5)
#define clr_LEDIN5 set_io(PORTD, 5)
#define tgl_LEDIN5 toogle_io(PORTD, 5)
#define get_LEDIN5 read_io(PORTD, 5)

/* LEDIN6 */
#define set_LEDIN6 clear_io(PORTC, 4)
#define clr_LEDIN6 set_io(PORTC, 4)
#define tgl_LEDIN6 toogle_io(PORTC, 4)
#define get_LEDIN6 read_io(PORTC, 4)

/* LEDIN7 */
#define set_LEDIN7 clear_io(PORTC, 5)
#define clr_LEDIN7 set_io(PORTC, 5)
#define tgl_LEDIN7 toogle_io(PORTC, 5)
#define get_LEDIN7 read_io(PORTC, 5)

/* LEDIN8 */
#define set_LEDIN8 clear_io(PORTC, 6)
#define clr_LEDIN8 set_io(PORTC, 6)
#define tgl_LEDIN8 toogle_io(PORTC, 6)
#define get_LEDIN8 read_io(PORTC, 6)

/* LEDOUT0 */
#define set_LEDOUT0 clear_io(PORTC, 7)
#define clr_LEDOUT0 set_io(PORTC, 7)
#define tgl_LEDOUT0 toogle_io(PORTC, 7)
#define get_LEDOUT0 read_io(PORTC, 7)

/* OUTPUT0 */
#define set_OUTPUT0 set_io(PORTC, 0)
#define clr_OUTPUT0 clear_io(PORTC, 0)
#define tgl_OUTPUT0 toogle_io(PORTC, 0)
#define get_OUTPUT0 read_io(PORTC, 0)


/************************************************************************/
/* Registers' structure                                                 */
/************************************************************************/
typedef struct
{
	uint16_t REG_INPUTS_STATE;
	uint8_t REG_OUTPUTS;
	uint8_t REG_INPUT_CATCH_MODE;
	uint8_t REG_OUTPUT_MODE;
	uint8_t REG_RESERVED0;
	uint8_t REG_RESERVED1;
	uint8_t REG_RESERVED2;
	uint8_t REG_RESERVED3;
	uint8_t REG_EVNT_ENABLE;
} AppRegs;

/************************************************************************/
/* Registers' address                                                   */
/************************************************************************/
/* Registers */
#define ADD_REG_INPUTS_STATE                32 // U16    State of each input (the address is included in the MSbits)
#define ADD_REG_OUTPUTS                     33 // U8     
#define ADD_REG_INPUT_CATCH_MODE            34 // U8     Configures when inputs will be catched
#define ADD_REG_OUTPUT_MODE                 35 // U8     Configures how the output behaves
#define ADD_REG_RESERVED0                   36 // U8     Not used
#define ADD_REG_RESERVED1                   37 // U8     Not used
#define ADD_REG_RESERVED2                   38 // U8     Not used
#define ADD_REG_RESERVED3                   39 // U8     Not used
#define ADD_REG_EVNT_ENABLE                 40 // U8     Enable the Events

/************************************************************************/
/* PWM Generator registers' memory limits                               */
/*                                                                      */
/* DON'T change the APP_REGS_ADD_MIN value !!!                          */
/* DON'T change these names !!!                                         */
/************************************************************************/
/* Memory limits */
#define APP_REGS_ADD_MIN                    0x20
#define APP_REGS_ADD_MAX                    0x28
#define APP_NBYTES_OF_REG_BANK              10

/************************************************************************/
/* Registers' bits                                                      */
/************************************************************************/
#define MSK_ADDRESS                        (3<<14)      // Board's address
#define MSK_INPUTS                         (0x1FF<<0)   // Board's inputs
#define B_INPUT0                           (1<<0)       // Input 0
#define B_INPUT1                           (1<<1)       // Input 1
#define B_INPUT2                           (1<<2)       // Input 2
#define B_INPUT3                           (1<<3)       // Input 3
#define B_INPUT4                           (1<<4)       // Input 4
#define B_INPUT5                           (1<<5)       // Input 5
#define B_INPUT6                           (1<<6)       // Input 6
#define B_INPUT7                           (1<<7)       // Input 7
#define B_INPUT8                           (1<<8)       // Input 8
#define B_OUTPUT0_STATE                    (1<<14)      // Reflects the Output 0 state
#define B_ADRESS0                          (1<<15)      // Address 0
#define B_ADRESS1                          (1<<16)      // Address 1
#define B_OUTPUT0                          (1<<0)       // Output 0
#define MSK_CATCH_MODE                     (15<<0)      // Catch mode
#define GM_INMODE_DISABLED                 (0<<0)       // Catch is disabled
#define GM_INMODE_WHEN_ANY_CHANGE          (1<<0)       // Catched everytime one of the Inputs changes
#define GM_INMODE_RISE_ON_INPUT0           (2<<0)       // Catched when Input 0 have a rising edge
#define GM_INMODE_FALL_ON_INPUT0           (3<<0)       // Catched when Input 0 have a falling edge
#define GM_INMODE_100Hz                    (4<<0)       // Catched at a frequency of 100 Hz
#define GM_INMODE_250Hz                    (5<<0)       // Catched at a frequency of 250 Hz
#define GM_INMODE_500Hz                    (6<<0)       // Catched at a frequency of 500 Hz
#define GM_INMODE_1000Hz                   (7<<0)       // Catched at a frequency of 1 KHz
#define GM_INMODE_2000Hz                   (8<<0)       // Catched at a frequency of 2 KHz
#define MSK_OUTPUT_MODE                    (7<<0)       // Output mode
#define GM_OUTMODE_NOT_USED                (0<<0)       // Not used by the ctach
#define GM_OUTMODE_TOGGLE                  (1<<0)       // Output toggles everytime the inputs are catched
#define GM_OUTMODE_INPUT0                  (2<<0)       // Output is equal to Input 0 (bit INPUT0)
#define GM_OUTMODE_PULSE_5mS               (3<<0)       // Output has a positive pulse of 5 milliseconds everytime the inputs are catched
#define GM_OUTMODE_PULSE_2mS               (4<<0)       // Output has a positive pulse of 2 milliseconds everytime the inputs are catched
#define GM_OUTMODE_PULSE_1mS               (5<<0)       // Output has a positive pulse of 1 milliseconds everytime the inputs are catched
#define GM_OUTMODE_PULSE_500uS             (6<<0)       // Output has a positive pulse of 500 microseconds everytime the inputs are catched
#define GM_OUTMODE_PULSE_250uS             (7<<0)       // Output has a positive pulse of 250 microseconds everytime the inputs are catched
#define B_EVT0                             (1<<0)       // Event of register INPUTS_STATE

#endif /* _APP_REGS_H_ */