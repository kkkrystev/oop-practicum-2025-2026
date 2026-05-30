#include "Device.h"

Device::Device(const std::string& label)
	: label(label) { }

const std::string& Device::getLabel() const
{
	return label;
}

