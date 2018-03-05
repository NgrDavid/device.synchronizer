#include "app_funcs.h"
#include "app_ios_and_regs.h"
#include "hwbp_core.h"


/************************************************************************/
/* Create pointers to functions                                         */
/************************************************************************/
extern AppRegs app_regs;

void (*app_func_rd_pointer[])(void) = {
	&app_read_REG_INPUTS_STATE,
	&app_read_REG_OUTPUTS,
	&app_read_REG_INPUT_CATCH_MODE,
	&app_read_REG_OUTPUT_MODE,
	&app_read_REG_RESERVED0,
	&app_read_REG_RESERVED1,
	&app_read_REG_RESERVED2,
	&app_read_REG_RESERVED3,
	&app_read_REG_EVNT_ENABLE
};

bool (*app_func_wr_pointer[])(void*) = {
	&app_write_REG_INPUTS_STATE,
	&app_write_REG_OUTPUTS,
	&app_write_REG_INPUT_CATCH_MODE,
	&app_write_REG_OUTPUT_MODE,
	&app_write_REG_RESERVED0,
	&app_write_REG_RESERVED1,
	&app_write_REG_RESERVED2,
	&app_write_REG_RESERVED3,
	&app_write_REG_EVNT_ENABLE
};


/************************************************************************/
/* REG_INPUTS_STATE                                                     */
/************************************************************************/
void app_read_REG_INPUTS_STATE(void)
{
	app_regs.REG_INPUTS_STATE = ((~PORTA_IN) & 0x3F) | (((~PORTB_IN) & 0x7) << 6) | (PORTC_IN & 0x01 ? 0x2000 : 0) | (PORTA_IN & 0x80 ? 0x4000 : 0) | (PORTC_IN & 0x02 ? 0x8000 : 0);
}

bool app_write_REG_INPUTS_STATE(void *a)
{
	return false;
}


/************************************************************************/
/* REG_OUTPUTS                                                          */
/************************************************************************/
void app_read_REG_OUTPUTS(void)
{
	app_regs.REG_OUTPUTS = read_OUTPUT0 ? 1 : 0;
}

bool app_write_REG_OUTPUTS(void *a)
{
	uint8_t reg = *((uint8_t*)a) & 1;

	if (reg)
	{
		set_OUTPUT0;
		set_LEDOUT0;
	}
	else
	{
		clr_OUTPUT0;
		clr_LEDOUT0;
	}

	app_regs.REG_OUTPUTS = reg;
	return true;
}


/************************************************************************/
/* REG_INPUT_CATCH_MODE                                                 */
/************************************************************************/
void app_read_REG_INPUT_CATCH_MODE(void)
{
	//app_regs.REG_INPUT_CATCH_MODE = 0;

}

bool app_write_REG_INPUT_CATCH_MODE(void *a)
{
	uint8_t reg = *((uint8_t*)a) & MSK_CATCH_MODE;

	switch (reg)
	{
		case GM_INMODE_WHEN_ANY_CHANGE:
				/* Enable all interrupts */
				io_set_int(&PORTA, INT_LEVEL_LOW, 1, (1<<0), false);                 // INPUT0
				io_set_int(&PORTA, INT_LEVEL_LOW, 0, (1<<1), false);                 // INPUT1
				io_set_int(&PORTA, INT_LEVEL_LOW, 0, (1<<2), false);                 // INPUT2
				io_set_int(&PORTA, INT_LEVEL_LOW, 0, (1<<3), false);                 // INPUT3
				io_set_int(&PORTA, INT_LEVEL_LOW, 0, (1<<4), false);                 // INPUT4
				io_set_int(&PORTA, INT_LEVEL_LOW, 0, (1<<5), false);                 // INPUT5
				io_set_int(&PORTB, INT_LEVEL_LOW, 0, (1<<0), false);                 // INPUT6
				io_set_int(&PORTB, INT_LEVEL_LOW, 0, (1<<1), false);                 // INPUT7
				io_set_int(&PORTB, INT_LEVEL_LOW, 0, (1<<2), false);						// INPUT8
				break;
		
		case GM_INMODE_RISE_ON_INPUT0:
		case GM_INMODE_FALL_ON_INPUT0:
				/* Enable only interrupts on Input 0*/
				io_set_int(&PORTA, INT_LEVEL_LOW, 1, (1<<0), false);						// INPUT0
				io_set_int(&PORTA, INT_LEVEL_OFF, 0, (1<<1), false);                 // INPUT1
				io_set_int(&PORTB, INT_LEVEL_OFF, 0, (1<<0), false);                 // INPUT6
				break;

		case GM_INMODE_DISABLED:
		case GM_INMODE_100Hz:
		case GM_INMODE_250Hz:
		case GM_INMODE_500Hz:
		case GM_INMODE_1000Hz:
		case GM_INMODE_2000Hz:
				io_set_int(&PORTA, INT_LEVEL_OFF, 1, (1<<0), false);                 // INPUT0
				io_set_int(&PORTA, INT_LEVEL_OFF, 0, (1<<1), false);                 // INPUT1
				io_set_int(&PORTB, INT_LEVEL_OFF, 0, (1<<0), false);                 // INPUT6
				break;
				
		default:
				return false;				
	}

	app_regs.REG_INPUT_CATCH_MODE = reg;
	return true;
}


/************************************************************************/
/* REG_OUTPUT_MODE                                                      */
/************************************************************************/
void app_read_REG_OUTPUT_MODE(void)
{
	//app_regs.REG_OUTPUT_MODE = 0;

}

bool app_write_REG_OUTPUT_MODE(void *a)
{
	uint8_t reg = *((uint8_t*)a) & MSK_OUTPUT_MODE;

	switch (reg)
	{
		case GM_OUTMODE_INPUT0:
			if (read_INPUT0)
			{
				clr_OUTPUT0;
				clr_LEDOUT0;
			}
			else
			{
				set_OUTPUT0;
				set_LEDOUT0;
			}
			break;

		case GM_OUTMODE_PULSE_250uS:
		case GM_OUTMODE_PULSE_500uS:
		case GM_OUTMODE_PULSE_1mS:
		case GM_OUTMODE_PULSE_2mS:
		case GM_OUTMODE_PULSE_5mS:
			clr_OUTPUT0;
			clr_LEDOUT0;
			break;

		case GM_OUTMODE_NOT_USED:
		case GM_OUTMODE_TOGGLE:
			break;

		default:
			return false;
	}

	app_regs.REG_OUTPUT_MODE = reg;
	return true;
}


/************************************************************************/
/* REG_RESERVED0                                                        */
/************************************************************************/
void app_read_REG_RESERVED0(void)
{
	//app_regs.REG_RESERVED0 = 0;
}

bool app_write_REG_RESERVED0(void *a)
{
	return false;
}


/************************************************************************/
/* REG_RESERVED1                                                        */
/************************************************************************/
void app_read_REG_RESERVED1(void)
{
	//app_regs.REG_RESERVED1 = 0;
}

bool app_write_REG_RESERVED1(void *a)
{	
	return false;
}


/************************************************************************/
/* REG_RESERVED2                                                        */
/************************************************************************/
void app_read_REG_RESERVED2(void)
{
	//app_regs.REG_RESERVED2 = 0;
}

bool app_write_REG_RESERVED2(void *a)
{
	return false;
}


/************************************************************************/
/* REG_RESERVED3                                                        */
/************************************************************************/
void app_read_REG_RESERVED3(void)
{
	//app_regs.REG_RESERVED3 = 0;
}

bool app_write_REG_RESERVED3(void *a)
{
	return false;
}


/************************************************************************/
/* REG_EVNT_ENABLE                                                      */
/************************************************************************/
void app_read_REG_EVNT_ENABLE(void)
{
	//app_regs.REG_EVNT_ENABLE = 0;
}

bool app_write_REG_EVNT_ENABLE(void *a)
{
	uint8_t reg = *((uint8_t*)a) & B_EVT0;

	app_regs.REG_EVNT_ENABLE = reg;
	return true;
}


/************************************************************************/
/* CATCH                                                                */
/************************************************************************/
void read(bool filter_equal_readings)
{   
    uint16_t digital_inputs = ((~PORTA_IN) & 0x3F) | (((~PORTB_IN) & 0x7) << 6) | (PORTC_IN & 0x01 ? 0x2000 : 0) | (PORTA_IN & 0x80 ? 0x4000 : 0) | (PORTC_IN & 0x02 ? 0x8000 : 0);
    
    if (filter_equal_readings)
    {
        if ((digital_inputs & 0x01FF) == (app_regs.REG_INPUTS_STATE & 0x01FF))
            return;        
    }
    
    app_regs.REG_INPUTS_STATE = digital_inputs;

	if (core_bool_is_visual_enabled())
	{
		PORTD_OUT = (PORTA_IN & 0x3F);
		PORTC_OUT = (PORTC_OUT & 0x8F) | ((PORTB_IN & 0x7) << 4);
	}

	switch (app_regs.REG_OUTPUT_MODE & MSK_OUTPUT_MODE)
	{
		case GM_OUTMODE_TOGGLE:
			if (core_bool_is_visual_enabled())
				tgl_OUTPUT0;
			tgl_LEDOUT0;
			break;

		case GM_OUTMODE_INPUT0:
			if (read_INPUT0)
			{
				clr_OUTPUT0;
				clr_LEDOUT0;
			}
			else
			{
				if (core_bool_is_visual_enabled())
				{	
					set_OUTPUT0;
					set_LEDOUT0;
				}
			}
			break;

		case GM_OUTMODE_PULSE_250uS:
			timer_type0_pwm(&TCC0, TIMER_PRESCALER_DIV64, 0xFFFF, 125, INT_LEVEL_OFF, INT_LEVEL_LOW);
			if (core_bool_is_visual_enabled())
				set_LEDOUT0;
			break;

		case GM_OUTMODE_PULSE_500uS:
			timer_type0_pwm(&TCC0, TIMER_PRESCALER_DIV64, 0xFFFF, 250, INT_LEVEL_OFF, INT_LEVEL_LOW);
			if (core_bool_is_visual_enabled())
				set_LEDOUT0;
			break;

		case GM_OUTMODE_PULSE_1mS:
			timer_type0_pwm(&TCC0, TIMER_PRESCALER_DIV64, 0xFFFF, 500, INT_LEVEL_OFF, INT_LEVEL_LOW);
			if (core_bool_is_visual_enabled())
				set_LEDOUT0;
			break;
			
		case GM_OUTMODE_PULSE_2mS:
			timer_type0_pwm(&TCC0, TIMER_PRESCALER_DIV64, 0xFFFF, 1000, INT_LEVEL_OFF, INT_LEVEL_LOW);
			if (core_bool_is_visual_enabled())
				set_LEDOUT0;
			break;
			
		case GM_OUTMODE_PULSE_5mS:
			timer_type0_pwm(&TCC0, TIMER_PRESCALER_DIV64, 0xFFFF, 2500, INT_LEVEL_OFF, INT_LEVEL_LOW);
			if (core_bool_is_visual_enabled())
				set_LEDOUT0;
			break;
	}


	if (app_regs.REG_EVNT_ENABLE & B_EVT0)
		core_func_send_event(ADD_REG_INPUTS_STATE, true);
}


/************************************************************************/
/* INPUTS INTERRUPTS                                                    */
/************************************************************************/
/* Not used */
ISR(TCC0_OVF_vect, ISR_NAKED)
{
	reti();
}

/* OUT0 Pulse */
ISR(TCC0_CCA_vect, ISR_NAKED)
{
	timer_type0_stop(&TCC0);
	clr_LEDOUT0;

	reti();
}

/************************************************************************/
/* INPUTS INTERRUPTS                                                    */
/************************************************************************/
/* Inputs 0 */
ISR(PORTA_INT1_vect, ISR_NAKED)
{
	switch (app_regs.REG_INPUT_CATCH_MODE & MSK_CATCH_MODE)
	{
		case GM_INMODE_WHEN_ANY_CHANGE:
			read(true);
			break;

		case GM_INMODE_RISE_ON_INPUT0:
			if (!read_INPUT0)
				read(true);
			break;

		case GM_INMODE_FALL_ON_INPUT0:
			if (read_INPUT0)
				read(true);
			break;
	}

	reti();
}

/* Inputs 1 - 5 */
ISR(PORTA_INT0_vect, ISR_NAKED)
{	
	if ((app_regs.REG_INPUT_CATCH_MODE & MSK_CATCH_MODE) == GM_INMODE_WHEN_ANY_CHANGE)
		read(true);

	reti();
}

/* Input 6 - 8 */
ISR(PORTB_INT0_vect, ISR_NAKED)
{
	if ((app_regs.REG_INPUT_CATCH_MODE & MSK_CATCH_MODE) == GM_INMODE_WHEN_ANY_CHANGE)
		read(true);

	reti();
}