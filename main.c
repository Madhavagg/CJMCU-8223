#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "config.h"
#include "app_uart.h"
#include "nrf_drv_twi.h"
#include "nrf_drv_gpiote.h"
#include "nrf_gpio.h"
#include "app_error.h"
#include "nrf.h"
#include "bsp.h"
#include "nrf_delay.h"
#include "app_util_platform.h"
#include "nrf_drv_config.h"   
#include "custom_board.h"
#include "LIS3DH.h"

#define GPIOTE_CHANNEL_0 0

/**
 * @brief TWI function prototypes
 *
 * Definations for the declared prototypes can be found in TWI.c
 * 
 */
extern ret_code_t twi_master_init(void);
extern uint8_t LIS3DH_read(uint8_t addr);
extern ret_code_t LIS3DH_write(uint8_t addr, uint8_t wdata);



/**
 * @brief TWI master instance
 *
 * Instance of TWI master driver that would be used for communication with LIS3DH
 * 
 */
const nrf_drv_twi_t m_twi_master = NRF_DRV_TWI_INSTANCE(MASTER_TWI_INST);

void init_LIS3DH(void)
{
    // configurations for control registers
    
		
		LIS3DH_write(REG_CTRL_REG1, 0x27);      // Turn on the sensor with ODR = 10Hz normal mode.
    LIS3DH_write(REG_CTRL_REG2, 0x01);      // High-pass filter (HPF) enabled with 0.2Hz cut-off frequency for INT1 (AOI1) interrupt generation only.
    LIS3DH_write(REG_CTRL_REG3, 0x40);      // ACC AOI1 interrupt signal is routed to INT1 pin.
    LIS3DH_write(REG_CTRL_REG4, 0x88);      // Full Scale = +/-2 g with BDU and HR bits enabled.
    LIS3DH_write(REG_CTRL_REG5, 0x00);      // Default value. Interrupt signals on INT1 pin is not latched. Users don’t need to read the INT1_SRC register to clear the interrupt signal.
   
    // configurations for wakeup and motionless detection
    LIS3DH_write(REG_INT1_THS, 0x08);         // Threshold (THS) = 8LSBs * 15.625mg/LSB = 125mg.
    LIS3DH_write(REG_INT1_DURATION, 0x32);    // Duration = 50LSBs * (1/10Hz) = 5s.
    LIS3DH_write(REG_INT1_CFG, 0x95);         // Enable XLIE, YLIE and ZLIE interrupt generation, AND logic. It means that the interrupt will be generated when X and Y and Z axis acceleration is within the ±THS threshold simultaneously. 
}

void in_pin_handler(nrf_drv_gpiote_pin_t pin, nrf_gpiote_polarity_t action)
{
    nrf_drv_gpiote_out_toggle(LED_1);
}

static void init_gpio(void)
{
		ret_code_t err_code;
	
	  err_code = nrf_drv_gpiote_init();
    APP_ERROR_CHECK(err_code);
    
    nrf_drv_gpiote_out_config_t out_config = GPIOTE_CONFIG_OUT_SIMPLE(false);

    err_code = nrf_drv_gpiote_out_init(LED_1, &out_config);
    APP_ERROR_CHECK(err_code);
	
		nrf_drv_gpiote_in_config_t in_config = GPIOTE_CONFIG_IN_SENSE_TOGGLE(true); // GPIOTE_CONFIG_IN_SENSE_HITOLO if we want interrupt on HI to LOW. In this case Interrupt will occur either on Hi to Low or Low to High
    in_config.pull = NRF_GPIO_PIN_PULLUP;

    err_code = nrf_drv_gpiote_in_init(INT_1, &in_config, in_pin_handler);
    APP_ERROR_CHECK(err_code);

    nrf_drv_gpiote_in_event_enable(INT_1, true);



}


int main(void)
{
	  
		ret_code_t err_code;
	
	/* Initializing TWI master interface for LIS3DH */
    err_code = twi_master_init();
    APP_ERROR_CHECK(err_code);
	
		init_LIS3DH();
		init_gpio();

	
	while(1)
	{
		// To put the device in System ON sleep mode. 
		// The SoftDevice function sd_app_evt_wait() will do the same as these calls and put the CPU to System ON sleep mode when using BLE
		__SEV();	
		__WFE();
		__WFE();
		
//		if(nrf_gpio_pin_read(INT_1)==0)
//		{	
//			nrf_gpio_pin_set(LED_1);
//		}
//		
//		else if(nrf_gpio_pin_read(INT_1))
//		{
//			nrf_gpio_pin_clear(LED_1);
//		}
		
		
	
	}
	
}
