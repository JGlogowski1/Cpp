#include <iostream>
#include <vector>

int main() {

    std::vector<int> gradeArr;
    int sum;
    int grade;

    do {
        //asks user for input of grades
        std::cout << "Input grades and when done, input -1:";
        std::cin >> grade;
        std::cout << std::endl;

        if(grade != -1) {

            //adds grade to sum
            sum += grade;

            gradeArr.push_back(grade);
        }

    }while(grade != -1);

    std::cout << std::endl << "You entered: " << gradeArr.size() << " grades." << std::endl;

    //prints all the grades
    std::cout << "Grades entered: ";
    for (int i : gradeArr){
        std::cout << i << " ";
    }

    //prints the average
    std::cout << std::endl << "The average grade is: " << (sum / gradeArr.size()) << std::endl;

    return 0;
}