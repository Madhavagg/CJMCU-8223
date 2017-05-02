#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "config.h"
#include "nrf_drv_twi.h"
#include "app_error.h"
#include "nrf.h"
#include "bsp.h"
#include "app_util_platform.h"
#include "nrf_drv_config.h"   
#include "custom_board.h"
#include "LIS3DH.h"


extern nrf_drv_twi_t m_twi_master;
extern ret_code_t twi_master_init(void);
extern uint8_t LIS3DH_read(uint8_t addr);
extern ret_code_t LIS3DH_write(uint8_t addr, uint8_t wdata);

/**
 * @brief Initialize the master TWI
 *
 * Function used to initialize master TWI interface that would communicate with LIS3DH.
 *
 * @return NRF_SUCCESS or the reason of failure
 */
 
ret_code_t twi_master_init(void)
{
    ret_code_t ret;
    const nrf_drv_twi_config_t config =
    {
       .scl                = TWI_SCL_PIN,
       .sda                = TWI_SDA_PIN,
       .frequency          = NRF_TWI_FREQ_100K,
       .interrupt_priority = APP_IRQ_PRIORITY_HIGH
    };

    do
    {
        ret = nrf_drv_twi_init(&m_twi_master, &config, NULL, NULL);
        if(NRF_SUCCESS != ret)
        {
            break;
        }
        nrf_drv_twi_enable(&m_twi_master);
    }while(0);
    return ret;
}
/**
 * @brief Read data from LIS3DH
 *
 * Function uses TWI interface to read data from LIS3DH.
 *
 * @param     addr  Register address to read
 *
 * @return Read value.
 */

uint8_t LIS3DH_read(uint8_t addr)
{
	ret_code_t ret;
	static uint8_t receive_data;
	do
    {
      
       ret = nrf_drv_twi_tx(&m_twi_master, LIS3DH_SLAVE_ADDRESS, &addr, 1, true);
       if(NRF_SUCCESS != ret)
       {
           break;
       }
       ret = nrf_drv_twi_rx(&m_twi_master, LIS3DH_SLAVE_ADDRESS, &receive_data, 1);
    }while(0);
    return receive_data;
}
/**
 * @brief Write data to LIS3DH
 *
 * Function uses TWI interface to write data into LIS3DH.
 *
 * @param     addr  Register address to write
 * @param[in] wdata Data to send
 *
 * @return NRF_SUCCESS or reason of error.
 *
 */

ret_code_t LIS3DH_write(uint8_t addr, uint8_t wdata)
{
    ret_code_t ret;
	
    uint8_t tx_data[2] = {addr, wdata};
		ret=nrf_drv_twi_tx(&m_twi_master, LIS3DH_SLAVE_ADDRESS, tx_data, sizeof(tx_data), false);
	
    return ret;
}
