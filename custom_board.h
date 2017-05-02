#ifndef CUSTOM_BOARD_H
#define CUSTOM_BOARD_H

#define LEDS_NUMBER    2

#define LED_START      21
#define LED_1          23
#define LED_2          24

#define LED_STOP       24

#define LEDS_LIST { LED_1, LED_2}

#define BSP_LED_0      LED_1
#define BSP_LED_1      LED_2

#define BSP_LED_0_MASK (1<<BSP_LED_0)
#define BSP_LED_1_MASK (1<<BSP_LED_1)


#define LEDS_MASK      (BSP_LED_0_MASK | BSP_LED_1_MASK)

#define LEDS_INV_MASK  LEDS_MASK

//TWI Pins 

#define TWI_SCL_PIN 								7
#define TWI_SDA_PIN 								6
#define MASTER_TWI_INST							0    											//!< TWI interface used as a master accessing LIS3DH

// Pins to handle interrupt from LIS3DH
#define INT_1 1


#endif //CUSTOM_BOARD_H
