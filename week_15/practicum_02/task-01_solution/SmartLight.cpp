#include <stdexcept>
#include <print>

#include "SmartLight.h"

SmartLight::SmartLight(
    const std::string& label, 
    unsigned brightness, 
    unsigned powerWatts) 
    : Device(label), brightness(brightness), powerWatts(powerWatts) 
{
    if (brightness < 1 || brightness > 100)
        throw std::invalid_argument("Invalid brightness\n");

    if (powerWatts < 1 || powerWatts > 200)
        throw std::invalid_argument("Invalid powerWatts\n");
}

double SmartLight::price() const
{
    return brightness * 0.5 + powerWatts * 1.25;
}

void SmartLight::print() const
{
    std::print("SmartLight: {} | brightness: {} | powerWatts: {} | price: {}\n", 
        label, 
        brightness, 
        powerWatts, 
        price()
    );
}

std::unique_ptr<Device> SmartLight::clone() const
{
    return std::make_unique<SmartLight>(*this);
}
