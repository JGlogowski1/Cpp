#include <iostream>
#include <vector>

int main() {
    std::vector<int> gradeArr; // Vector to store grades
    int sum = 0; // Variable to store the sum of grades
    int grade; // Variable to store each grade entered by the user

    do {
        // Asks the user for input of grades until -1 is entered
        std::cout << "Input grades, and when done, input -1: ";
        std::cin >> grade;
        std::cout << std::endl;

        if (grade != -1) {
            // Adds the grade to the sum and pushes it into the vector
            sum += grade;
            gradeArr.push_back(grade);
        }

    } while (grade != -1);

    // Displays the total number of grades entered
    std::cout << std::endl << "You entered: " << gradeArr.size() << " grades." << std::endl;

    // Prints all the grades entered
    std::cout << "Grades entered: ";
    for (int i : gradeArr) {
        std::cout << i << " ";
    }

    // Calculates and displays the average grade
    if (!gradeArr.empty()) {
        std::cout << std::endl << "The average grade is: " << (sum / gradeArr.size()) << std::endl;
    } else {
        std::cout << std::endl << "No grades entered. Average cannot be calculated." << std::endl;
    }

    return 0;
}
