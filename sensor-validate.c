
/**********************************************
Include header files
***********************************************/
#include "sensor-validate.h"
/*********************************************/
/*********************************************
Function definitions
**********************************************/

/********************************************************************************
 * Function: inputArrayisNotEmpty
 
 * Description: A function that checks if the passed array is a null.
 
 * input: range of the input array
 
 * returns: True if the array is not empty
 *********************************************************************************/
bool inputArrayisNotEmpty(int numOfValues)
 {
   return (numOfValues>0 ? 1:0);
 }


/**************************************************************************************
 * Function: ConsecutiveReadingIsAbrupt
 
 * Description: A function that checks if the two concurrent readings 
 * have abrupt spike or jump more than the maximum delta threshold value.
 
 * input: two consecutive sensor values in a given array and the maximum
 * delta threshold of a particular sensor
 
 * returns: True if the difference between the two inputs is more than the delta value
 **************************************************************************************/

bool ConsecutiveReadingIsAbrupt(double value, double nextValue, double maxDelta)
{
  if(nextValue - value > maxDelta) {
    return 1;
  }
  return 0;
}

/********************************************************************************
 * Function: SensorReadingIsValid
 
 * Description: A function that checks if the passed array has concurrent readings 
 * with abrupt spike or jump more than the maximum delta threshold value.
 
 * input: input array with sensor values, range of the input array and 
 * the maximum delta threshold of a particular sensor
 
 * returns: True if the sensor readings DO NOT have abrupt spike in the consecutive readings
 *********************************************************************************/
bool SensorReadingIsValid(double values[], int numOfValues, double deltavalue)
{
  int lastButOneIndex = numOfValues - 1;
    for(int i = 0; i < lastButOneIndex; i++) {
      if(ConsecutiveReadingIsAbrupt(values[i], values[i + 1], deltavalue)) {
        return 0;
      }
  }
  return 1;
}

/********************************************************************************
 * Function: validateSOCreadings
 
 * Description: A function that validates the passed array of SOC valules 
 * has concurrent readings with abrupt spike or jump more than the maximum delta 
 * threshold value. 
 * It doesn't check the sensor validation if the array is null
 
 * Input: input array with SOC sensor values, range of the input array and 
 * the maximum delta threshold of a SOC Calculating sensor
 
 * returns: True if the sensor readings have abrupt spike in the consecutive readings
 *********************************************************************************/
 
bool validateSOCreadings(double values[], int numOfValues) 
{

 bool validatedSOCOutput=0;
 if (inputArrayisNotEmpty(numOfValues))
  {
    validatedSOCOutput=SensorReadingIsValid(values, numOfValues,DELTAMAXSOC);
  }
 return (validatedSOCOutput);
}


/********************************************************************************
 * Function: validateCurrentreadings
 
 * Description: A function that validates the passed array of current valules 
 * has concurrent readings with abrupt spike or jump more than the maximum delta 
 * threshold value. 
 * It doesn't check the sensor validation if the array is null
 
 * Input: input array with current sensor values, range of the input array and 
 * the maximum delta threshold of a current Calculating sensor
 
 * returns: True if the sensor readings have abrupt spike in the consecutive readings
 *********************************************************************************/
bool validateCurrentreadings(double values[], int numOfValues) 
{
  bool validatedCurrentOutput=0;
  if (inputArrayisNotEmpty(numOfValues))
  {
    validatedCurrentOutput=SensorReadingIsValid(values, numOfValues, DELTAMAXCURRENT);
  }
  return(validatedCurrentOutput);
  
}
