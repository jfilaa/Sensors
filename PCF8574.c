
/* Includes ------------------------------------------------------------------*/
#include "PCF8574_Driver.h"
#ifdef  USE_FULL_ASSERT_PCF8574
#include <stdio.h>
#endif

/**
* @brief  Get GPIO state
* @param  value
* @retval Error code [PCF8574_OK, PCF8574_ERROR].
*/
PCF8574_Error_et PCF8574_Get_State(uint8_t* state)
{  
  if(PCF8574_ReadReg(0, 2, state)) return PCF8574_ERROR;
  
  return PCF8574_OK;
}

/**
* @brief  Set GPIO state
* @param  value
* @retval Error code [PCF8574_OK, PCF8574_ERROR].
*/
PCF8574_Error_et PCF8574_Set_State(uint8_t* state)
{  
  if(PCF8574_WriteReg(0, 2, state)) return PCF8574_ERROR;
  
  return PCF8574_OK;
}

