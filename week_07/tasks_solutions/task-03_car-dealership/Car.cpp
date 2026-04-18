#include "Car.h"
#include <iostream>
#include <cstring>
#pragma warning(disable : 4996)

unsigned Car::idGenerator = 1;

void Car::setString(char* dest, const char* src)
{
    delete[] dest;

    if (!src)
    {
        dest = new char[1];
        dest[0] = '\0';
        return;
    }

    dest = new char[strlen(src) + 1];
    strcpy(dest, src);
}

void Car::copyFrom(const Car& other)
{
    year = other.year;
    price = other.price;
    featuresCount = other.featuresCount;

    if (other.brand)
    {
        brand = new char[strlen(other.brand) + 1];
        strcpy(brand, other.brand);
    }
    else
    {
        brand = new char[1];
        brand[0] = '\0';
    }

    if (other.model)
    {
        model = new char[strlen(other.model) + 1];
        strcpy(model, other.model);
    }
    else
    {
        model = new char[1];
        model[0] = '\0';
    }

    if (featuresCount == 0)
    {
        features = nullptr;
        return;
    }

    features = new char* [featuresCount];
    for (size_t i = 0; i < featuresCount; i++)
    {
        features[i] = new char[strlen(other.features[i]) + 1];
        strcpy(features[i], other.features[i]);
    }
}

void Car::moveFrom(Car&& other)
{
    id = other.id;
    brand = other.brand;
    model = other.model;
    year = other.year;
    price = other.price;
    features = other.features;
    featuresCount = other.featuresCount;

    other.id = 0;
    other.brand = nullptr;
    other.model = nullptr;
    other.year = 0;
    other.price = 0.0;
    other.features = nullptr;
    other.featuresCount = 0;
}

void Car::free()
{
    delete[] brand;
    delete[] model;

    for (size_t i = 0; i < featuresCount; i++)
    {
        delete[] features[i];
    }
    delete[] features;

    brand = nullptr;
    model = nullptr;
    features = nullptr;
    featuresCount = 0;
    year = 0;
    price = 0.0;
    id = 0;
}

Car::Car()
{
    id = idGenerator++;
    brand = new char[1];
    brand[0] = '\0';

    model = new char[1];
    model[0] = '\0';

    year = 0;
    price = 0.0;
    features = nullptr;
    featuresCount = 0;
}

Car::Car(const char* brand, const char* model, unsigned year, double price)
{
    id = idGenerator++;
    this->brand = nullptr;
    this->model = nullptr;

    setString(this->brand, brand);
    setString(this->model, model);

    this->year = year;
    this->price = price;
    this->features = nullptr;
    this->featuresCount = 0;
}

Car::Car(const Car& other)
{
    id = idGenerator++;
    copyFrom(other);
}

Car& Car::operator=(const Car& other)
{
    if (this != &other)
    {
        free();
        copyFrom(other);
    }
    return *this;
}

Car::Car(Car&& other) noexcept
{
    moveFrom(std::move(other));
}

Car& Car::operator=(Car&& other) noexcept
{
    if (this != &other)
    {
        free();
        moveFrom(std::move(other));
    }
    return *this;
}

Car::~Car()
{
    free();
}

void Car::addFeature(const char* feature)
{
    if (!feature)
        return;

    if (hasFeature(feature))
        return;

    char** newFeatures = new char* [featuresCount + 1];

    for (size_t i = 0; i < featuresCount; i++)
    {
        newFeatures[i] = features[i];
    }

    newFeatures[featuresCount] = new char[strlen(feature) + 1];
    strcpy(newFeatures[featuresCount], feature);

    delete[] features;
    features = newFeatures;
    featuresCount++;
}

void Car::removeFeature(const char* feature)
{
    if (!feature || featuresCount == 0)
        return;

    size_t indexToRemove = featuresCount;
    for (size_t i = 0; i < featuresCount; i++)
    {
        if (strcmp(features[i], feature) == 0)
        {
            indexToRemove = i;
            break;
        }
    }

    if (indexToRemove == featuresCount)
        return;

    delete[] features[indexToRemove];

    if (featuresCount == 1)
    {
        delete[] features;
        features = nullptr;
        featuresCount = 0;
        return;
    }

    char** newFeatures = new char* [featuresCount - 1];
    size_t newIndex = 0;

    for (size_t i = 0; i < featuresCount; i++)
    {
        if (i != indexToRemove)
        {
            newFeatures[newIndex++] = features[i];
        }
    }

    delete[] features;
    features = newFeatures;
    featuresCount--;
}

bool Car::hasFeature(const char* feature) const
{
    if (!feature)
        return false;

    for (size_t i = 0; i < featuresCount; i++)
    {
        if (strcmp(features[i], feature) == 0)
            return true;
    }

    return false;
}

void Car::changePrice(double newPrice)
{
    if (newPrice >= 0)
        price = newPrice;
}

void Car::print() const
{
    std::cout << "ID: " << id << '\n';
    std::cout << "Brand: " << brand << '\n';
    std::cout << "Model: " << model << '\n';
    std::cout << "Year: " << year << '\n';
    std::cout << "Price: " << price << '\n';
    std::cout << "Features: ";

    if (featuresCount == 0)
    {
        std::cout << "No features";
    }
    else
    {
        for (size_t i = 0; i < featuresCount; i++)
        {
            std::cout << features[i];
            if (i != featuresCount - 1)
                std::cout << ", ";
        }
    }

    std::cout << "\n";
}

unsigned Car::getId() const
{
    return id;
}

const char* Car::getBrand() const
{
    return brand;
}

const char* Car::getModel() const
{
    return model;
}

unsigned Car::getYear() const
{
    return year;
}

double Car::getPrice() const
{
    return price;
}

size_t Car::getFeaturesCount() const
{
    return featuresCount;
}

const char* Car::getFeatureAt(size_t index) const
{
    if (index >= featuresCount)
        return nullptr;

    return features[index];
}