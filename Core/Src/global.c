#include "global.h"
uint8_t tmp = 0;
uint8_t buffer[BUFFER_SIZE];
uint8_t buffer_flag = 0;
uint8_t index_buffer = 0;

uint8_t data_in[BUFFER_SIZE];
uint8_t data_out[BUFFER_SIZE];
uint8_t data_in_idx = 0;
//strcpy((char *)data_out, "Invalid command\n");
uint8_t data_out_idx = 0;
uint8_t cmdflag = 0;

ReceiveState rcv = WAIT_COMMAND;
CommandProcess cmd = RST;

void command_parser_fsm(){
	switch (rcv) {
		case WAIT_COMMAND:
			if(tmp == '!'){
				rcv = READ_COMMAND;
				memset(data_in, 0, BUFFER_SIZE);
				data_in_idx = 0;
			}
			break;
		case READ_COMMAND:
			if(tmp == '#'){
				rcv = WAIT_COMMAND;
				cmdflag = 1;
			}
			else{
				if(data_in_idx < BUFFER_SIZE) data_in[data_in_idx++] = tmp;
			}
			break;
		default:
			break;
	}

}
void uart_communication_fsm(){
	switch (cmd) {
		case RST:
			if((strcmp((char*)data_in, "RST") == 0) && cmdflag){
//				HAL_UART_Transmit(&huart2, (uint8_t *)"\r\n", 2, 1000);
				int adc = HAL_ADC_GetValue(&hadc1);
				sprintf((char*)data_out, "!ADC=%d#\r\n", adc);
				cmd = TRANSMIT;
				cmdflag = 0;
			}
			break;
		case TRANSMIT:
			HAL_UART_Transmit(&huart2, data_out, strlen((char*)data_out), 1000);
			setTimer0(3000);
			cmd = OK;
			break;
		case OK:
			if((strcmp((char*)data_in, "OK") == 0) && cmdflag){
//				HAL_UART_Transmit(&huart2, (uint8_t *)"\r\n", 2, 1000);
				cmd = RST;
				cmdflag = 0;
				memset(data_out, 0, BUFFER_SIZE);
				HAL_UART_Transmit(&huart2, data_out, strlen((char*)data_out), 1000);
			}
			else if(isTimerFlag0()){
				cmd = TRANSMIT;
			}
			break;
		default:
			break;
	}
}
