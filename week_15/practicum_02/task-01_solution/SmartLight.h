#pragma once

#include "Device.h"

class SmartLight : public Device
{
public:
	SmartLight(
		const std::string& label, 
		unsigned brightness, 
		unsigned powerWatts
	);
	
	double price() const override;
	void print() const override;

	std::unique_ptr<Device> clone() const override;

private:
	unsigned brightness;
	unsigned powerWatts;
};

