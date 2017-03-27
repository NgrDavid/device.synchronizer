#include <avr/io.h>
#include "hwbp_core_types.h"
#include "app_ios_and_regs.h"

/************************************************************************/
/* Configure and initialize IOs                                         */
/************************************************************************/
void init_ios(void)
{	/* Configure input pins */
	io_pin2in(&PORTA, 0, PULL_IO_TRISTATE, SENSE_IO_EDGES_BOTH);         // INPUT0
	io_pin2in(&PORTA, 1, PULL_IO_TRISTATE, SENSE_IO_EDGES_BOTH);         // INPUT1
	io_pin2in(&PORTA, 2, PULL_IO_TRISTATE, SENSE_IO_EDGES_BOTH);         // INPUT2
	io_pin2in(&PORTA, 3, PULL_IO_TRISTATE, SENSE_IO_EDGES_BOTH);         // INPUT3
	io_pin2in(&PORTA, 4, PULL_IO_TRISTATE, SENSE_IO_EDGES_BOTH);         // INPUT4
	io_pin2in(&PORTA, 5, PULL_IO_TRISTATE, SENSE_IO_EDGES_BOTH);         // INPUT5
	io_pin2in(&PORTB, 0, PULL_IO_TRISTATE, SENSE_IO_EDGES_BOTH);         // INPUT6
	io_pin2in(&PORTB, 1, PULL_IO_TRISTATE, SENSE_IO_EDGES_BOTH);         // INPUT7
	io_pin2in(&PORTB, 2, PULL_IO_TRISTATE, SENSE_IO_EDGES_BOTH);         // INPUT8
	io_pin2in(&PORTA, 7, PULL_IO_UP, SENSE_IO_EDGES_BOTH);               // ADD0
	io_pin2in(&PORTC, 1, PULL_IO_UP, SENSE_IO_EDGES_BOTH);               // ADD1

	/* Configure input interrupts */
	io_set_int(&PORTA, INT_LEVEL_LOW, 1, (1<<0), false);                 // INPUT0
	io_set_int(&PORTA, INT_LEVEL_LOW, 0, (1<<1), false);                 // INPUT1
	io_set_int(&PORTA, INT_LEVEL_LOW, 0, (1<<2), false);                 // INPUT2
	io_set_int(&PORTA, INT_LEVEL_LOW, 0, (1<<3), false);                 // INPUT3
	io_set_int(&PORTA, INT_LEVEL_LOW, 0, (1<<4), false);                 // INPUT4
	io_set_int(&PORTA, INT_LEVEL_LOW, 0, (1<<5), false);                 // INPUT5
	io_set_int(&PORTB, INT_LEVEL_LOW, 0, (1<<0), false);                 // INPUT6
	io_set_int(&PORTB, INT_LEVEL_LOW, 0, (1<<1), false);                 // INPUT7
	io_set_int(&PORTB, INT_LEVEL_LOW, 0, (1<<2), false);                 // INPUT8

	/* Interrupt vectors */
	//ISR(PORTA_INT1_vect, ISR_NAKED) {}                                 // INPUT0
	//ISR(PORTA_INT0_vect, ISR_NAKED) {}                                 // INPUT1
	//ISR(PORTA_INT0_vect, ISR_NAKED) {}                                 // INPUT2
	//ISR(PORTA_INT0_vect, ISR_NAKED) {}                                 // INPUT3
	//ISR(PORTA_INT0_vect, ISR_NAKED) {}                                 // INPUT4
	//ISR(PORTA_INT0_vect, ISR_NAKED) {}                                 // INPUT5
	//ISR(PORTB_INT0_vect, ISR_NAKED) {}                                 // INPUT6
	//ISR(PORTB_INT0_vect, ISR_NAKED) {}                                 // INPUT7
	//ISR(PORTB_INT0_vect, ISR_NAKED) {}                                 // INPUT8

	/* Configure output pins */
	io_pin2out(&PORTD, 0, OUT_IO_DIGITAL, IN_EN_IO_DIS);                 // LEDIN0
	io_pin2out(&PORTD, 1, OUT_IO_DIGITAL, IN_EN_IO_DIS);                 // LEDIN1
	io_pin2out(&PORTD, 2, OUT_IO_DIGITAL, IN_EN_IO_DIS);                 // LEDIN2
	io_pin2out(&PORTD, 3, OUT_IO_DIGITAL, IN_EN_IO_DIS);                 // LEDIN3
	io_pin2out(&PORTD, 4, OUT_IO_DIGITAL, IN_EN_IO_DIS);                 // LEDIN4
	io_pin2out(&PORTD, 5, OUT_IO_DIGITAL, IN_EN_IO_DIS);                 // LEDIN5
	io_pin2out(&PORTC, 4, OUT_IO_DIGITAL, IN_EN_IO_DIS);                 // LEDIN6
	io_pin2out(&PORTC, 5, OUT_IO_DIGITAL, IN_EN_IO_DIS);                 // LEDIN7
	io_pin2out(&PORTC, 6, OUT_IO_DIGITAL, IN_EN_IO_DIS);                 // LEDIN8
	io_pin2out(&PORTC, 7, OUT_IO_DIGITAL, IN_EN_IO_DIS);                 // LEDOUT0
	io_pin2out(&PORTC, 0, OUT_IO_DIGITAL, IN_EN_IO_EN);                  // OUTPUT0

	/* Initialize output pins */
	clr_LEDIN0;
	clr_LEDIN1;
	clr_LEDIN2;
	clr_LEDIN3;
	clr_LEDIN4;
	clr_LEDIN5;
	clr_LEDIN6;
	clr_LEDIN7;
	clr_LEDIN8;
	clr_LEDOUT0;
	clr_OUTPUT0;
}

/************************************************************************/
/* Registers' stuff                                                     */
/************************************************************************/
AppRegs app_regs;

uint8_t app_regs_type[] = {
	TYPE_U16,
	TYPE_U8,
	TYPE_U8,
	TYPE_U8,
	TYPE_U8,
	TYPE_U8,
	TYPE_U8,
	TYPE_U8,
	TYPE_U8
};

uint16_t app_regs_n_elements[] = {
	1,
	1,
	1,
	1,
	1,
	1,
	1,
	1,
	1
};

uint8_t *app_regs_pointer[] = {
	(uint8_t*)(&app_regs.REG_INPUTS_STATE),
	(uint8_t*)(&app_regs.REG_OUTPUTS),
	(uint8_t*)(&app_regs.REG_INPUT_CATCH_MODE),
	(uint8_t*)(&app_regs.REG_OUTPUT_MODE),
	(uint8_t*)(&app_regs.REG_RESERVED0),
	(uint8_t*)(&app_regs.REG_RESERVED1),
	(uint8_t*)(&app_regs.REG_RESERVED2),
	(uint8_t*)(&app_regs.REG_RESERVED3),
	(uint8_t*)(&app_regs.REG_EVNT_ENABLE)
};