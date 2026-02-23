#include <cstring>

const int MAX_NAME_LENGTH = 50;
const int MAX_EMPLOYEES = 100;

enum class Position {
    INTERN,
    DEVELOPER,
    SENIOR,
    MANAGER
};

struct Employee {
    char name[MAX_NAME_LENGTH];
    int id;
    double salary;
    Position position;
};

struct Firm {
    char name[MAX_NAME_LENGTH];
    Employee employees[MAX_EMPLOYEES];
    int employeeCount;
};

int findEmployeeIndex(const Firm& firm, int id) {
    for (int i = 0; i < firm.employeeCount; ++i)
        if (firm.employees[i].id == id)
            return i;

    return -1;
}

bool isEmployed(const Firm& firm, int id) {
    return findEmployeeIndex(firm, id) != -1;
}

bool isManager(const Employee& employee) {
    return employee.position == Position::MANAGER;
}

bool promotePosition(Position& position) {
    switch (position) {
    case Position::INTERN:
        position = Position::DEVELOPER;
        return true;

    case Position::DEVELOPER:
        position = Position::SENIOR;
        return true;

    case Position::SENIOR:
        position = Position::MANAGER;
        return true;

    case Position::MANAGER:
        return false;
    }
    return false;
}

bool hire(Firm& firm, const Employee& employee) {
    if (firm.employeeCount >= MAX_EMPLOYEES)
        return false;

    if (isEmployed(firm, employee.id))
        return false;

    firm.employees[firm.employeeCount++] = employee;
    return true;
}

bool fire(Firm& firm, Employee& employee) {
    if (isManager(employee))
        return false;

    if (isEmployed(firm, employee.id))
        return false;

    int index = findEmployeeIndex(firm, employee.id);
    firm.employees[index] = firm.employees[firm.employeeCount - 1];
    firm.employeeCount--;
    return true;
}

int countByPosition(const Firm& firm, Position position) {
    int count = 0;

    for (int i = 0; i < firm.employeeCount; ++i)
        if (firm.employees[i].position == position)
            count++;

    return count;
}

const Employee* highestSalary(const Firm& firm) {
    if (firm.employeeCount == 0)
        return nullptr;

    int bestIndex = 0;

    for (int i = 1; i < firm.employeeCount; ++i)
        if (firm.employees[i].salary >
            firm.employees[bestIndex].salary)
            bestIndex = i;

    return &firm.employees[bestIndex];
}

bool promote(Firm& firm, Employee& employee) {
    if (!isEmployed(firm, employee.id))
        return false;

    return promotePosition(employee.position);
}

