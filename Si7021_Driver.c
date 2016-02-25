
/* Includes ------------------------------------------------------------------*/
#include "SI7021_Driver.h"
#ifdef  USE_FULL_ASSERT_SI7021
#include <stdio.h>
#endif

/**
* @brief  Get device type ID.
* @param  deviceid pointer to the returned device type ID.
* @retval Error code [HTS221_OK, HTS221_ERROR].
*/
Si7021_Error_et Si7021_Get_DeviceID(uint8_t* deviceid)
{  
  if(Si7021_ReadReg(Si7021_WHO_AM_I_REG, 2, deviceid)) return Si7021_ERROR;
  
  return Si7021_OK;
}

