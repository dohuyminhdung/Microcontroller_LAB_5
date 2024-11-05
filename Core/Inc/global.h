#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include "main.h"
#include "softwaretimer.h"
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>

extern ADC_HandleTypeDef hadc1;
extern UART_HandleTypeDef huart2;
#define BUFFER_SIZE 50
extern uint8_t tmp;
extern uint8_t buffer[BUFFER_SIZE];
extern uint8_t buffer_flag;
extern uint8_t index_buffer;
extern uint8_t buffer_count;
extern uint8_t data_in[BUFFER_SIZE];
extern uint8_t data_out[BUFFER_SIZE];
extern uint8_t data_in_idx;
extern uint8_t data_out_idx;

typedef enum{
	WAIT_COMMAND,
	READ_COMMAND
}ReceiveState;

typedef enum{
	RST,
	TRANSMIT,
	OK
}CommandProcess;

void command_parser_fsm();
void uart_communication_fsm();
#endif /* INC_GLOBAL_H_ */
