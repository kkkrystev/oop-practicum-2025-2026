#include <iostream>
#include <string>

#include "DeviceFactory.h"

std::optional<std::unique_ptr<Device>> DeviceFactory::createDevice()
{
    std::string type; 
    
    std::cin >> type; 
    
    if (type == "SmartLight") 
        return DeviceFactory::createSmartLight(); 

    if (type == "SmartThermostat") 
        return DeviceFactory::createSmartThermostat(); 
    
    return std::nullopt;
}

std::unique_ptr<Device> DeviceFactory::createSmartLight()
{
    std::string label;
    unsigned brightness, powerWatts;

    std::cin >> label >> brightness >> powerWatts;

    return std::make_unique<SmartLight>(label, brightness, powerWatts);
}

std::unique_ptr<Device> DeviceFactory::createSmartThermostat()
{
    std::string label;
    int minTemperature, maxTemperature;

    std::cin >> label >> minTemperature >> maxTemperature;

    return std::make_unique<SmartThermostat>(label, minTemperature, maxTemperature);
}
