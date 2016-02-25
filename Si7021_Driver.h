
#ifndef __Si7021_DRIVER__H
#define __Si7021_DRIVER__H

#include <stdint.h>

#define Si7021_I2C_ADDRESS 0x80

// I2C commands
#define RH_READ             0xE5 
#define TEMP_READ           0xE3 
#define POST_RH_TEMP_READ   0xE0 
#define RESET               0xFE 
#define USER1_READ          0xE7 
#define USER1_WRITE         0xE6 

// compound commands
uint8_t SERIAL1_READ[]      = { 0xFA, 0x0F };
uint8_t SERIAL2_READ[]      = { 0xFC, 0xC9 };

/**
* @brief  Error type. 
 */
typedef enum {Si7021_OK = (uint8_t)0, Si7021_ERROR = !Si7021_OK} Si7021_Error_et;

/**
* @addtogroup Si7021_Registers
* @{
*/


/**
* @brief Device Identification register.
* \code
* Read
* Default value: 0xBC
* 7:0 This read-only register contains the device identifier for Si7021.
* \endcode
*/
#define Si7021_WHO_AM_I_REG          SERIAL1_READ

/**
* @brief Device Identification value.
*/
#define Si7013_WHO_AM_I_VAL         (uint8_t)0x0D
#define Si7020_WHO_AM_I_VAL         (uint8_t)0x14
#define Si7021_WHO_AM_I_VAL         (uint8_t)0x15

#define Si7021_HalInit                                  HAL_Init_I2C
#define Si7021_HalDeInit                                HAL_DeInit_I2C

// the user must redefine the proper Si7021_ReadReg
#define Si7021_ReadReg(RegAddr, NumByteToRead, Data)    HAL_ReadReg(Si7021_I2C_ADDRESS, RegAddr, NumByteToRead, Data)

// the user must redefine the proper Si7021_WriteReg
#define Si7021_WriteReg(RegAddr, NumByteToWrite, Data)  HAL_WriteReg(Si7021_I2C_ADDRESS, RegAddr, NumByteToWrite, Data)

Si7021_Error_et Si7021_Get_DeviceID(uint8_t* deviceid);

#endif // __Si7021_DRIVER__H