#include <print>

#include "DeviceConfiguration.h"

DeviceConfiguration::DeviceConfiguration(const DeviceConfiguration& other)
{
    copyFrom(other);
}

DeviceConfiguration& DeviceConfiguration::operator=(const DeviceConfiguration& other) 
{
    if (this != &other) {
        free();
        copyFrom(other);
    }
    return *this;
}

void DeviceConfiguration::add(std::unique_ptr<Device> device)
{
    if (!device)
        throw std::invalid_argument("DeviceConfiguration::add: null device");
    devices.push_back(std::move(device));
}

double DeviceConfiguration::totalPrice() const 
{
    double total = 0.0;
    for (const auto& d : devices) {
        total += d->price();
    }
    return total;
}

const Device* DeviceConfiguration::findWhere(std::function<bool(const Device&)> predicate) const
{
    for (const auto& d : devices) {
        if (predicate(*d)) {
            return d.get();
        }
    }
    return nullptr;
}

void DeviceConfiguration::print() const {
    std::print("DeviceConfiguration ({} device(s)):\n", devices.size());

    for (size_t i = 0; i < devices.size(); ++i) {
        std::print("[{}]", i);
        devices[i]->print();
    }

    std::print("Total price: {}\n", totalPrice());
}

void DeviceConfiguration::free()
{
    devices.clear();
}

void DeviceConfiguration::copyFrom(const DeviceConfiguration& other)
{
    devices.reserve(other.devices.size());

    for (const auto& d : other.devices) {
        devices.push_back(d->clone());
    }
}
