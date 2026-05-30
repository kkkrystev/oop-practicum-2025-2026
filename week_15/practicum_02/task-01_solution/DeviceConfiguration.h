#pragma once

#include <optional>
#include <functional>
#include <memory>
#include <vector>

#include "Device.h"

class DeviceConfiguration
{
public:
	DeviceConfiguration() = default;
	~DeviceConfiguration() = default;

	DeviceConfiguration(const DeviceConfiguration& other);
	DeviceConfiguration& operator=(const DeviceConfiguration& other);

	void add(std::unique_ptr<Device> device); 
	double totalPrice() const;
	const Device* findWhere(std::function<bool(const Device&)> predicate) const;
	void print() const;

	const Device& operator[](size_t i) const;
	Device& operator[](size_t i);

private:
	void free();
	void copyFrom(const DeviceConfiguration& other);

	std::vector<std::unique_ptr<Device>> devices;
};

