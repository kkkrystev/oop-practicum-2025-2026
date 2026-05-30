#pragma once

#include <memory>
#include <optional>

#include "Device.h"
#include "SmartLight.h"
#include "SmartThermostat.h"

class DeviceFactory
{
public:
	static std::optional<std::unique_ptr<Device>> createDevice();

	static std::unique_ptr<Device> createSmartLight();
	static std::unique_ptr<Device> createSmartThermostat();
};

