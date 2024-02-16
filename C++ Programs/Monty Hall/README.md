# Monty Hall Problem Simulator

**Author**: Joe  
**Date**: Feburary 15, 2024  
**Purpose**: Simulation of the Monty Hall problem   
**Filename**: main.cpp

## Overview

The Monty Hall Problem Simulator is a C++ program that simulates the famous Monty Hall problem. It allows users to run multiple simulations of the Monty Hall problem, where they choose one of three doors, one of which hides a prize (car), and then have the option to switch their choice after one of the non-chosen doors (revealed by the host) is opened.

## Features

- **Simulation of Monty Hall Problem**: Simulates the Monty Hall problem according to user input.
- **Input Validation**: Ensures that user inputs are valid and handles errors gracefully.
- **Randomization**: Utilizes the `rand()` function to randomize the location of the car and the user's initial choice.
- **Option to Switch Choice**: Offers users the option to switch their choice after a door is revealed by the host.
- **Calculation of Win Percentage**: Calculates and displays the average percentage of wins based on simulation results.

## Usage

1. **Enter Number of Simulations**: Input the number of simulations you want to run.
2. **Choose Switching Option**: Decide whether you want to switch your choice after the host opens a door (y/n).
3. **View Results**: See the average percentage of wins based on the simulations.

## Example Usage

```plaintext
$ ./montyHall
Welcome to the Monty Hall problem
Please enter the number of simulations you want to run: 10000
You have chosen to run 10000 simulations
Do you want to switch your choice after the host opens a door? (y/n): y
The average percentage of wins is 66.73%
