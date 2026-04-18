#pragma once
#include "Car.h"
#include <iostream>

class CarDealership
{
private:
    char* name;
    Car* cars;
    size_t size;
    size_t capacity = 8;

    void copyFrom(const CarDealership& other);
    void moveFrom(CarDealership&& other);
    void free();
    void resize();

public:
    CarDealership();
    CarDealership(const char* name);

    CarDealership(const CarDealership& other);
    CarDealership& operator=(const CarDealership& other);

    CarDealership(CarDealership&& other) noexcept;
    CarDealership& operator=(CarDealership&& other) noexcept;

    ~CarDealership();

    void addCar(const Car& car);
    void addCar(Car&& car);

    bool removeCarById(unsigned id);
    Car* findCarById(unsigned id);
    const Car* findCarById(unsigned id) const;

    void printAll() const;
    void printCarsByBrand(const char* brand) const;
    double getAveragePrice() const;
    bool sellCar(unsigned id);

    void setName(const char* name);
    const char* getName() const;
    size_t getSize() const;
};