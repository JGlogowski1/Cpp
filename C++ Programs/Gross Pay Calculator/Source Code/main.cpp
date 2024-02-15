#include <iostream>
#include <list>
#include <string>

//Title: ICA2 Gross Pay Problem
//Author: Joe Glogowski
//Date: October 12, 2023
//Filename: grossPay.cpp
//Purpose: ICA2

#include "class.h"



void userLoop(std::list<Employee>& employees);


int main() {

    std::list<Employee> employees;

    userLoop(employees);

    auto employeeIterator = employees.begin();

    while(employeeIterator != employees.end()){
        std::cout << employeeIterator -> getName() << " made $" << employeeIterator->getGrossPay() << std::endl;
        employeeIterator++;
    }
    return 0;

}


void userLoop(std::list<Employee>& employees) {

    char check;



    // do while will run again if the user wants to calculate another gross pay
    int employeeCounter = 1;

    do {


        Employee employee;
        std::string name;

        float hoursWorked, wage;

        //takes the users name
        std::cout << "Give me your name" << std::endl;
        std::cin >> name;


        //appends the name to the end of the list
        employee.setName(name);


        //Gets the ammount of hours you worked
        std::cout << "How many hours did you work" << std::endl;
        std::cin >> hoursWorked;
        employee.setHoursWorked(hoursWorked);

        //Gets how much money you make per hour
        std::cout << "How much money do you make per hour" << std::endl;
        std::cin >> wage;
        employee.setWage(wage);

        employees.push_back(employee);


        //asks user if they want to calculate another gross pay
        std::cout << "Do you want to calculate another gross pay. y or n." << std::endl;
        std::cin >> check;

    }while (check == 'y');
}