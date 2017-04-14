/******************************************************************************
*
* Project:  CodeBlocks
* Purpose:  Class for handling the inputs required for surface fire behavior
*           in the Rothermel Model
* Author:   William Chatham <wchatham@fs.fed.us>
*
*******************************************************************************
*
* THIS SOFTWARE WAS DEVELOPED AT THE ROCKY MOUNTAIN RESEARCH STATION (RMRS)
* MISSOULA FIRE SCIENCES LABORATORY BY EMPLOYEES OF THE FEDERAL GOVERNMENT
* IN THE COURSE OF THEIR OFFICIAL DUTIES. PURSUANT TO TITLE 17 SECTION 105
* OF THE UNITED STATES CODE, THIS SOFTWARE IS NOT SUBJECT TO COPYRIGHT
* PROTECTION AND IS IN THE PUBLIC DOMAIN. RMRS MISSOULA FIRE SCIENCES
* LABORATORY ASSUMES NO RESPONSIBILITY WHATSOEVER FOR ITS USE BY OTHER
* PARTIES,  AND MAKES NO GUARANTEES, EXPRESSED OR IMPLIED, ABOUT ITS QUALITY,
* RELIABILITY, OR ANY OTHER CHARACTERISTIC.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
* OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
* THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
* FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
* DEALINGS IN THE SOFTWARE.
*
******************************************************************************/

#ifndef SURFACEINPUTS_H
#define SURFACEINPUTS_H

#include "behaveUnits.h"
#include "surfaceEnums.h"

class SurfaceInputs
{
public:
    SurfaceInputs();
  
    // Main Surface module inputs setters 
    void updateSurfaceInputs(int fuelModelNumber, double moistureOneHour, double moistureTenHour, double moistureHundredHour,
        double moistureLiveHerbaceous, double moistureLiveWoody, MoistureUnits::MoistureUnitsEnum moistureUnits, double windSpeed,
        SpeedUnits::SpeedUnitsEnum windSpeedUnits, double windDirection, WindHeightInputMode::WindHeightInputModeEnum windHeightInputMode, 
        double slope, SlopeUnits::SlopeUnitsEnum slopeUnits, double aspect, double canopyCover, double canopyHeight, 
        LengthUnits::LengthUnitsEnum canopyHeightUnits, double crownRatio);
    void setFuelModelNumber(int fuelModelNumber);
    void setMoistureOneHour(double moistureOneHour, MoistureUnits::MoistureUnitsEnum moistureUnits);
    void setMoistureTenHour(double moistureTenHour, MoistureUnits::MoistureUnitsEnum moistureUnits);
    void setMoistureHundredHour(double moistureHundredHour, MoistureUnits::MoistureUnitsEnum moistureUnits);
    void setMoistureLiveHerbaceous(double moistureLiveHerbaceous, MoistureUnits::MoistureUnitsEnum moistureUnits);
    void setMoistureLiveWoody(double moistureLiveWoody, MoistureUnits::MoistureUnitsEnum moistureUnits);
    void setSlope(double slope, SlopeUnits::SlopeUnitsEnum slopeUnits);
    void setAspect(double aspect);
    void setFlameLengthUnits(LengthUnits::LengthUnitsEnum flameLengthUnits);
    void setSlopeUnits(SlopeUnits::SlopeUnitsEnum slopeUnits);
    void setWindSpeed(double windSpeed, SpeedUnits::SpeedUnitsEnum windSpeedUnits);
    void setSpreadRateUnits(SpeedUnits::SpeedUnitsEnum spreadRateUnits);
    void setWindDirection(double windDirection);
    void setWindAndSpreadOrientationMode(WindAndSpreadOrientationMode::WindAndSpreadOrientationModeEnum windAndSpreadOrientationMode);
    void setWindHeightInputMode(WindHeightInputMode::WindHeightInputModeEnum windHeightInputMode);
    void setCoverUnits(CoverUnits::CoverUnitsEnum coverUnits);
    void setCanopyCover(double canopyCover);
    void setCanopyHeight(double canopyHeight, LengthUnits::LengthUnitsEnum canopyHeightUnits);
    void setCrownRatio(double crownRatio);
    void setUserProvidedWindAdjustmentFactor(double userProvidedWindAdjustmentFactor);
    void setWindAdjustmentFactorCalculationMethod(WindAdjustmentFactorCalculationMethod::WindAdjustmentFactorCalculationMethodEnum windAdjustmentFactorCalculationMethod);

    // Main Surface module inputs getters 
    int getFuelModelNumber() const;
    double getMoistureOneHour(MoistureUnits::MoistureUnitsEnum moistureUnits) const;
    double getMoistureTenHour(MoistureUnits::MoistureUnitsEnum moistureUnits) const;
    double getMoistureHundredHour(MoistureUnits::MoistureUnitsEnum moistureUnits) const;
    double getMoistureLiveHerbaceous(MoistureUnits::MoistureUnitsEnum moistureUnits) const;
    double getMoistureLiveWoody(MoistureUnits::MoistureUnitsEnum moistureUnits) const;
    double getWindSpeed() const;
    double getWindDirection() const;
    double getSlope() const;
    double getAspect() const;
    double getCanopyCover() const;
    double getCanopyHeight() const;
    double getCrownRatio() const;
    WindAndSpreadOrientationMode::WindAndSpreadOrientationModeEnum getWindAndSpreadOrientationMode() const;
    WindHeightInputMode::WindHeightInputModeEnum getWindHeightInputMode() const;
    SlopeUnits::SlopeUnitsEnum getSlopeUnits() const;
    SpeedUnits::SpeedUnitsEnum getSpreadRateUnits() const;
    LengthUnits::LengthUnitsEnum getFlameLengthUnits() const;
    CoverUnits::CoverUnitsEnum getCoverUnits() const;
    double getUserProvidedWindAdjustmentFactor() const;
    WindAdjustmentFactorCalculationMethod::WindAdjustmentFactorCalculationMethodEnum getWindAdjustmentFactorCalculationMethod() const;

    // Two fuel models inputs setters
    void updateSurfaceInputsForTwoFuelModels(int firstfuelModelNumber, int secondFuelModelNumber, double moistureOneHour,
        double moistureTenHour, double moistureHundredHour, double moistureLiveHerbaceous, double moistureLiveWoody, 
        MoistureUnits::MoistureUnitsEnum moistureUnits, double windSpeed, SpeedUnits::SpeedUnitsEnum windSpeedUnits, 
        double windDirection, WindHeightInputMode::WindHeightInputModeEnum windHeightInputMode, double firstFuelModelCoverage,
        TwoFuelModels::TwoFuelModelsEnum twoFuelModelsMethod, double slope, SlopeUnits::SlopeUnitsEnum slopeUnits, double aspect, 
        double canopyCover, double canopyHeight, LengthUnits::LengthUnitsEnum canopyHeightUnits, double crownRatio);
    void setFirstFuelModelNumber(int firstFuelModelNumber);
    void setSecondFuelModelNumber(int secondFuelModelNumber);
    void setTwoFuelModelsMethod(TwoFuelModels::TwoFuelModelsEnum twoFuelModelsMethod);
    void setTwoFuelModelsFirstFuelModelCoverage(double firstFuelModelCoverage);

    // Two fuel models inputs getters
    bool isUsingTwoFuelModels() const;
    TwoFuelModels::TwoFuelModelsEnum getTwoFuelModelsMethod() const;
    int getFirstFuelModelNumber() const;
    int getSecondFuelModelNumber() const;
    double getFirstFuelModelCoverage() const;

    // Palmetto-Gallberry inputs setters
    void updateSurfaceInputsForPalmettoGallbery(double moistureOneHour, double moistureTenHour, double moistureHundredHour,
        double moistureLiveHerbaceous, double moistureLiveWoody, MoistureUnits::MoistureUnitsEnum moistureUnits, double windSpeed, 
        SpeedUnits::SpeedUnitsEnum windSpeedUnits, double windDirection, WindHeightInputMode::WindHeightInputModeEnum windHeightInputMode, 
        double ageOfRough, double heightOfUnderstory, double palmettoCoverage, double overstoryBasalArea, double slope, 
        SlopeUnits::SlopeUnitsEnum slopeUnits, double aspect, double canopyCover, double canopyHeight, 
        LengthUnits::LengthUnitsEnum canopyHeightUnits, double crownRatio);
    void setAgeOfRough(double ageOfRough);
    void setHeightOfUnderstory(double heightOfUnderstory);
    void setPalmettoCoverage(double palmettoCoverage);
    void setOverstoryBasalArea(double overstoryBasalArea);
   
    // Palmetto-Gallberry getters
    double getAgeOfRough() const;
    double getHeightOfUnderstory() const;
    double getPalmettoCoverage() const;
    double getOverstoryBasalArea() const;
    bool isUsingPalmettoGallberry() const;

    // Westerm Aspen inputs setters
    void updateSurfaceInputsForWesternAspen(int aspenFuelModelNumber, double aspenCuringLevel,
        AspenFireSeverity::AspenFireSeverityEnum aspenFireSeverity, double DBH, double moistureOneHour, double moistureTenHour,
        double moistureHundredHour, double moistureLiveHerbaceous, double moistureLiveWoody, MoistureUnits::MoistureUnitsEnum moistureUnits, 
        double windSpeed, SpeedUnits::SpeedUnitsEnum windSpeedUnits, double windDirection, WindHeightInputMode::WindHeightInputModeEnum windHeightInputMode, 
        double slope, SlopeUnits::SlopeUnitsEnum slopeUnits, double aspect, double canopyCover, double canopyHeight, 
        LengthUnits::LengthUnitsEnum canopyHeightUnits, double crownRatio);
    void setAspenFuelModelNumber(int aspenFuelModelNumber);
    void setAspenCuringLevel(double aspenCuringLevel);
    void setAspenDBH(double DBH);
    void setAspenFireSeverity(AspenFireSeverity::AspenFireSeverityEnum aspenFireSeverity);

    // Western Aspen getters
    bool isUsingWesternAspen() const;
    int getAspenFuelModelNumber() const;
    double getAspenCuringLevel() const;
    double getAspenDBH() const;
    AspenFireSeverity::AspenFireSeverityEnum getAspenFireSeverity() const;

private:
    void initializeMembers();
   
    // Main Suface module inputs
    int fuelModelNumber_;               // 1 to 256
    double moistureOneHour_;            // 1% to 60%
    double moistureTenHour_;            // 1% to 60%		
    double moistureHundredHour_;        // 1% to 60%
    double moistureLiveHerbaceous_;     // 30% to 300%
    double moistureLiveWoody_;          // 30% to 300%
    double windSpeed_;                  // measured wind speed in feet per minute
    double windDirection_;              // degrees, 0-360
    double slope_;                      // gradient 0-600 or degrees 0-80  
    double aspect_;                     // aspect of slope in degrees, 0-360

    // Two Fuel Models inputs
    bool isUsingTwoFuelModels_;         // Whether fire spread calculation is using Two Fuel Models
    int secondFuelModelNumber_;         // 1 to 256, second fuel used in Two Fuel Models
    double firstFuelModelCoverage_;     // percent of landscape occupied by first fuel in Two Fuel Models

    // Palmetto-Gallberry inputs
    bool isUsingPalmettoGallberry_;
    double ageOfRough_;
    double heightOfUnderstory_;
    double palmettoCoverage_;
    double overstoryBasalArea_;

    // Western Aspen inputs
    bool isUsingWesternAspen_;
    int aspenFuelModelNumber_;
    double aspenCuringLevel_;
    double DBH_;
    AspenFireSeverity::AspenFireSeverityEnum aspenFireSeverity_;

    // Wind Adjustment Factor Parameters
    double canopyCover_;
    double canopyHeight_;
    double crownRatio_;
    double userProvidedWindAdjustmentFactor_;

    // Input Modes
    CoverUnits::CoverUnitsEnum coverUnits_;
    LengthUnits::LengthUnitsEnum flameLengthUnits_;
    SlopeUnits::SlopeUnitsEnum slopeUnits_;
    SpeedUnits::SpeedUnitsEnum spreadRateUnits_;
    TwoFuelModels::TwoFuelModelsEnum twoFuelModelsMethod_;              
    WindHeightInputMode::WindHeightInputModeEnum windHeightInputMode_;  
    WindAndSpreadOrientationMode::WindAndSpreadOrientationModeEnum windAndSpreadOrientationMode_;
    WindAdjustmentFactorCalculationMethod::WindAdjustmentFactorCalculationMethodEnum windAdjustmentFactorCalculationMethod_;
};

#endif // SURFACEINPUTS_H
