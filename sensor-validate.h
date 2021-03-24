
/*Header file*/
/* Indlude header files if any */
/**********************************************

***********************************************/
/* Define Macros*/
/**********************************************/
 #define DELTAMAXSOC 0.05
 #define DELTAMAXCURRENT 0.1
/**********************************************/

/****************************************************************************
Function declaration
***************************************************************************/
bool inputArrayisNotEmpty(int numOfValues);

bool ConsecutiveReadingIsAbrupt(double value, double nextValue, double maxDelta);

bool SensorReadingIsValid(double values[], int numOfValues, double deltavalue);

bool validateSOCreadings(double values[], int numOfValues);

bool validateCurrentreadings(double values[], int numOfValues);

