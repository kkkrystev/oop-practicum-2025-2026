#pragma once
#include "Grade.h"

class GradeBook
{
	static constexpr int CAPACITY = 200;

	char* courseName;
	Grade* grades;
	unsigned count;

    void free();
    void copyFrom(const GradeBook& other);

public:
    GradeBook();
    GradeBook(const char* name);

    GradeBook(const GradeBook& other);
    GradeBook& operator=(const GradeBook& other);

    ~GradeBook();

    bool addGrade(const Grade& g);
    double average() const;

    double getGrade(const char* fn) const;
    const char* getCourseName() const;

    void print() const;
};