#include <print>

#include "SmartThermostat.h"

SmartThermostat::SmartThermostat(const std::string& label, int minTemp, int maxTemp)
	: Device(label), minTemperature(minTemp), maxTemperature(maxTemp) 
{
	if (minTemperature < -30 || minTemperature > 50) { 
		throw std::invalid_argument("Invalid min temperature"); 
	} 
	if (maxTemperature < -30 || maxTemperature > 50) { 
		throw std::invalid_argument("Invalid max temperature"); 
	} 
	if (minTemperature >= maxTemperature) { 
		throw std::invalid_argument("Invalid temperature range"); 
	}
}

double SmartThermostat::price() const
{
	return 100 + (maxTemperature - minTemperature) * 5;
}


void SmartThermostat::print() const
{
	std::print("SmartThermostat: {} | minTemperature: {} | maxTemperature: {} | price: {}\n", 
		label, 
		minTemperature, 
		maxTemperature, 
		price());
}

std::unique_ptr<Device> SmartThermostat::clone() const
{
	return std::make_unique<SmartThermostat>(*this);
}