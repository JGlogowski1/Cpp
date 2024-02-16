#include <iostream>
#include <cstdlib> // for rand() and srand()
#include <ctime> // for time()
#include <limits>

// Function prototype
int montyHall(int n, char switchChoice);

int main() {
    std::cout << "Welcome to the Monty Hall problem\n";
    std::cout << "Please enter the number of simulations you want to run: ";

    int n;
    // Input validation
    while (!(std::cin >> n) || n <= 0) {
        std::cout << "Invalid input. Please enter a positive integer: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    std::cout << "You have chosen to run " << n << " simulations\n";
    std::cout << "Do you want to switch your choice after the host opens a door? (y/n): ";

    char switchChoice;
    // Input validation
    while (!(std::cin >> switchChoice) || (switchChoice != 'y' && switchChoice != 'n')) {
        std::cout << "Invalid input. Please enter 'y' for yes or 'n' for no: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    // Seed the random number generator
    srand(static_cast<unsigned int>(time(nullptr)));

    int winner = montyHall(n, switchChoice);

    // Calculate and display the average percentage of wins
    double winPercentage = (static_cast<double>(winner) / n) * 100;
    std::cout << "The average percentage of wins is " << winPercentage << "%\n";

    return 0;
}

// Function to simulate Monty Hall problem
int montyHall(int n, char switchChoice) {
    int totalWins = 0; // Variable to track total wins

    for (int i = 0; i < n; ++i) {
        // Randomly assign car behind one of the doors
        int car = rand() % 3;
        // Randomly choose a door
        int choice = rand() % 3;

        // Determine the door revealed by host that doesn't have the car and wasn't chosen
        int goat = -1;
        for (int j = 0; j < 3; ++j) {
            if (j != car && j != choice) {
                goat = j;
                break;
            }
        }

        // Apply switching logic if requested
        if (switchChoice == 'y') {
            // Switch choice to the other unchosen door
            choice = 3 - choice - goat;
        }

        // Check if the chosen door contains the car
        if (choice == car) {
            totalWins++; // Increment total wins if the chosen door has the car
        }
    }

    return totalWins; // Return total wins
}
