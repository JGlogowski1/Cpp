//Title: ICA2 Gross Pay Problem
//Author: Joe Glogowski
//Date: October 12, 2023
//Filename: class.h
//Purpose: Employee Class Header File

#ifndef GROSSCLASS_CLASS_H
#define GROSSCLASS_CLASS_H

#include <string>

class Employee {
private:
    std::string name;
    float hoursWorked, wage;

public:
    Employee();

    void setName(const std::string &n);

    void setHoursWorked(float h);

    void setWage(float w);

    std::string getName() const;

    float getOvertime() const;

    float getGrossPay() const;
};

#endif //GROSSCLASS_CLASS_H
