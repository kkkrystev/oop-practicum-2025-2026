#include "GradeBook.h"
#include "Grade.h"
#include <iostream>
#include <cstring>

void GradeBook::free() {
    delete[] courseName;
    courseName = nullptr;
    
    delete[] grades;
    grades = nullptr;
    
    count = 0;
}

void GradeBook::copyFrom(const GradeBook& other) {
    count = other.count;

    courseName = new char[std::strlen(other.courseName) + 1];
    strcpy_s(courseName,
        std::strlen(other.courseName) + 1,
        other.courseName);

    grades = new Grade[CAPACITY];

    for (int i = 0; i < count; i++) {
        grades[i] = other.grades[i];
    }
}

GradeBook::GradeBook()
    : courseName(new char[1] {'\0'}),
    grades(new Grade[CAPACITY]), 
    count(0) 
{}

GradeBook::GradeBook(const char* name)
    : courseName(nullptr),
    grades(new Grade[CAPACITY]),
    count(0)
{
    if (!name) {
        courseName = new char[1] {'\0'};
    }
    else {
        courseName = new char[std::strlen(name) + 1];
        strcpy_s(courseName, std::strlen(name) + 1, name);
    }
}

GradeBook::GradeBook(const GradeBook& other)
    : courseName(nullptr),
    grades(nullptr),
    count(0)
{
    copyFrom(other);
}

GradeBook& GradeBook::operator=(const GradeBook& other) {
    if (this != &other) {
        free();
        copyFrom(other);
    }
    return *this;
}

GradeBook::~GradeBook() {
    free();
}

bool GradeBook::addGrade(const Grade& g) {
    if (count >= CAPACITY) 
        return false;

    grades[count] = g;
    count++;

    return true;
}

double GradeBook::average() const {
    if (count == 0) 
        return 0.0;

    double sum = 0.0;

    for (int i = 0; i < count; i++) {
        sum += grades[i].grade;
    }

    return sum / count;
}

double GradeBook::getGrade(const char* fn) const {
    for (int i = 0; i < count; i++) {
        if (std::strcmp(grades[i].fn, fn) == 0)
            return grades[i].grade;
    }
    return -1;
}

const char* GradeBook::getCourseName() const
{
    return courseName;
}

void GradeBook::print() const {
    std::cout << "Course: " << courseName << "\n";

    for (std::size_t i = 0; i < count; i++) {
        std::cout << "FN: " << grades[i].fn
            << " Grade: " << grades[i].grade
            << "\n";
    }
}