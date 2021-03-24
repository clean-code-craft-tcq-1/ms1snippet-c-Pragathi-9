#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
#include "sensor-validate.h"

TEST_CASE("reports error when SOC jumps abruptly") 
{
  double socReadings[] = {0.0, 0.01, 0.5, 0.51};
  int numOfSocReadings = sizeof(socReadings) / sizeof(socReadings[0]);
  REQUIRE(validateSOCreadings(socReadings, numOfSocReadings) == 0); 
}

TEST_CASE("SOC sensor is valid when the input array doesnt record any abrupt spike") 
{
  double socReadings[] = {0.2, 0.21, 0.24, 0.29, 0.32, 0.35};
  int numOfSocReadings = sizeof(socReadings) / sizeof(socReadings[0]);
  REQUIRE(validateSOCreadings(socReadings, numOfSocReadings) == 1); 
}

TEST_CASE("SOC sensor is not checked for fault when a null input array is passed") 
{
  double socReadings[] = {};
  int numOfSocReadings = sizeof(socReadings) / sizeof(socReadings[0]);
  REQUIRE(validateSOCreadings(socReadings, numOfSocReadings) == 0); 
}

TEST_CASE("reports error when current jumps abruptly") 
{
  double currentReadings[] = {0.0, 0.02, 0.03, 0.33};
  int numOfCurReadings = sizeof(currentReadings) / sizeof(currentReadings[0]);
  REQUIRE(validateCurrentreadings(currentReadings, numOfCurReadings) == 0);
}

TEST_CASE("Validation is positive when there are no abrupt spike in current ") 
{
  double currentReadings[] = {0.4, 0.45, 0.55, 0.65, 0.72, 0.75};
  int numOfCurReadings = sizeof(currentReadings) / sizeof(currentReadings[0]);
  REQUIRE(validateCurrentreadings(currentReadings, numOfCurReadings) == 1);
}

TEST_CASE("current sensor is not checked for fault when a null input array is passed") 
{
  double currentReadings[] = {};
  int numOfCurReadings = sizeof(currentReadings) / sizeof(currentReadings[0]);
  REQUIRE(validateCurrentreadings(currentReadings, numOfCurReadings) == 0);
}
