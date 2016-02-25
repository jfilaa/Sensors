// Sensors.cpp : Defines the entry point for the console application.
//


//#define _USE_BMP180_
#define _USE_HTS221_
#define _USE_LPS25HB_
#define _USE_SI7021_
#define _USE_PCF8574_

#if defined(__linux__)
 #include <linux/i2c-dev.h>
 //#include "i2cbusses.h"
#endif // __linux__

#include "stdio.h"
#include <stdint.h>
#include <string.h>
#include "LPS25HB_Driver.h"
#include "HTS221_Driver.h"
#include "BMP180.h"
#include "PCF8574_Driver.h"
#include "Sensors.h"

void PrintArray(uint8_t* Data, uint8_t Len)
{
	char Buffer[50];
	char* Pointer;
	int i = 0;

	Buffer[0] = '{';
	Buffer[1] = ' ';
	Pointer = &Buffer[0] + 2;
	for(i = 0; i < Len; i++) Pointer += sprintf(Pointer, "0x%02X ", *(Data + i));
	*(Pointer++) = '}';
	*(Pointer++) = '\n';
	*Pointer = '\0';
	printf(Buffer);
}

uint8_t HAL_ReadReg(uint8_t DeviceAddr, uint8_t RegAddr, uint8_t NumByteToRead, uint8_t* Data)
{
#if defined(__linux__)
	res = i2c_smbus_read_byte_data(file, daddress);

	if (res < 0)
	{
		fprintf(stderr, "Error: Read failed\n");
		exit(2);
	}
#else
	DeviceAddr = DeviceAddr >> 1;
	printf("Device 0x%02X Read register 0x%02X Len = %d\n", DeviceAddr, RegAddr, NumByteToRead);
	return 0;
#endif
}

uint8_t HAL_WriteReg(uint8_t DeviceAddr, uint8_t RegAddr, uint8_t NumByteToWrite, uint8_t* Data)
{
#if defined(__linux__)
	res = i2c_smbus_write_byte(file, daddress);
	if (res < 0) fprintf(stderr, "Warning - write failed\n");
#else
	DeviceAddr = DeviceAddr >> 1;	
	printf("Device 0x%02X Write register 0x%02X Data = ", DeviceAddr, RegAddr);
	PrintArray(Data, NumByteToWrite);
	return 0;
#endif
}

void HAL_Init_I2C()
{
}

void HAL_DeInit_I2C()
{
}

int main(int argc, char* argv[])
{
	uint8_t Data[20];
	uint8_t* Pointer;
#ifdef _USE_BMP180_
	bmp180_t bmp180;
#endif
	int res, i2cbus, address, size, file;

	memset(&Data, 0, sizeof(Data));

	// open I2C
#if defined(__linux__) // only Linux supported
	file = open_i2c_dev(i2cbus, filename, sizeof(filename), 0); // open I2C as file

	if (file < 0 || check_funcs(file, size, daddress, pec) || set_slave_addr(file, address, force)) exit(1); // check file

	if (!yes && !confirm(filename, address, size, daddress, pec)) exit(0);
 
	if (pec && ioctl(file, I2C_PEC, 1) < 0)
	{
		fprintf(stderr, "Error: Could not set PEC: %s\n", strerror(errno));
		close(file);
		exit(1);
	}

	/*res = i2c_smbus_write_byte(file, daddress);
	if (res < 0) fprintf(stderr, "Warning - write failed\n");

	res = i2c_smbus_read_byte(file);

	res = i2c_smbus_read_byte_data(file, daddress);*/

	close(file);
  
	if (res < 0)
	{
		fprintf(stderr, "Error: Read failed\n");
		exit(2);
	}
#endif

	/*HTS221_ReadReg(LPS25HB_RES_CONF_REG, 1, &Data[0]);
	Data[0] = 0x1;
	Data[1] = 0x2;
	Data[2] = 0x3;
	Pointer = &Data[0];
	HAL_WriteReg(LPS25HB_ADDRESS, LPS25HB_RES_CONF_REG, 3, &Data[0]);*/
	
#ifdef _USE_HTS221_
	HTS221_Get_DeviceID(&Data[1]);
	printf("HTS221_Get_DeviceID = 0x%02x\n", Data[1]);
#endif

#ifdef _USE_LPS25HB_
	LPS25HB_Get_DeviceID(&Data[2]);
	printf("LPS25HB_Get_DeviceID = 0x%02x\n", Data[2]);
#endif

#ifdef _USE_BMP180_
	bmp180_init(&bmp180);
	//printf("BMP180_Get_DeviceID = 0x%02x\n", Data[1]);
#endif

#ifdef _USE_SI7021_
	Si7021_Get_DeviceID(&Data[3]);
	printf("Si7021_Get_DeviceID = 0x%02x\n", Data[3]);
#endif

#ifdef _USE_PCF8574_
	PCF8574_Get_State(&Data[4]);
	PCF8574_Set_State(&Data[5]);
	printf("PCF8574_Get_State = 0x%02x\n", Data[4]);
#endif
	
	PrintArray(&Data[0], 5);

#if defined(__linux__) // only Linux supported
	close(file);
#endif

	return 0;
}

