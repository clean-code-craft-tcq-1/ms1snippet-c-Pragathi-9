#include "sensor-validate.h"

int SensorReadingIsFaulty(double value, double nextValue, double maxDelta) {
  if(nextValue - value > maxDelta) {
    return 1;
  }
  return 0;
}

int validateSOCreadings(double* values, int numOfValues) {
  int lastButOneIndex = numOfValues - 1;
  for(int i = 0; i < lastButOneIndex; i++) {
    if(SensorReadingIsFaulty(values[i], values[i + 1], 0.05)) {
      return 0;
    }
  }
  return 1;
}

int validateCurrentreadings(double* values, int numOfValues) {
  int lastButOneIndex = numOfValues - 1;
  for(int i = 0; i < lastButOneIndex; i++) {
    if(SensorReadingIsFaulty(values[i], values[i + 1], 0.1)) {
      return 0;
    }
  }
  return 1;
}
