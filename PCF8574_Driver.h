
#ifndef __PCF8574_DRIVER__H
#define __PCF8574_DRIVER__H

#include <stdint.h>

#define PCF8574_I2C_ADDRESS 0x40
//#define PCF8574_I2C_ADDRESS 0x41
//#define PCF8574_I2C_ADDRESS 0x42
//#define PCF8574_I2C_ADDRESS 0x43
//#define PCF8574_I2C_ADDRESS 0x44
//#define PCF8574_I2C_ADDRESS 0x45
//#define PCF8574_I2C_ADDRESS 0x46
//#define PCF8574_I2C_ADDRESS 0x47
//#define PCF8574_I2C_ADDRESS 0x48
//#define PCF8574_I2C_ADDRESS 0x49

/**
* @brief  Error type. 
 */
typedef enum {PCF8574_OK = (uint8_t)0, PCF8574_ERROR = !PCF8574_OK} PCF8574_Error_et;

// the user must redefine the proper PCF8574_ReadReg
#define PCF8574_ReadReg(RegAddr, NumByteToRead, Data)    HAL_ReadReg(PCF8574_I2C_ADDRESS, RegAddr, NumByteToRead, Data)

// the user must redefine the proper PCF8574_WriteReg
#define PCF8574_WriteReg(RegAddr, NumByteToWrite, Data)  HAL_WriteReg(PCF8574_I2C_ADDRESS, RegAddr, NumByteToWrite, Data)

PCF8574_Error_et PCF8574_Get_State(uint8_t* state);
PCF8574_Error_et PCF8574_Set_State(uint8_t* state);

#endif // __PCF8574_DRIVER__H