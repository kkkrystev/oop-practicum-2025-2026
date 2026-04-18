#include "CarDealership.h"
#include <iostream>
#include <cstring>

#pragma warning(disable : 4996)

void CarDealership::setName(const char* name)
{
    delete[] this->name;

    if (!name)
    {
        this->name = new char[1];
        this->name[0] = '\0';
        return;
    }

    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
}

void CarDealership::copyFrom(const CarDealership& other)
{
    if (other.name)
    {
        name = new char[strlen(other.name) + 1];
        strcpy(name, other.name);
    }
    else
    {
        name = new char[1];
        name[0] = '\0';
    }

    size = other.size;
    capacity = other.capacity;
    cars = new Car[capacity];

    for (size_t i = 0; i < size; i++)
    {
        cars[i] = other.cars[i];
    }
}

void CarDealership::moveFrom(CarDealership&& other)
{
    name = other.name;
    cars = other.cars;
    size = other.size;
    capacity = other.capacity;

    other.name = nullptr;
    other.cars = nullptr;
    other.size = 0;
    other.capacity = 0;
}

void CarDealership::free()
{
    delete[] name;
    delete[] cars;

    name = nullptr;
    cars = nullptr;
    size = 0;
    capacity = 0;
}

void CarDealership::resize()
{
    if (capacity >= size)
        capacity *= 2;


    Car* newCars = new Car[capacity];

    for (size_t i = 0; i < size; i++)
    {
        newCars[i] = std::move(cars[i]);
    }

    delete[] cars;
    cars = newCars;
}

CarDealership::CarDealership()
{
    name = new char[1];
    name[0] = '\0';
    cars = nullptr;
    size = 0;
    capacity = 8;
}

CarDealership::CarDealership(const char* name)
{
    this->name = nullptr;
    setName(name);
    cars = nullptr;
    size = 0;
    capacity = 8;
}

CarDealership::CarDealership(const CarDealership& other)
{
    copyFrom(other);
}

CarDealership& CarDealership::operator=(const CarDealership& other)
{
    if (this != &other)
    {
        free();
        copyFrom(other);
    }
    return *this;
}

CarDealership::CarDealership(CarDealership&& other) noexcept
{
    moveFrom(std::move(other));
}

CarDealership& CarDealership::operator=(CarDealership&& other) noexcept
{
    if (this != &other)
    {
        free();
        moveFrom(std::move(other));
    }
    return *this;
}

CarDealership::~CarDealership()
{
    free();
}

void CarDealership::addCar(const Car& car)
{
    if (size >= capacity)
        resize();

    cars[size++] = car;
}

void CarDealership::addCar(Car&& car)
{
    if (size >= capacity)
        resize();

    cars[size++] = std::move(car);
}

bool CarDealership::removeCarById(unsigned id)
{
    for (size_t i = 0; i < size; i++)
    {
        if (cars[i].getId() == id)
        {
            for (size_t j = i; j < size - 1; j++)
            {
                cars[j] = std::move(cars[j + 1]);
            }
            size--;
            return true;
        }
    }

    return false;
}

Car* CarDealership::findCarById(unsigned id)
{
    for (size_t i = 0; i < size; i++)
    {
        if (cars[i].getId() == id)
            return &cars[i];
    }

    return nullptr;
}

const Car* CarDealership::findCarById(unsigned id) const
{
    for (size_t i = 0; i < size; i++)
    {
        if (cars[i].getId() == id)
            return &cars[i];
    }

    return nullptr;
}

void CarDealership::printAll() const
{
    std::cout << "Dealership: " << name << '\n';
    std::cout << "Cars count: " << size << "\n\n";

    for (size_t i = 0; i < size; i++)
    {
        cars[i].print();
        std::cout << '\n';
    }
}

void CarDealership::printCarsByBrand(const char* brand) const
{
    if (!brand)
        return;

    bool found = false;
    for (size_t i = 0; i < size; i++)
    {
        if (strcmp(cars[i].getBrand(), brand) == 0)
        {
            cars[i].print();
            std::cout << '\n';
            found = true;
        }
    }

    if (!found)
    {
        std::cout << "No cars from this brand.\n";
    }
}

double CarDealership::getAveragePrice() const
{
    if (size == 0)
        return 0.0;

    double sum = 0.0;
    for (size_t i = 0; i < size; i++)
    {
        sum += cars[i].getPrice();
    }

    return sum / size;
}

bool CarDealership::sellCar(unsigned id)
{
    return removeCarById(id);
}

const char* CarDealership::getName() const
{
    return name;
}

size_t CarDealership::getSize() const
{
    return size;
}