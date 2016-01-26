#include "surface.h"

Surface::Surface(const FuelModels& fuelModels, SurfaceInputs& surfaceInputs)
	// Surface Module initialiazation list
		: surfaceFuelbedIntermediates_{ fuelModels, surfaceInputs },
		surfaceFireSpread_{surfaceFuelbedIntermediates_, surfaceInputs}
{
	fuelModels_ = &fuelModels;
	surfaceInputs_ = &surfaceInputs;
}

double Surface::calculateSurfaceFireForwardSpreadRate(double directionOfInterest)
{
	double spreadRate = 0.0;

	// Make sure inputs are within valid ranges
	validateInputs();
	// Calculate fuel bed intermediates
	surfaceFuelbedIntermediates_.calculateFuelbedIntermediates();
	// Calculate spread rate
	spreadRate = surfaceFireSpread_.calculateForwardSpreadRate(directionOfInterest);
	// Return results
	return spreadRate;
}

double Surface::calculateSpreadRateAtVector(double directionOfinterest)
{
	return surfaceFireSpread_.calculateSpreadRateAtVector(directionOfinterest);
}

double Surface::getDirectionOfMaxSpread() const
{
	double directionOfMaxSpread = surfaceFireSpread_.getDirectionOfMaxSpread();
	return directionOfMaxSpread;
}

double Surface::getFlameLength() const
{
	return surfaceFireSpread_.getFlameLength();
}

double Surface::getFireLengthToWidthRatio() const
{
	return surfaceFireSpread_.getFireLengthToWidthRatio();
}

double Surface::getFireEccentricity() const
{
	return surfaceFireSpread_.getFireEccentricity();
}

void Surface::validateInputs()
{
	const int MINIMUM_FUEL_MODEL_NUMBER = 1;
	const int MAXIMUM_FUEL_MODEL_NUMBER = 255;

	int myFuelModelNumber = surfaceInputs_->getFuelModelNumber();
	if (myFuelModelNumber < MINIMUM_FUEL_MODEL_NUMBER || myFuelModelNumber > MAXIMUM_FUEL_MODEL_NUMBER)
	{
		// TODO: Add proper error handling
		surfaceInputs_->setFuelModelNumber(0); // prevent access out of index bounds
		// Using Fuel Model Zero indicates and error
	}

	double myWindSpeed = surfaceInputs_->getMidflameWindSpeed();
	if (myWindSpeed < 0)
	{
		surfaceInputs_->setMidflameWindSpeed(0); // can't have negative wind speed
	}

	// This section exists only to facilate automated testing with the same set
	// of input values, making it necessary only to increment the fuel model
	// and still have valid data for that fuel models - WMC - 11/2015
	if (fuelModels_->getFuelLoadOneHour(myFuelModelNumber) == 0)
	{
		surfaceInputs_->setMoistureOneHour(0);
	}
	if (fuelModels_->getFuelLoadTenHour(myFuelModelNumber) == 0)
	{
		surfaceInputs_->setMoistureTenHour(0);
	}
	if (fuelModels_->getFuelLoadHundredHour(myFuelModelNumber) == 0)
	{
		surfaceInputs_->setMoistureHundredHour(0);
	}
	if (fuelModels_->getFuelLoadLiveHerbaceous(myFuelModelNumber) == 0)
	{
		surfaceInputs_->setMoistureLiveHerbaceous(0);
	}
	if (fuelModels_->getFuelLoadLiveWoody(myFuelModelNumber) == 0)
	{
		surfaceInputs_->setMoistureLiveWoody(0);
	}
}