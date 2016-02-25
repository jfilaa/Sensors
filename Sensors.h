
#ifndef __SENSORS_H__
#define __SENSORS_H__

#include <stdint.h>

void HAL_Init_I2C();
void HAL_DeInit_I2C();
uint8_t HAL_ReadReg(uint8_t DeviceAddr, uint8_t RegAddr, uint8_t NumByteToRead, uint8_t* Data);
uint8_t HAL_WriteReg(uint8_t DeviceAddr, uint8_t RegAddr, uint8_t NumByteToWrite, uint8_t* Data);

#endif // __SENSORS_H__