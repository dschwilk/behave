#define BOOST_TEST_MODULE BehaveTest

#include <boost/test/unit_test.hpp>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include "behaveRun.h"
#include "fuelModelSet.h"

// Define the error tolerance for double values
static const double ERROR_TOLERANCE = 1e-06;

double roundToSixDecimalPlaces(const double numberToBeRounded) 
{
    std::stringstream ss;
    ss << std::fixed;
    ss.precision(6); // set to 6 places after decimal
    ss << numberToBeRounded; // put number to be rounded into the stringstream
    std::string s = ss.str(); // convert stringstream to string
    double roundedValue = stod(s); // convert string to double
    return roundedValue;
}

struct BehaveRunTest
{
    FuelModelSet fuelModelSet;
    BehaveRun behaveRun;

    BehaveRunTest()
        : behaveRun(fuelModelSet)
    {
        BOOST_TEST_MESSAGE("Setup BehaveRun test");
    }

    ~BehaveRunTest()
    {
        BOOST_TEST_MESSAGE("Teardown BehaveRun test\n");
    }
};

void setSurfaceInputsForGS4LowMoistureScenario(BehaveRun& behaveRun)
{
    //Low Moisture Inputs 
    // 5 mph twenty ft wind, 30% slope, 50% canopy cover and crown ratio, 30 ft canopy cover
    int fuelModelNumber = 124; // fuel model gs4(124) chosen as it is dynamic and has values for all moisture classes
    double moistureOneHour = 6.0;
    double moistureTenHour = 7.0;
    double moistureHundredHour = 8.0;
    double moistureLiveHerbaceous = 60.0;
    double moistureLiveWoody = 90.0;
    MoistureUnits::MoistureUnitsEnum moistureUnits = MoistureUnits::PERCENT;
    double windSpeed = 5.0;
    WindHeightInputMode::WindHeightInputModeEnum windHeightInputMode = WindHeightInputMode::TWENTY_FOOT;
    SpeedUnits::SpeedUnitsEnum windSpeedUnits = SpeedUnits::MILES_PER_HOUR;
    double windDirection = 0;
    WindAndSpreadOrientationMode::WindAndSpreadOrientationModeEnum windAndSpreadOrientationMode = WindAndSpreadOrientationMode::RELATIVE_TO_NORTH;
    double slope = 30.0;
    SlopeUnits::SlopeUnitsEnum slopeUnits = SlopeUnits::PERCENT;
    double aspect = 0;
    double canopyCover = 50;
    double canopyHeight = 30.0;
    LengthUnits::LengthUnitsEnum canopyHeightUnits = LengthUnits::FEET;
    double crownRatio = 0.50;

    behaveRun.surface.updateSurfaceInputs(fuelModelNumber, moistureOneHour, moistureTenHour, moistureHundredHour, moistureLiveHerbaceous,
        moistureLiveWoody, moistureUnits, windSpeed, windSpeedUnits, windHeightInputMode, windDirection, windAndSpreadOrientationMode,
        slope, slopeUnits, aspect, canopyCover, canopyHeight, canopyHeightUnits, crownRatio);
}

void setSurfaceInputsForTwoFuelModelsLowMoistureScenario(BehaveRun& behaveRun)
{
    int firstFuelModelNumber = 1; // fuel model 1 chosen arbitrarily
    int secondFuelModelNumber = 124; // fuel model gs4(124) chosen as it is dynamic and has values for all moisture classes
    double moistureOneHour = 6.0;
    double moistureTenHour = 7.0;
    double moistureHundredHour = 8.0;
    double moistureLiveHerbaceous = 60.0;
    double moistureLiveWoody = 90.0;
    MoistureUnits::MoistureUnitsEnum moistureUnits = MoistureUnits::PERCENT;
    TwoFuelModels::TwoFuelModelsEnum twoFuelModelsMethod = TwoFuelModels::TWO_DIMENSIONAL;
    double windSpeed = 5.0;
    WindHeightInputMode::WindHeightInputModeEnum windHeightInputMode = WindHeightInputMode::TWENTY_FOOT;
    SpeedUnits::SpeedUnitsEnum windSpeedUnits = SpeedUnits::MILES_PER_HOUR;
    double windDirection = 0;
    WindAndSpreadOrientationMode::WindAndSpreadOrientationModeEnum windAndSpreadOrientationMode = WindAndSpreadOrientationMode::RELATIVE_TO_NORTH;
    double firstFuelModelCoverage = 0;
    double slope = 30.0;
    SlopeUnits::SlopeUnitsEnum slopeUnits = SlopeUnits::PERCENT;
    double aspect = 0;
    double canopyCover = 50;
    double canopyHeight = 30.0;
    LengthUnits::LengthUnitsEnum canopyHeightUnits = LengthUnits::FEET;
    double crownRatio = 0.50;

    behaveRun.surface.updateSurfaceInputsForTwoFuelModels(firstFuelModelNumber, secondFuelModelNumber, moistureOneHour, moistureTenHour, 
        moistureHundredHour, moistureLiveHerbaceous, moistureLiveWoody, moistureUnits, windSpeed, windSpeedUnits, windHeightInputMode,
        windDirection, windAndSpreadOrientationMode, firstFuelModelCoverage, twoFuelModelsMethod, slope, slopeUnits, aspect, canopyCover, 
        canopyHeight, canopyHeightUnits, crownRatio);
}

void setCrownInputsLowMoistureScenario(BehaveRun& behaveRun)
{
    //Low Moisture Inputs 
    // 5 mph twenty ft wind, 30% slope, 50% canopy cover and crown ratio, 30 ft canopy cover
    int fuelModelNumber = 124; // fuel model gs4(124) chosen as it is dynamic and has values for all moisture classes
    double moistureOneHour = 6.0;
    double moistureTenHour = 7.0;
    double moistureHundredHour = 8.0;
    double moistureLiveHerbaceous = 60.0;
    double moistureLiveWoody = 90.0;
    double moistureFoliar = 120;
    MoistureUnits::MoistureUnitsEnum moistureUnits = MoistureUnits::PERCENT;
    double windSpeed = 5.0;
    WindHeightInputMode::WindHeightInputModeEnum windHeightInputMode = WindHeightInputMode::TWENTY_FOOT;
    SpeedUnits::SpeedUnitsEnum windSpeedUnits = SpeedUnits::MILES_PER_HOUR;
    double windDirection = 0;
    WindAndSpreadOrientationMode::WindAndSpreadOrientationModeEnum windAndSpreadOrientationMode = WindAndSpreadOrientationMode::RELATIVE_TO_NORTH;
    double slope = 30.0;
    SlopeUnits::SlopeUnitsEnum slopeUnits = SlopeUnits::PERCENT;
    double aspect = 0;
    double canopyCover = 50;
    double canopyHeight = 30.0;
    LengthUnits::LengthUnitsEnum canopyHeightUnits = LengthUnits::FEET;
    double crownRatio = 0.50;
    double canopyBaseHeight = 6;
    double canopyBulkDensity = 0.03;
    
    behaveRun.crown.updateCrownInputs(fuelModelNumber, moistureOneHour, moistureTenHour, moistureHundredHour, moistureLiveHerbaceous,
        moistureLiveWoody, moistureFoliar, moistureUnits, windSpeed, windSpeedUnits, windHeightInputMode,
        windDirection, windAndSpreadOrientationMode, slope, slopeUnits, aspect, canopyCover, canopyHeight, canopyHeightUnits,
        crownRatio, canopyBaseHeight, canopyBulkDensity);
}

BOOST_FIXTURE_TEST_SUITE(BehaveRunTestSuite, BehaveRunTest)

BOOST_AUTO_TEST_CASE(singleFuelModelTest)
{
    // Observed and expected output
    double observedSurfaceFireSpreadRate = 0.0;
    double expectedSurfaceFireSpreadRate = 0.0;

    setSurfaceInputsForGS4LowMoistureScenario(behaveRun);

    SpeedUnits::SpeedUnitsEnum windSpeedUnits = SpeedUnits::MILES_PER_HOUR;

    // Test North oriented mode, 45 degree wind, 5 mph 20 foot wind, 30 degree slope
    WindHeightInputMode::WindHeightInputModeEnum windHeightInputMode = WindHeightInputMode::TWENTY_FOOT;
    behaveRun.surface.setWindHeightInputMode(windHeightInputMode);
    behaveRun.surface.setSlope(30, SlopeUnits::DEGREES);
    behaveRun.surface.setWindAndSpreadOrientationMode(WindAndSpreadOrientationMode::RELATIVE_TO_NORTH);
    behaveRun.surface.setWindSpeed(5, windSpeedUnits, windHeightInputMode);
    behaveRun.surface.setWindDirection(45);
    behaveRun.surface.setAspect(95);
    behaveRun.surface.doSurfaceRunInDirectionOfMaxSpread();
    observedSurfaceFireSpreadRate = roundToSixDecimalPlaces(behaveRun.surface.getSpreadRate(SpeedUnits::CHAINS_PER_HOUR));
    expectedSurfaceFireSpreadRate = 19.677584;
    BOOST_CHECK_CLOSE(observedSurfaceFireSpreadRate, expectedSurfaceFireSpreadRate, ERROR_TOLERANCE);

    // Test upslope oriented mode, 5 mph 20 foot uplsope wind
    behaveRun.surface.setFuelModelNumber(124);
    behaveRun.surface.setWindSpeed(5, windSpeedUnits, windHeightInputMode);
    behaveRun.surface.setWindHeightInputMode(WindHeightInputMode::TWENTY_FOOT);
    behaveRun.surface.setWindAndSpreadOrientationMode(WindAndSpreadOrientationMode::RELATIVE_TO_UPSLOPE);
    behaveRun.surface.setWindDirection(0);
    behaveRun.surface.setSlope(30, SlopeUnits::PERCENT);
    behaveRun.surface.setAspect(0);
    behaveRun.surface.doSurfaceRunInDirectionOfMaxSpread();
    observedSurfaceFireSpreadRate = roundToSixDecimalPlaces(behaveRun.surface.getSpreadRate(SpeedUnits::CHAINS_PER_HOUR));
    expectedSurfaceFireSpreadRate = 8.876216;
    BOOST_CHECK_CLOSE(observedSurfaceFireSpreadRate, expectedSurfaceFireSpreadRate, ERROR_TOLERANCE);

    // Test upslope oriented mode, 5 mph 20 foot wind cross-slope left to right (90 degrees)
    behaveRun.surface.setWindHeightInputMode(WindHeightInputMode::TWENTY_FOOT);
    behaveRun.surface.setWindAndSpreadOrientationMode(WindAndSpreadOrientationMode::RELATIVE_TO_UPSLOPE);
    behaveRun.surface.setWindSpeed(5, windSpeedUnits, windHeightInputMode);
    behaveRun.surface.setWindDirection(90);
    behaveRun.surface.doSurfaceRunInDirectionOfMaxSpread();
    observedSurfaceFireSpreadRate = roundToSixDecimalPlaces(behaveRun.surface.getSpreadRate(SpeedUnits::CHAINS_PER_HOUR));
    expectedSurfaceFireSpreadRate = 7.091665;
    BOOST_CHECK_CLOSE(observedSurfaceFireSpreadRate, expectedSurfaceFireSpreadRate, ERROR_TOLERANCE);

    // Test North oriented mode, 20 foot North wind, zero aspect
    behaveRun.surface.setWindHeightInputMode(WindHeightInputMode::TWENTY_FOOT);
    behaveRun.surface.setWindAndSpreadOrientationMode(WindAndSpreadOrientationMode::RELATIVE_TO_NORTH);
    behaveRun.surface.setWindDirection(0);
    behaveRun.surface.setAspect(0);
    behaveRun.surface.doSurfaceRunInDirectionOfMaxSpread();
    observedSurfaceFireSpreadRate = roundToSixDecimalPlaces(behaveRun.surface.getSpreadRate(SpeedUnits::CHAINS_PER_HOUR));
    expectedSurfaceFireSpreadRate = 8.876216;
    BOOST_CHECK_CLOSE(observedSurfaceFireSpreadRate, expectedSurfaceFireSpreadRate, ERROR_TOLERANCE);

    // Test North oriented mode, 20 foot North-East wind (45 degree), 215 degree aspect
    behaveRun.surface.setWindHeightInputMode(WindHeightInputMode::TWENTY_FOOT);
    behaveRun.surface.setWindAndSpreadOrientationMode(WindAndSpreadOrientationMode::RELATIVE_TO_NORTH);
    behaveRun.surface.setAspect(215);
    behaveRun.surface.setWindDirection(45);
    behaveRun.surface.doSurfaceRunInDirectionOfMaxSpread();
    observedSurfaceFireSpreadRate = roundToSixDecimalPlaces(behaveRun.surface.getSpreadRate(SpeedUnits::CHAINS_PER_HOUR));
    expectedSurfaceFireSpreadRate = 4.113265;
    BOOST_CHECK_CLOSE(observedSurfaceFireSpreadRate, expectedSurfaceFireSpreadRate, ERROR_TOLERANCE);

    // Test North oriented mode, 20 foot 45 degree wind, 95 degree aspect
    behaveRun.surface.setWindHeightInputMode(WindHeightInputMode::TWENTY_FOOT);
    behaveRun.surface.setWindAndSpreadOrientationMode(WindAndSpreadOrientationMode::RELATIVE_TO_NORTH);
    behaveRun.surface.setAspect(5);
    behaveRun.surface.setWindDirection(45);
    behaveRun.surface.doSurfaceRunInDirectionOfMaxSpread();
    observedSurfaceFireSpreadRate = roundToSixDecimalPlaces(behaveRun.surface.getSpreadRate(SpeedUnits::CHAINS_PER_HOUR));
    expectedSurfaceFireSpreadRate = 8.503960;
    BOOST_CHECK_CLOSE(observedSurfaceFireSpreadRate, expectedSurfaceFireSpreadRate, ERROR_TOLERANCE);

    // Test Non-Burnable Fuel
    behaveRun.surface.setFuelModelNumber(91);
    behaveRun.surface.doSurfaceRunInDirectionOfMaxSpread();
    observedSurfaceFireSpreadRate = roundToSixDecimalPlaces(behaveRun.surface.getSpreadRate(SpeedUnits::CHAINS_PER_HOUR));
    expectedSurfaceFireSpreadRate = 0.0;
    BOOST_CHECK_CLOSE(observedSurfaceFireSpreadRate, expectedSurfaceFireSpreadRate, ERROR_TOLERANCE);
}

BOOST_AUTO_TEST_CASE(lengthToWidthRatioTest)
{
    // Observed and expected output
    double observedLengthToWidthRatio = 0.0;
    double expectedLengthToWidthRatio = 0.0;

    double observedCrownLengthToWidthRatio = 0;
    double expectedCrownLengthToWidthRatio = 0;

    setSurfaceInputsForGS4LowMoistureScenario(behaveRun);

    SpeedUnits::SpeedUnitsEnum windSpeedUnits = SpeedUnits::MILES_PER_HOUR;
    WindHeightInputMode::WindHeightInputModeEnum windHeightInputMode = WindHeightInputMode::TWENTY_FOOT;

    // Test North oriented mode, north wind, 0 mph 20 foot wind, 0 degree aspect, 0 degree slope
    behaveRun.surface.setWindHeightInputMode(windHeightInputMode);
    behaveRun.surface.setSlope(0, SlopeUnits::DEGREES);
    behaveRun.surface.setWindAndSpreadOrientationMode(WindAndSpreadOrientationMode::RELATIVE_TO_NORTH);
    behaveRun.surface.setWindSpeed(0, windSpeedUnits, windHeightInputMode);
    behaveRun.surface.setWindDirection(0);
    behaveRun.surface.setAspect(0);
    behaveRun.surface.doSurfaceRunInDirectionOfMaxSpread();
    observedLengthToWidthRatio = roundToSixDecimalPlaces(behaveRun.surface.getFireLengthToWidthRatio());
    expectedLengthToWidthRatio = 1.0;
    BOOST_CHECK_CLOSE(observedLengthToWidthRatio, expectedLengthToWidthRatio, ERROR_TOLERANCE);

    // Test North oriented mode, 45 degree wind, 5 mph 20 foot wind, 95 degree aspect, 30 degree slope
    behaveRun.surface.setWindHeightInputMode(windHeightInputMode);
    behaveRun.surface.setSlope(30, SlopeUnits::DEGREES);
    behaveRun.surface.setWindAndSpreadOrientationMode(WindAndSpreadOrientationMode::RELATIVE_TO_NORTH);
    behaveRun.surface.setWindSpeed(5, windSpeedUnits, windHeightInputMode);
    behaveRun.surface.setWindDirection(45);
    behaveRun.surface.setAspect(95);
    behaveRun.surface.doSurfaceRunInDirectionOfMaxSpread();
    observedLengthToWidthRatio = roundToSixDecimalPlaces(behaveRun.surface.getFireLengthToWidthRatio());
    expectedLengthToWidthRatio = 1.897769;
    BOOST_CHECK_CLOSE(observedLengthToWidthRatio, expectedLengthToWidthRatio, ERROR_TOLERANCE);

    // Test North oriented mode, 45 degree wind, 15 mph 20 foot wind, 95 degree aspect, 30 degree slope
    behaveRun.surface.setWindHeightInputMode(windHeightInputMode);
    behaveRun.surface.setSlope(30, SlopeUnits::DEGREES);
    behaveRun.surface.setWindAndSpreadOrientationMode(WindAndSpreadOrientationMode::RELATIVE_TO_NORTH);
    behaveRun.surface.setWindSpeed(15, windSpeedUnits, windHeightInputMode);
    behaveRun.surface.setWindDirection(45);
    behaveRun.surface.setAspect(95);
    behaveRun.surface.doSurfaceRunInDirectionOfMaxSpread();
    observedLengthToWidthRatio = roundToSixDecimalPlaces(behaveRun.surface.getFireLengthToWidthRatio());
    expectedLengthToWidthRatio = 2.142422;
    BOOST_CHECK_CLOSE(observedLengthToWidthRatio, expectedLengthToWidthRatio, ERROR_TOLERANCE);

    // Test Crown fire length-to-width-ratio
    setCrownInputsLowMoistureScenario(behaveRun);
    behaveRun.crown.doCrownRun();
    expectedCrownLengthToWidthRatio = 1.625;
    observedCrownLengthToWidthRatio = roundToSixDecimalPlaces(behaveRun.crown.getCrownFireLengthToWidthRatio());
    BOOST_CHECK_CLOSE(expectedCrownLengthToWidthRatio, observedCrownLengthToWidthRatio, ERROR_TOLERANCE);

    setCrownInputsLowMoistureScenario(behaveRun);
    behaveRun.crown.setWindSpeed(10, windSpeedUnits, windHeightInputMode);
    behaveRun.crown.doCrownRun();
    expectedCrownLengthToWidthRatio = 2.25;
    observedCrownLengthToWidthRatio = roundToSixDecimalPlaces(behaveRun.crown.getCrownFireLengthToWidthRatio());
    BOOST_CHECK_CLOSE(expectedCrownLengthToWidthRatio, observedCrownLengthToWidthRatio, ERROR_TOLERANCE);

    setCrownInputsLowMoistureScenario(behaveRun);
    behaveRun.crown.setWindSpeed(15, windSpeedUnits, windHeightInputMode);
    behaveRun.crown.doCrownRun();
    expectedCrownLengthToWidthRatio = 2.875;
    observedCrownLengthToWidthRatio = roundToSixDecimalPlaces(behaveRun.crown.getCrownFireLengthToWidthRatio());
    BOOST_CHECK_CLOSE(expectedCrownLengthToWidthRatio, observedCrownLengthToWidthRatio, ERROR_TOLERANCE);
}

BOOST_AUTO_TEST_CASE(ellipticalDimensionTest)
{
    double observedA = 0;
    double observedB = 0;
    double observedC = 0;
    double expectedA = 7.461858;
    double expectedB = 17.824253;
    double expectedC = 16.187176;

    setSurfaceInputsForGS4LowMoistureScenario(behaveRun);
    SpeedUnits::SpeedUnitsEnum spreadRateUnits = SpeedUnits::CHAINS_PER_HOUR;
    // Test fire elliptical dimensions a, b and c (direct mid-flame, upslope mode)
    behaveRun.surface.setWindAndSpreadOrientationMode(WindAndSpreadOrientationMode::RELATIVE_TO_UPSLOPE);
    setSurfaceInputsForGS4LowMoistureScenario(behaveRun);
    behaveRun.surface.setWindHeightInputMode(WindHeightInputMode::DIRECT_MIDFLAME);
    behaveRun.surface.doSurfaceRunInDirectionOfMaxSpread();

    observedA = roundToSixDecimalPlaces(behaveRun.surface.getEllipticalA(spreadRateUnits));
    BOOST_CHECK_CLOSE(observedA, expectedA, ERROR_TOLERANCE);

    observedB = roundToSixDecimalPlaces(behaveRun.surface.getEllipticalB(spreadRateUnits));
    BOOST_CHECK_CLOSE(observedB, expectedB, ERROR_TOLERANCE);

    observedC = roundToSixDecimalPlaces(observedC = behaveRun.surface.getEllipticalC(spreadRateUnits));
    BOOST_CHECK_CLOSE(observedC, expectedC, ERROR_TOLERANCE);
}

BOOST_AUTO_TEST_CASE(directionOfInterestTest)
{
    double directionOfInterest = 0;
    double observedSurfaceFireSpreadRate = 0.0;
    double expectedSurfaceFireSpreadRate = 0.0;

    setSurfaceInputsForGS4LowMoistureScenario(behaveRun);
  
    // Test upslope oriented mode, 20 foot wind, direction of interest 90 degrees from upslope, 45 degree wind
    directionOfInterest = 90;
    behaveRun.surface.setWindHeightInputMode(WindHeightInputMode::TWENTY_FOOT);
    behaveRun.surface.setWindAndSpreadOrientationMode(WindAndSpreadOrientationMode::RELATIVE_TO_UPSLOPE);
    behaveRun.surface.setWindDirection(45);
    behaveRun.surface.doSurfaceRunInDirectionOfInterest(directionOfInterest);
    observedSurfaceFireSpreadRate = roundToSixDecimalPlaces(behaveRun.surface.getSpreadRate(SpeedUnits::CHAINS_PER_HOUR));
    expectedSurfaceFireSpreadRate = 3.016440;
    BOOST_CHECK_CLOSE(observedSurfaceFireSpreadRate, expectedSurfaceFireSpreadRate, ERROR_TOLERANCE);

    // Test upslope oriented mode, 20 foot wind, direction of interest 160 degrees from upslope, 290 degree wind
    directionOfInterest = 160;
    behaveRun.surface.setWindHeightInputMode(WindHeightInputMode::TWENTY_FOOT);
    behaveRun.surface.setWindAndSpreadOrientationMode(WindAndSpreadOrientationMode::RELATIVE_TO_UPSLOPE);
    behaveRun.surface.setWindDirection(290);
    behaveRun.surface.doSurfaceRunInDirectionOfInterest(directionOfInterest);
    observedSurfaceFireSpreadRate = roundToSixDecimalPlaces(behaveRun.surface.getSpreadRate(SpeedUnits::CHAINS_PER_HOUR));
    expectedSurfaceFireSpreadRate = 1.399262;
    BOOST_CHECK_CLOSE(observedSurfaceFireSpreadRate, expectedSurfaceFireSpreadRate, ERROR_TOLERANCE);

    // Test upslope oriented mode, 20 foot wind, direction of interest 215 degrees from upslope, 215 degree wind
    directionOfInterest = 215;
    behaveRun.surface.setWindHeightInputMode(WindHeightInputMode::TWENTY_FOOT);
    behaveRun.surface.setWindAndSpreadOrientationMode(WindAndSpreadOrientationMode::RELATIVE_TO_UPSLOPE);
    behaveRun.surface.setWindDirection(215);
    behaveRun.surface.doSurfaceRunInDirectionOfInterest(directionOfInterest);
    observedSurfaceFireSpreadRate = roundToSixDecimalPlaces(behaveRun.surface.getSpreadRate(SpeedUnits::CHAINS_PER_HOUR));
    expectedSurfaceFireSpreadRate = 1.648579;
    BOOST_CHECK_CLOSE(observedSurfaceFireSpreadRate, expectedSurfaceFireSpreadRate, ERROR_TOLERANCE);
    
    // Test North oriented mode, 20 foot 135 degree wind, direction of interest 30 degrees from north, 263 degree aspect
    directionOfInterest = 30;
    behaveRun.surface.setWindHeightInputMode(WindHeightInputMode::TWENTY_FOOT);
    behaveRun.surface.setWindAndSpreadOrientationMode(WindAndSpreadOrientationMode::RELATIVE_TO_NORTH);
    behaveRun.surface.setWindDirection(280);
    behaveRun.surface.setAspect(135);
    behaveRun.surface.doSurfaceRunInDirectionOfInterest(directionOfInterest);
    observedSurfaceFireSpreadRate = roundToSixDecimalPlaces(behaveRun.surface.getSpreadRate(SpeedUnits::CHAINS_PER_HOUR));
    expectedSurfaceFireSpreadRate = 3.504961;
    BOOST_CHECK_CLOSE(observedSurfaceFireSpreadRate, expectedSurfaceFireSpreadRate, ERROR_TOLERANCE);

    // Test North oriented mode, 20 foot north wind, direction of interest 90 degrees from north, 45 degree aspect
    directionOfInterest = 90;
    behaveRun.surface.setWindHeightInputMode(WindHeightInputMode::TWENTY_FOOT);
    behaveRun.surface.setWindAndSpreadOrientationMode(WindAndSpreadOrientationMode::RELATIVE_TO_NORTH);
    behaveRun.surface.setWindDirection(0);
    behaveRun.surface.setAspect(45);
    behaveRun.surface.doSurfaceRunInDirectionOfInterest(directionOfInterest);
    observedSurfaceFireSpreadRate = roundToSixDecimalPlaces(behaveRun.surface.getSpreadRate(SpeedUnits::CHAINS_PER_HOUR));
    expectedSurfaceFireSpreadRate = 1.803660;
    BOOST_CHECK_CLOSE(observedSurfaceFireSpreadRate, expectedSurfaceFireSpreadRate, ERROR_TOLERANCE);

    // Test North oriented mode, 20 foot 135 degree wind, direction of interest 285 degrees from north, 263 degree aspect
    directionOfInterest = 285;
    behaveRun.surface.setWindHeightInputMode(WindHeightInputMode::TWENTY_FOOT);
    behaveRun.surface.setWindAndSpreadOrientationMode(WindAndSpreadOrientationMode::RELATIVE_TO_NORTH);
    behaveRun.surface.setWindDirection(280);
    behaveRun.surface.setAspect(263);
    behaveRun.surface.doSurfaceRunInDirectionOfInterest(directionOfInterest);
    observedSurfaceFireSpreadRate = roundToSixDecimalPlaces(behaveRun.surface.getSpreadRate(SpeedUnits::CHAINS_PER_HOUR));
    expectedSurfaceFireSpreadRate = 1.452856;
    BOOST_CHECK_CLOSE(observedSurfaceFireSpreadRate, expectedSurfaceFireSpreadRate, ERROR_TOLERANCE);
}

BOOST_AUTO_TEST_CASE(firelineIntensityTest)
{
    double observedFirelineIntensity = 0.0;
    double expectedFirelineIntensity = 598.339039;

    setSurfaceInputsForGS4LowMoistureScenario(behaveRun);

    // Test upslope oriented mode, 20 foot uplsope wind 
    behaveRun.surface.setWindHeightInputMode(WindHeightInputMode::TWENTY_FOOT);
    behaveRun.surface.setWindAndSpreadOrientationMode(WindAndSpreadOrientationMode::RELATIVE_TO_UPSLOPE);
    behaveRun.surface.doSurfaceRunInDirectionOfMaxSpread();
    observedFirelineIntensity = behaveRun.surface.getFirelineIntensity();
    BOOST_CHECK_CLOSE(observedFirelineIntensity, expectedFirelineIntensity, ERROR_TOLERANCE);
}

BOOST_AUTO_TEST_CASE(twoFuelModelsTest)
{
    double observedSurfaceFireSpreadRate = 0.0;
    double expectedSurfaceFireSpreadRate = 0.0;

    // Test upslope oriented mode, 20 foot wind, low moisture conditions
    behaveRun.surface.setWindHeightInputMode(WindHeightInputMode::TWENTY_FOOT);
    setSurfaceInputsForTwoFuelModelsLowMoistureScenario(behaveRun);

    // Do runs for first fuel model coverage 0-100 with step size 10
    behaveRun.surface.setTwoFuelModelsFirstFuelModelCoverage(0);
    behaveRun.surface.doSurfaceRunInDirectionOfMaxSpread();
    observedSurfaceFireSpreadRate = roundToSixDecimalPlaces(behaveRun.surface.getSpreadRate(SpeedUnits::CHAINS_PER_HOUR));
    expectedSurfaceFireSpreadRate = 8.876216;
    BOOST_CHECK_CLOSE(observedSurfaceFireSpreadRate, expectedSurfaceFireSpreadRate, ERROR_TOLERANCE);

    behaveRun.surface.setTwoFuelModelsFirstFuelModelCoverage(10);
    behaveRun.surface.doSurfaceRunInDirectionOfMaxSpread();
    observedSurfaceFireSpreadRate = roundToSixDecimalPlaces(behaveRun.surface.getSpreadRate(SpeedUnits::CHAINS_PER_HOUR));
    expectedSurfaceFireSpreadRate = 10.446373;
    BOOST_CHECK_CLOSE(observedSurfaceFireSpreadRate, expectedSurfaceFireSpreadRate, ERROR_TOLERANCE);

    behaveRun.surface.setTwoFuelModelsFirstFuelModelCoverage(20);
    behaveRun.surface.doSurfaceRunInDirectionOfMaxSpread();
    observedSurfaceFireSpreadRate = roundToSixDecimalPlaces(behaveRun.surface.getSpreadRate(SpeedUnits::CHAINS_PER_HOUR));
    expectedSurfaceFireSpreadRate = 12.112509;
    BOOST_CHECK_CLOSE(observedSurfaceFireSpreadRate, expectedSurfaceFireSpreadRate, ERROR_TOLERANCE);

    behaveRun.surface.setTwoFuelModelsFirstFuelModelCoverage(30);
    behaveRun.surface.doSurfaceRunInDirectionOfMaxSpread();
    observedSurfaceFireSpreadRate = roundToSixDecimalPlaces(behaveRun.surface.getSpreadRate(SpeedUnits::CHAINS_PER_HOUR));
    expectedSurfaceFireSpreadRate = 13.825904;
    BOOST_CHECK_CLOSE(observedSurfaceFireSpreadRate, expectedSurfaceFireSpreadRate, ERROR_TOLERANCE);

    behaveRun.surface.setTwoFuelModelsFirstFuelModelCoverage(40);
    behaveRun.surface.doSurfaceRunInDirectionOfMaxSpread();
    observedSurfaceFireSpreadRate = roundToSixDecimalPlaces(behaveRun.surface.getSpreadRate(SpeedUnits::CHAINS_PER_HOUR));
    expectedSurfaceFireSpreadRate = 15.532700;
    BOOST_CHECK_CLOSE(observedSurfaceFireSpreadRate, expectedSurfaceFireSpreadRate, ERROR_TOLERANCE);

    behaveRun.surface.setTwoFuelModelsFirstFuelModelCoverage(50);
    behaveRun.surface.doSurfaceRunInDirectionOfMaxSpread();
    observedSurfaceFireSpreadRate = roundToSixDecimalPlaces(behaveRun.surface.getSpreadRate(SpeedUnits::CHAINS_PER_HOUR));
    expectedSurfaceFireSpreadRate = 17.173897;
    BOOST_CHECK_CLOSE(observedSurfaceFireSpreadRate, expectedSurfaceFireSpreadRate, ERROR_TOLERANCE);

    behaveRun.surface.setTwoFuelModelsFirstFuelModelCoverage(60);
    behaveRun.surface.doSurfaceRunInDirectionOfMaxSpread();
    observedSurfaceFireSpreadRate = roundToSixDecimalPlaces(behaveRun.surface.getSpreadRate(SpeedUnits::CHAINS_PER_HOUR));
    expectedSurfaceFireSpreadRate = 18.685358;
    BOOST_CHECK_CLOSE(observedSurfaceFireSpreadRate, expectedSurfaceFireSpreadRate, ERROR_TOLERANCE);

    behaveRun.surface.setTwoFuelModelsFirstFuelModelCoverage(70);
    behaveRun.surface.doSurfaceRunInDirectionOfMaxSpread();
    observedSurfaceFireSpreadRate = roundToSixDecimalPlaces(behaveRun.surface.getSpreadRate(SpeedUnits::CHAINS_PER_HOUR));
    expectedSurfaceFireSpreadRate = 19.997806;
    BOOST_CHECK_CLOSE(observedSurfaceFireSpreadRate, expectedSurfaceFireSpreadRate, ERROR_TOLERANCE);

    behaveRun.surface.setTwoFuelModelsFirstFuelModelCoverage(80);
    behaveRun.surface.doSurfaceRunInDirectionOfMaxSpread();
    observedSurfaceFireSpreadRate = roundToSixDecimalPlaces(behaveRun.surface.getSpreadRate(SpeedUnits::CHAINS_PER_HOUR));
    expectedSurfaceFireSpreadRate = 21.036826;
    BOOST_CHECK_CLOSE(observedSurfaceFireSpreadRate, expectedSurfaceFireSpreadRate, ERROR_TOLERANCE);

    behaveRun.surface.setTwoFuelModelsFirstFuelModelCoverage(90);
    behaveRun.surface.doSurfaceRunInDirectionOfMaxSpread();
    observedSurfaceFireSpreadRate = roundToSixDecimalPlaces(behaveRun.surface.getSpreadRate(SpeedUnits::CHAINS_PER_HOUR));
    expectedSurfaceFireSpreadRate = 21.722861;
    BOOST_CHECK_CLOSE(observedSurfaceFireSpreadRate, expectedSurfaceFireSpreadRate, ERROR_TOLERANCE);

    behaveRun.surface.setTwoFuelModelsFirstFuelModelCoverage(100);
    behaveRun.surface.doSurfaceRunInDirectionOfMaxSpread();
    observedSurfaceFireSpreadRate = roundToSixDecimalPlaces(behaveRun.surface.getSpreadRate(SpeedUnits::CHAINS_PER_HOUR));
    expectedSurfaceFireSpreadRate = 21.971217;
    BOOST_CHECK_CLOSE(observedSurfaceFireSpreadRate, expectedSurfaceFireSpreadRate, ERROR_TOLERANCE);
}

BOOST_AUTO_TEST_CASE(crownModuleTest)
{
    double canopyHeight = 30;
    double canopyBaseHeight = 6; 
    double canopyBulkDensity = 0.03;
    
    SpeedUnits::SpeedUnitsEnum windSpeedUnits = SpeedUnits::MILES_PER_HOUR;
    WindHeightInputMode::WindHeightInputModeEnum windHeightInputMode = WindHeightInputMode::TWENTY_FOOT;

    double observedCrownFireSpreadRate = 0;
    double expectedCrownFireSpreadRate = 0;
    double observedCrownFlameLength = 0;
    double expectedCrownFlameLength = 0;
    double observedCrownFirelineIntensity = 0;
    double expectedCrownFirelineIntensity = 0;
    int expectedFireType = (int)FireType::SURFACE;
    int observedFireType = (int)FireType::SURFACE;

    behaveRun.crown.setWindHeightInputMode(WindHeightInputMode::TWENTY_FOOT);

    // Test crown fire spread rate, flame length, intensity
    //setSurfaceInputsForGS4LowMoistureScenario(behaveRun);
    //behaveRun.crown.doSurfaceRunInDirectionOfMaxSpread();
    setCrownInputsLowMoistureScenario(behaveRun);
    behaveRun.crown.doCrownRun();
    expectedCrownFireSpreadRate = 10.259921;
    observedCrownFireSpreadRate = roundToSixDecimalPlaces(behaveRun.crown.getCrownFireSpreadRate(SpeedUnits::CHAINS_PER_HOUR));
    BOOST_CHECK_CLOSE(observedCrownFireSpreadRate, expectedCrownFireSpreadRate, ERROR_TOLERANCE);

    expectedCrownFlameLength = 29.320557;
    observedCrownFlameLength = roundToSixDecimalPlaces(behaveRun.crown.getCrownFlameLength());
    BOOST_CHECK_CLOSE(observedCrownFlameLength, expectedCrownFlameLength, ERROR_TOLERANCE);

    expectedCrownFirelineIntensity = 1775.061222;
    observedCrownFirelineIntensity = roundToSixDecimalPlaces(behaveRun.crown.getCrownFirelineIntensity());
    BOOST_CHECK_CLOSE(observedCrownFirelineIntensity, expectedCrownFirelineIntensity, ERROR_TOLERANCE);

    // Test fire type, Surface fire expected
    setCrownInputsLowMoistureScenario(behaveRun);
    behaveRun.crown.setMoistureOneHour(20, MoistureUnits::PERCENT);
    behaveRun.crown.doCrownRun();
    expectedFireType = (int)FireType::SURFACE;
    observedFireType = (int)behaveRun.crown.getFireType();
    BOOST_CHECK_EQUAL(observedFireType, expectedFireType);

    // Test fire type, Torching fire expected
    setCrownInputsLowMoistureScenario(behaveRun);
    behaveRun.crown.doCrownRun();
    expectedFireType = (int)FireType::TORCHING;
    observedFireType = (int)behaveRun.crown.getFireType();
    BOOST_CHECK_EQUAL(observedFireType, expectedFireType);

    // Test fire type, Crowning fire expected
    setCrownInputsLowMoistureScenario(behaveRun);
    behaveRun.crown.setWindSpeed(10, windSpeedUnits, windHeightInputMode);
    behaveRun.crown.doCrownRun();
    expectedFireType = (int)FireType::CROWNING;
    observedFireType = (int)behaveRun.crown.getFireType();
    BOOST_CHECK_EQUAL(observedFireType, expectedFireType);

    // Test fire type, Conditional crown fire expected
    setCrownInputsLowMoistureScenario(behaveRun);
    canopyHeight = 60;
    behaveRun.crown.setCanopyHeight(canopyHeight, LengthUnits::FEET);
    canopyBaseHeight = 30;
    behaveRun.crown.setCanopyBaseHeight(canopyBaseHeight);
    canopyBulkDensity = 0.06;
    behaveRun.crown.setCanopyBulkDensity(0.06);
    behaveRun.crown.setWindSpeed(5, windSpeedUnits, windHeightInputMode);
    behaveRun.crown.doCrownRun();
    expectedFireType = (int)FireType::CONDITIONAL_CROWN_FIRE;
    observedFireType = (int)behaveRun.crown.getFireType();
    BOOST_CHECK_EQUAL(observedFireType, expectedFireType);
}

BOOST_AUTO_TEST_CASE(spotModuleTest)
{
    double flameLength = 0.0;
    double expectedSpottingDistance = 0.0;
    double observedSpottingDistance = 0.0;

    setSurfaceInputsForGS4LowMoistureScenario(behaveRun);
    behaveRun.surface.setWindHeightInputMode(WindHeightInputMode::TWENTY_FOOT);
    behaveRun.surface.doSurfaceRunInDirectionOfMaxSpread();
    flameLength = behaveRun.surface.getFlameLength(LengthUnits::FEET);

    SpotFireLocation::SpotFireLocationEnum location = SpotFireLocation::RIDGE_TOP;
    double ridgeToValleyDistance = 1.0;
    double ridgeToValleyElevation = 2000.0;
    double downwindCoverHeight = 30.0;
    double windSpeedAtTwentyFeet = 5.0;
    double burningPileflameHeight = 5.0;
    double torchingTrees = 15;
    double DBH = 20;
    double treeHeight = 30;
    SpotTreeSpecies::SpotTreeSpeciesEnum treeSpecies = SpotTreeSpecies::ENGELMANN_SPRUCE;
   
	// Test spotting distance from a burning pile
	expectedSpottingDistance = 0.021330;
	behaveRun.spot.updateSpotInputsForBurningPile(location, ridgeToValleyDistance, ridgeToValleyElevation, downwindCoverHeight, 
		burningPileflameHeight, windSpeedAtTwentyFeet);
	behaveRun.spot.calculateSpottingDistanceFromBurningPile();
	observedSpottingDistance = roundToSixDecimalPlaces(behaveRun.spot.getMaxSpottingDistanceFromBurningPile());
	BOOST_CHECK_CLOSE(observedSpottingDistance, expectedSpottingDistance, ERROR_TOLERANCE);

    // Test spotting distance from surface fire
    expectedSpottingDistance = 0.164401;
	behaveRun.spot.updateSpotInputsForSurfaceFire(location, ridgeToValleyDistance, ridgeToValleyElevation, downwindCoverHeight, 
		flameLength, windSpeedAtTwentyFeet);
    behaveRun.spot.calculateSpottingDistanceFromSurfaceFire();
    observedSpottingDistance = roundToSixDecimalPlaces(behaveRun.spot.getMaxSpottingDistanceFromSurfaceFire());
    BOOST_CHECK_CLOSE(observedSpottingDistance, expectedSpottingDistance, ERROR_TOLERANCE);
    
    // Test spotting distance from torching trees
    expectedSpottingDistance = 0.222396;
	behaveRun.spot.updateSpotInputsForTorchingTrees(location, ridgeToValleyDistance, ridgeToValleyElevation, downwindCoverHeight,
		torchingTrees, DBH, treeHeight, treeSpecies, windSpeedAtTwentyFeet);
    behaveRun.spot.calculateSpottingDistanceFromTorchingTrees();
    observedSpottingDistance = roundToSixDecimalPlaces(behaveRun.spot.getMaxSpottingDistanceFromTorchingTrees());
    BOOST_CHECK_CLOSE(observedSpottingDistance, expectedSpottingDistance, ERROR_TOLERANCE);
}

BOOST_AUTO_TEST_CASE(speedUnitConversionTest)
{
    // Observed and expected output
    double observedSurfaceFireSpreadRate = 0.0;
    double expectedSurfaceFireSpreadRate = 0.0;

    SpeedUnits::SpeedUnitsEnum windSpeedUnits = SpeedUnits::MILES_PER_HOUR;
    WindHeightInputMode::WindHeightInputModeEnum windHeightInputMode = WindHeightInputMode::TWENTY_FOOT;

    setSurfaceInputsForGS4LowMoistureScenario(behaveRun);

    // Test upslope oriented mode, 20 foot uplsope wind
    behaveRun.surface.setFuelModelNumber(124);
    behaveRun.surface.setWindSpeed(5, windSpeedUnits, windHeightInputMode);
    behaveRun.surface.setWindHeightInputMode(WindHeightInputMode::TWENTY_FOOT);
    behaveRun.surface.setWindAndSpreadOrientationMode(WindAndSpreadOrientationMode::RELATIVE_TO_UPSLOPE);
    behaveRun.surface.setWindDirection(0);
    behaveRun.surface.setSlope(30, SlopeUnits::PERCENT);
    behaveRun.surface.setAspect(0);
    behaveRun.surface.doSurfaceRunInDirectionOfMaxSpread();

    // Test surface spread rate in chains per hour
    observedSurfaceFireSpreadRate = roundToSixDecimalPlaces(behaveRun.surface.getSpreadRate(SpeedUnits::CHAINS_PER_HOUR));
    expectedSurfaceFireSpreadRate = 8.876216;
    BOOST_CHECK_CLOSE(observedSurfaceFireSpreadRate, expectedSurfaceFireSpreadRate, ERROR_TOLERANCE);

    // Test surface spread rate in feet per minute
    expectedSurfaceFireSpreadRate = 9.763838;
    observedSurfaceFireSpreadRate = roundToSixDecimalPlaces(behaveRun.surface.getSpreadRate(SpeedUnits::FEET_PER_MINUTE));
    BOOST_CHECK_CLOSE(observedSurfaceFireSpreadRate, expectedSurfaceFireSpreadRate, ERROR_TOLERANCE);

    // Test surface spread rate in kilometers per hour
    expectedSurfaceFireSpreadRate = 0.178561;
    observedSurfaceFireSpreadRate = roundToSixDecimalPlaces(behaveRun.surface.getSpreadRate(SpeedUnits::KILOMETERS_PER_HOUR));
    BOOST_CHECK_CLOSE(observedSurfaceFireSpreadRate, expectedSurfaceFireSpreadRate, ERROR_TOLERANCE);

    // Test surface spread rate in meters per minute
    expectedSurfaceFireSpreadRate = 2.976018;
    observedSurfaceFireSpreadRate = roundToSixDecimalPlaces(behaveRun.surface.getSpreadRate(SpeedUnits::METERS_PER_MINUTE));
    BOOST_CHECK_CLOSE(observedSurfaceFireSpreadRate, expectedSurfaceFireSpreadRate, ERROR_TOLERANCE);

    // Test surface spread rate in meters per second
    expectedSurfaceFireSpreadRate = 0.049600;
    observedSurfaceFireSpreadRate = roundToSixDecimalPlaces(behaveRun.surface.getSpreadRate(SpeedUnits::METERS_PER_SECOND));
    BOOST_CHECK_CLOSE(observedSurfaceFireSpreadRate, expectedSurfaceFireSpreadRate, ERROR_TOLERANCE);

    // Test surface spread rate in miles per hour
    expectedSurfaceFireSpreadRate = 0.110953;
    observedSurfaceFireSpreadRate = roundToSixDecimalPlaces(behaveRun.surface.getSpreadRate(SpeedUnits::MILES_PER_HOUR));
    BOOST_CHECK_CLOSE(observedSurfaceFireSpreadRate, expectedSurfaceFireSpreadRate, ERROR_TOLERANCE);
}

BOOST_AUTO_TEST_CASE(igniteModuleTest)
{
    double moistureOneHour = 6.0;
    double moistureHundredHour = 8.0;
    double airTemperature = 80; // Fahrenheit
    double sunShade = 50.0; // Percent 
    IgnitionFuelBedType::IgnitionFuelBedTypeEnum fuelBedType = IgnitionFuelBedType::DOUGLAS_FIR_DUFF;
    double duffDepth = 6.0; // inches
    LightningCharge::LightningChargeEnum lightningChargeType = LightningCharge::UNKNOWN;

    double observedFirebrandIgnitionProbability = 0;
    double observedLightningIgnitionProbability = 0;
    double expectedFirebrandIgnitionProbability = 0;
    double expectedLightningIgnitionProbability = 0;

    MoistureUnits::MoistureUnitsEnum mositureUnits = MoistureUnits::PERCENT;
    TemperatureUnits::TemperatureUnitsEnum temperatureUnits = TemperatureUnits::FAHRENHEIT;
    CoverUnits::CoverUnitsEnum sunShadeUnits = CoverUnits::PERCENT;
    LengthUnits::LengthUnitsEnum duffDepthUnits = LengthUnits::INCHES;

    expectedFirebrandIgnitionProbability = 0.54831705;
    expectedLightningIgnitionProbability = 0.39362018;

    behaveRun.ignite.updateIgniteInputs(moistureOneHour, moistureHundredHour, mositureUnits, airTemperature,
        temperatureUnits, sunShade, sunShadeUnits, fuelBedType, duffDepth, duffDepthUnits, lightningChargeType);
    observedFirebrandIgnitionProbability = behaveRun.ignite.calculateFirebrandIgnitionProbability(ProbabilityUnits::FRACTION);
    BOOST_CHECK_CLOSE(observedFirebrandIgnitionProbability, expectedFirebrandIgnitionProbability, ERROR_TOLERANCE);

    observedLightningIgnitionProbability = behaveRun.ignite.calculateLightningIgnitionProbability(ProbabilityUnits::FRACTION);
    BOOST_CHECK_CLOSE(expectedLightningIgnitionProbability, observedLightningIgnitionProbability, ERROR_TOLERANCE);

    moistureOneHour = 7.0;
    moistureHundredHour = 9.0;
    airTemperature = 90; // Fahrenheit
    sunShade = 25.0; // Percent 
    fuelBedType = IgnitionFuelBedType::LODGEPOLE_PINE_DUFF;
    duffDepth = 8.0; // inches
    lightningChargeType = LightningCharge::NEGATIVE;

    expectedFirebrandIgnitionProbability = 50.717573;
    expectedLightningIgnitionProbability = 17.931991;

    behaveRun.ignite.updateIgniteInputs(moistureOneHour, moistureHundredHour, mositureUnits, airTemperature,
        temperatureUnits, sunShade, sunShadeUnits, fuelBedType, duffDepth, duffDepthUnits, lightningChargeType);
    observedFirebrandIgnitionProbability = behaveRun.ignite.calculateFirebrandIgnitionProbability(ProbabilityUnits::PERCENT);
    BOOST_CHECK_CLOSE(observedFirebrandIgnitionProbability, expectedFirebrandIgnitionProbability, ERROR_TOLERANCE);

    observedLightningIgnitionProbability = behaveRun.ignite.calculateLightningIgnitionProbability(ProbabilityUnits::PERCENT);
    BOOST_CHECK_CLOSE(expectedLightningIgnitionProbability, observedLightningIgnitionProbability, ERROR_TOLERANCE);
}

BOOST_AUTO_TEST_SUITE_END()  // End BehaveRunTestSuite

#ifndef NDEBUG
BOOST_AUTO_TEST_CASE(waitInDebug)
{
    BOOST_CHECK_EQUAL(0, 0);
    // Make Visual Studio wait while in debug mode
    std::cout << "Press Enter to continue . . .";
    std::cin.get();
}
#endif
