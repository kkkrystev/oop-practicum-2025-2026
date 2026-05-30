#pragma once

#include "Device.h"

class SmartThermostat : public Device
{
public:
	SmartThermostat(const std::string& label, int minTemp, int maxTemp);

	double price() const override;
	void print() const override;

	std::unique_ptr<Device> clone() const override;

private:
	int minTemperature, maxTemperature;		
};

