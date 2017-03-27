#ifndef _APP_FUNCTIONS_H_
#define _APP_FUNCTIONS_H_
#include <avr/io.h>


/************************************************************************/
/* Define if not defined                                                */
/************************************************************************/
#ifndef bool
	#define bool uint8_t
#endif
#ifndef true
	#define true 1
#endif
#ifndef false
	#define false 0
#endif


/************************************************************************/
/* Prototypes                                                           */
/************************************************************************/
void app_read_REG_INPUTS_STATE(void);
void app_read_REG_OUTPUTS(void);
void app_read_REG_INPUT_CATCH_MODE(void);
void app_read_REG_OUTPUT_MODE(void);
void app_read_REG_RESERVED0(void);
void app_read_REG_RESERVED1(void);
void app_read_REG_RESERVED2(void);
void app_read_REG_RESERVED3(void);
void app_read_REG_EVNT_ENABLE(void);

bool app_write_REG_INPUTS_STATE(void *a);
bool app_write_REG_OUTPUTS(void *a);
bool app_write_REG_INPUT_CATCH_MODE(void *a);
bool app_write_REG_OUTPUT_MODE(void *a);
bool app_write_REG_RESERVED0(void *a);
bool app_write_REG_RESERVED1(void *a);
bool app_write_REG_RESERVED2(void *a);
bool app_write_REG_RESERVED3(void *a);
bool app_write_REG_EVNT_ENABLE(void *a);


#endif /* _APP_FUNCTIONS_H_ */