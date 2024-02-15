//
// Created by W0453648 on 2023-11-30.
//

#ifndef GROSSCLASS_CLASS_H
#define GROSSCLASS_CLASS_H

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
