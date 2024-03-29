//Title: ICA2 Gross Pay Problem
//Author: Joe Glogowski
//Date: October 12, 2023
//Filename: class.cpp
//Purpose: Employee Class Implementation File

#include <string>
#include "class.h"

Employee::Employee() : hoursWorked(0.0), wage(0.0) {
    // Constructor implementation if needed
}

void Employee::setName(const std::string& n) {
    name = n;
}

void Employee::setHoursWorked(float h) {
    hoursWorked = h;
}

void Employee::setWage(float w) {
    wage = w;
}

std::string Employee::getName() const {
    return name;
}

float Employee::getOvertime() const {
    float overtime = 0.0;
    if (hoursWorked >= 40) {
        overtime = (hoursWorked - 40) * 1.5;
    }
    return overtime;
}

float Employee::getGrossPay() const {
    return hoursWorked * wage + getOvertime();
}
