/******************************************************************************
*
* Project:  CodeBlocks
* Purpose:  A collection of units conversion functions and enums
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

#ifndef	BEHAVEUNITS_H
#define BEHAVEUNITS_H

struct LengthUnits
{
    enum LengthUnitsEnum
    {
        FEET, // base length unit
        INCHES,
        CENTIMETERS,
        METERS,				
        MILES,
        KILOMETERS
    };

    static double toBaseUnits(double value, LengthUnitsEnum units);
    static double fromBaseUnits(double value, LengthUnitsEnum units);
};

struct LoadingUnits
{
    enum LoadingUnitsEnum
    {
        POUNDS_PER_SQUARE_FOOT, // base loading unit
        TONS_PER_ACRE,
        TONNES_PER_HECTARE,
        KILOGRAMS_PER_SQUARE_METER
    };

    static double toBaseUnits(double value, LoadingUnitsEnum units);
    static double fromBaseUnits(double value, LoadingUnitsEnum units);
};

struct SurfaceAreaToVolumeUnits
{
    enum SurfaceAreaToVolumeUnitsEnum
    {
        SQUARE_FEET_OVER_CUBIC_FEET, // base loading unit
        SQUARE_METERS_OVER_CUBIC_METERS,
        SQUARE_INCHES_OVER_CUBIC_INCHES,
        SQUARE_CENTIMETERS_OVER_CUBIC_CENTIMERS
    };

    static double toBaseUnits(double value, SurfaceAreaToVolumeUnitsEnum units);
    static double fromBaseUnits(double value, SurfaceAreaToVolumeUnitsEnum units);
};


struct SpeedUnits 
{
    enum SpeedUnitsEnum
    {
        FEET_PER_MINUTE, // base velocity unit
        CHAINS_PER_HOUR,
        METERS_PER_SECOND,	
        METERS_PER_MINUTE,
        MILES_PER_HOUR,
        KILOMETERS_PER_HOUR
    };

    static double toBaseUnits(double value, SpeedUnitsEnum units);
    static double fromBaseUnits(double value, SpeedUnitsEnum units);
};

struct CoverUnits
{
    enum CoverUnitsEnum
    {
        FRACTION, // base cover unit
        PERCENT
    };

    static double toBaseUnits(double value, CoverUnitsEnum units);
    static double fromBaseUnits(double value, CoverUnitsEnum units);
};

struct ProbabilityUnits
{
    enum ProbabilityUnitsEnum
    {
        FRACTION, // base cover unit
        PERCENT
    };

    static double toBaseUnits(double value, ProbabilityUnitsEnum units);
    static double fromBaseUnits(double value, ProbabilityUnitsEnum units);
};


struct MoistureUnits
{
    enum MoistureUnitsEnum
    {
        FRACTION, // base cover unit
        PERCENT
    };

    static double toBaseUnits(double value, MoistureUnitsEnum units);
    static double fromBaseUnits(double value, MoistureUnitsEnum units);
};

struct SlopeUnits
{
    enum SlopeUnitsEnum
    {			   
        DEGREES, // base slope unit
        PERCENT
    };

    static double toBaseUnits(double value, SlopeUnitsEnum units);
    static double fromBaseUnits(double value, SlopeUnitsEnum units);
};

struct DensityUnits
{
    enum DensityUnitsEnum
    {
        POUNDS_PER_CUBIC_FOOT, // base density unit
        KILOGRAMS_PER_CUBIC_METER
    };

    static double toBaseUnits(double value, DensityUnitsEnum units);
    static double fromBaseUnits(double value, DensityUnitsEnum units);
};

struct TemperatureUnits
{
    enum TemperatureUnitsEnum
    {
        FAHRENHEIT, // base temperature unit
        CELSIUS,
        KELVIN
    };

    static double toBaseUnits(double value, TemperatureUnitsEnum units);
    static double fromBaseUnits(double value, TemperatureUnitsEnum units);
};

#endif // BEHAVEUNITS_H
