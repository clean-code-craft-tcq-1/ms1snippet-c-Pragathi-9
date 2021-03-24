
 #define DELTAMAXSOC 0.05
 #define DELTAMAXCURRENT 0.1

bool inputArrayisNotEmpty(int numOfValues);

bool SensorReadingIsFaulty(double* value, double nextValue, double maxDelta);

bool validateSOCreadings(double* values, int numOfValues);

bool validateCurrentreadings(double* values, int numOfValues);

bool validateSensorReadings(double values, int numOfValues, double deltavalue);
