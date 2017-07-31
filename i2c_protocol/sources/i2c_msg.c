/*
 * i2c_msg.c
 *
 *  Created on: Jul 31, 2017
 *      Author: cody
 */
/* Includes ------------------------------------------------------------------*/
#include "i2cs.h"
#include "fsl_debug_console.h"
/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Static functions ----------------------------------------------------------*/
/* Exported variables --------------------------------------------------------*/
/* Exported functions --------------------------------------------------------*/

static void cb_rx_not_empty(uint8_t data)
{
	PRINTF("Data 0x%x\r\n", data);
}
static void cb_rx_complete(void)
{
	PRINTF("cb_rx_complete\r\n");
}
static void cb_tx_request(void)
{
	PRINTF("cb_tx_request\r\n");
}

void i2c_msg_init(void)
{
	/*Setup I2C slave to host communication*/
	i2c_slave_callback_t i2c_slave;

	i2c_slave.clbk_hdl = cb_rx_not_empty;
	i2c_slave.receiver_hdl = cb_rx_complete;
	i2c_slave.transmitter_hdl = cb_tx_request;

	i2cs_init(&i2c_slave);
}

