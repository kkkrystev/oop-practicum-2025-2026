#pragma once
#include <string>
#include <memory>

class Device
{
public:
	Device(const std::string& label);
	virtual ~Device() = default;

	const std::string& getLabel() const;
	virtual double price() const = 0;
	virtual void print() const = 0;

	virtual std::unique_ptr<Device> clone() const = 0;

protected:
	std::string label;
};