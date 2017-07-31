/*
 * i2cs.c
 *
 *  Created on: Jul 31, 2017
 *      Author: cody
 */

/* Includes ------------------------------------------------------------------*/


#include "i2cs.h"
#include "fsl_i2c.h"
#include "fsl_debug_console.h"
/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* I2C slave configuration */
static i2c_slave_config_t i2c_slave =
{
    .enableGeneralCall = false,
    .enableWakeUp = false,
    .enableHighDrive = false,
    .enableBaudRateCtl = false,
    .enableSlave = true,
    .upperAddress = 0,

    .addressingMode = kI2C_Address7bit,
    .slaveAddress = I2C_MASTER_SLAVE_ADDR_7BIT,
};
i2c_slave_handle_t g_s_handle;
/* Static functions ----------------------------------------------------------*/
static void i2c_slave_callback(I2C_Type *base, i2c_slave_transfer_t *xfer, void *userData);


static void  (*rx_hdl)(uint8_t data);
static void  (*receiver_hdl)(void);
static void  (*transmitter_hdl)(void);
static void  (*restart_hdl)(void);
/* Exported variables --------------------------------------------------------*/
/* private functions --------------------------------------------------------*/
/* Exported functions --------------------------------------------------------*/
void i2cs_init(i2c_slave_callback_t *i2c_cb)
{
    /*store rx callback*/
    rx_hdl = i2c_cb->clbk_hdl;
    receiver_hdl = i2c_cb->receiver_hdl;
    transmitter_hdl = i2c_cb->transmitter_hdl;
    restart_hdl = i2c_cb->restart_hdl;

    /*init i2c*/
    I2C_SlaveInit(EXAMPLE_I2C_SLAVE_BASEADDR, &i2c_slave, CLOCK_GetFreq(I2C_SLAVE_CLK_SRC));

    memset(&g_s_handle, 0, sizeof(g_s_handle));

    /*  Set i2c slave interrupt priority higher. */
    NVIC_SetPriority(I2C_SLAVE_IRQ, 0);
    I2C_SlaveTransferCreateHandle(EXAMPLE_I2C_SLAVE_BASEADDR, &g_s_handle, i2c_slave_callback, NULL);
    I2C_SlaveTransferNonBlocking(EXAMPLE_I2C_SLAVE_BASEADDR, &g_s_handle, kI2C_SlaveCompletionEvent);

}


static void i2c_slave_callback(I2C_Type *base, i2c_slave_transfer_t *xfer, void *userData)
{
    switch (xfer->event)
    {
        /*  Transmit request */
        case kI2C_SlaveTransmitEvent:
//            /*  Update information for transmit process */
//            xfer->data = g_slave_buff;
//            xfer->dataSize = I2C_DATA_LENGTH;
        	(*transmitter_hdl)();
            break;

        /*  Receive request */
        case kI2C_SlaveReceiveEvent:
            /*  Update information for received process */
        	(*rx_hdl)(*(uint8_t *)userData);
//            PRINTF("Data 0x%x\r\n",*(uint8_t *)userData);
//          PRINTF("index: %d-0x%2x\r\n",index++,g_slave_buff[0]);
            break;

        /*  Transfer done */
        case kI2C_SlaveCompletionEvent:
        	(*receiver_hdl)();
            break;

        default:
            break;
    }
}
