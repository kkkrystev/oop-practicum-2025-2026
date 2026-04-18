#pragma once
#include <iostream>

class Car
{
private:
    unsigned id;
    char* brand;
    char* model;
    unsigned year;
    double price;
    char** features;
    size_t featuresCount;

    static unsigned idGenerator;

    void copyFrom(const Car& other);
    void moveFrom(Car&& other);
    void free();

    void setString(char* dest, const char* src);

public:
    Car();
    Car(const char* brand, const char* model, unsigned year, double price);

    Car(const Car& other);
    Car& operator=(const Car& other);

    Car(Car&& other) noexcept;
    Car& operator=(Car&& other) noexcept;

    ~Car();

    void addFeature(const char* feature);
    void removeFeature(const char* feature);
    bool hasFeature(const char* feature) const;

    void changePrice(double newPrice);

    void print() const;

    unsigned getId() const;
    const char* getBrand() const;
    const char* getModel() const;
    unsigned getYear() const;
    double getPrice() const;
    size_t getFeaturesCount() const;
    const char* getFeatureAt(size_t index) const;
};