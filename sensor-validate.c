#include "sensor-validate.h"

bool SensorReadingIsFaulty(double value, double nextValue, double maxDelta) {
  if(nextValue - value > maxDelta) {
    return 1;
  }
  return 0;
}

bool validateSensorReadings(double* values, numOfValues, deltavalue)
{
  int lastButOneIndex = numOfValues - 1;
    for(int i = 0; i < lastButOneIndex; i++) {
      if(SensorReadingIsFaulty(values[i], values[i + 1], deltavalue)) {
        return 0;
      }
  }
  return 1;
}

 bool inputArrayisNotEmpty(int numOfValues)
 {
   return (numOfValues>0 ? 1:0)
 }

bool validateSOCreadings(double* values, int numOfValues) 
{

 bool validatedSOCOutput=0;
 if (inputArrayisNotEmpty(numOfValues))
  {
    validatedSOCOutput=validateSensorReadings(values, numOfValues,DELTAMAXSOC);
  }
 return (validatedSOCOutput);
}

bool validateCurrentreadings(double* values, int numOfValues) 
{
  bool validatedCurrentOutput=0;
  if (inputArrayisNotEmpty(numOfValues))
  {
    validatedCurrentOutput=validateSensorReadings(values, numOfValues, DELTAMAXCURRENT);
  }
  return(validatedCurrentOutput);
  
}
