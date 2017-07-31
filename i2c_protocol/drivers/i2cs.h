/*
 * i2cs.h
 *
 *  Created on: Jul 31, 2017
 *      Author: cody
 */
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef SOURCES_I2CS_H_
#define SOURCES_I2CS_H_
/* Includes ------------------------------------------------------------------*/
#include <stdint.h>
/* Exported define -----------------------------------------------------------*/
#define I2C_MASTER_SLAVE_ADDR_7BIT 0x53U
#define EXAMPLE_I2C_SLAVE_BASEADDR I2C1
#define I2C_SLAVE_CLK_SRC I2C1_CLK_SRC
#define I2C_SLAVE_IRQ I2C1_IRQn

/* Exported typedef ----------------------------------------------------------*/
typedef struct i2c_slave_callback
{
	/* Call back upper layer data when received every 1 byte */
	void (*clbk_hdl)(uint8_t data);
	/* Command from host which is received completely data */
	void (*receiver_hdl)(void);
	/* Command from host is received */
	void (*transmitter_hdl)(void);
	/* When receive a restart bit from host. */
	void (*restart_hdl)(void);
} i2c_slave_callback_t;


/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
/* Exported macro ------------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */
void i2cs_init(i2c_slave_callback_t *i2c_cb);

#endif /* SOURCES_I2CS_H_ */
