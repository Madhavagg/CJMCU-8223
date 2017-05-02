#ifndef LIS3DH_H
#define LIS3DH_H

	#define LIS3DH_SLAVE_ADDRESS 			  	0x19					// When SA0 is connected to power in CJMCU Board -> Bit 0 = 

	static const uint8_t REG_STATUS_AUX = 0x07;
	static const uint8_t REG_OUT_ADC1_L = 0x08;
	static const uint8_t REG_OUT_ADC1_H = 0x09;
	static const uint8_t REG_OUT_ADC2_L = 0x0a;
	static const uint8_t REG_OUT_ADC2_H = 0x0b;
	static const uint8_t REG_OUT_ADC3_L = 0x0c;
	static const uint8_t REG_OUT_ADC3_H = 0x0d;
	static const uint8_t REG_INT_COUNTER_REG = 0x0e;
	static const uint8_t REG_WHO_AM_I = 0x0f;
	static const uint8_t REG_TEMP_CFG_REG = 0x1f;
	static const uint8_t REG_CTRL_REG1 = 0x20;
	static const uint8_t REG_CTRL_REG2 = 0x21;
	static const uint8_t REG_CTRL_REG3 = 0x22;
	static const uint8_t REG_CTRL_REG4 = 0x23;
	static const uint8_t REG_CTRL_REG5 = 0x24;
	static const uint8_t REG_CTRL_REG6 = 0x25;
	static const uint8_t REG_REFERENCE = 0x26;
	static const uint8_t REG_STATUS_REG = 0x27;
	static const uint8_t REG_OUT_X_L = 0x28;
	static const uint8_t REG_OUT_X_H = 0x29;
	static const uint8_t REG_OUT_Y_L = 0x2a;
	static const uint8_t REG_OUT_Y_H = 0x2b;
	static const uint8_t REG_OUT_Z_L = 0x2c;
	static const uint8_t REG_OUT_Z_H = 0x2d;
	static const uint8_t REG_FIFO_CTRL_REG = 0x2e;
	static const uint8_t REG_FIFO_SRC_REG = 0x2f;
	static const uint8_t REG_INT1_CFG = 0x30;
	static const uint8_t REG_INT1_SRC = 0x31;
	static const uint8_t REG_INT1_THS = 0x32;
	static const uint8_t REG_INT1_DURATION = 0x33;
	static const uint8_t REG_CLICK_CFG = 0x38;
	static const uint8_t REG_CLICK_SRC = 0x39;
	static const uint8_t REG_CLICK_THS = 0x3a;
	static const uint8_t REG_TIME_LIMIT = 0x3b;
	static const uint8_t REG_TIME_LATENCY = 0x3c;
	static const uint8_t REG_TIME_WINDOW = 0x3d;
	static const uint8_t REG_ACT_THS = 0x3e;
	static const uint8_t REG_ACT_DUR = 0x3f;
		
#endif //LIS3DH.h

