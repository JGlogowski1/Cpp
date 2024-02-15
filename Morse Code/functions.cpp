//Title: Morse Code Translator
//Author: Joe Glogowski
//Date: November 23, 2023
//Filename: functions.cpp
//Purpose: Assignment 4
//files i will include:
#include "functions.h"



#include <iostream>
#include <map>
#include <windows.h>
#include <limits>
#include <fstream>
#include <sstream>

int userMenu() {
    int x;
    int y;
    int typeOfTranslate = 0;

    std::cout << "Welcome to morse code translator!!!!" << std::endl;
    Sleep(1000);

    do {
        std::cout << "Would you like to translate from text to morse code, or morse code to text." << std::endl
                  << "\t1 = from text to morse code." << std::endl << "\t2 = from morse code to text" << std::endl;
        std::cin >> x;
        if (x == 1){
            std::cout << "Would you like to translate from the terminal or from a file" << std::endl
                      << "\t1 = from terminal" << std::endl << "\t2 = from file" << std::endl;
            std::cin >> y;
            if (y == 1){
                //type of translation 1 is from text, from the terminal.
                typeOfTranslate = 1;
                std::cout << "Give me your text: " << std::endl;
            }else if (y == 2) {
                //type of translation 2 is from text code, from a file.
                typeOfTranslate = 2;
            }else{
                std::cout << "Incorrect input, Please Try again" << std::endl;
                continue;
            }
        }else if(x == 2) {
            std::cout << "Would you like to translate from the terminal or from a file" << std::endl
                      << "\t1 = from terminal" << std::endl << "\t2 = from file" << std::endl;
            std::cin >> y;
            if (y == 1){
                //type of translation 3 is from morse code, from the terminal
                typeOfTranslate = 3;
                std::cout << "Give me your morse code (one space between each morse-coded letter, and three spaces between each morse-coded word)" << std::endl;
            }else if (y == 2) {
                //type of translation 4 is from morse code, from a file
                typeOfTranslate = 4;
            }else{
                std::cout << "Incorrect input, Please Try again" << std::endl;
                continue;
            }
        }else{
            std::cout << "Incorrect input, Please Try again" << std::endl;
            continue;
        }

    }while(typeOfTranslate == 0);
    return typeOfTranslate;
}

std::string userInput(){

    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::string userString;
    std::getline(std::cin, userString);

    return userString;
}

std::string readFile () {
    std::ifstream file("fileToRead.txt");


    if(!file.is_open()){
        std::cerr << "error opening file: " << "fileToRead.txt" << std::endl;
        return "";
    }

    std::string fileContent;
    std::string line;

    while (std::getline(file, line)) {
        fileContent += line + "\n";
    }

    file.close();

    return fileContent;
}

std::string fromText(const std::string& userString, const std::map<char, std::string>& charToMorse) {
    std::string morseCode;

    for (char c : userString) {
        auto it = charToMorse.find(c);
        if (it != charToMorse.end()) {
            morseCode += it->second + ' ';
        }else {
            morseCode += " ";
        }
    }
    return morseCode;
}

std::string fromMorse(const std::string& morseCode, const std::map<std::string, char>& morseToChar) {
    std::string english;
    std::istringstream iss(morseCode);

    std::string morseSymbol;
    while (iss >> morseSymbol) {
        if (morseSymbol == " ") {
            english += ' ';  // Handle space between words
        } else {
            auto it = morseToChar.find(morseSymbol);
            if (it != morseToChar.end()) {
                english += it->second;
            } else {
                english += '?';
            }
        }
    }
    return english;
}

void displayOutput(const std::string& outputString){

    std::cout << "the output is: " << outputString << std::endl;

}//
// Created by W0453648 on 2023-11-23.
//

#include "functions.h"

#include <iostream>
#include <map>
#include <windows.h>
#include <limits>
#include <fstream>
#include <sstream>

// Function to display the user menu and prompt for the type of translation.
int userMenu() {
    int x;
    int y;
    int typeOfTranslate = 0;

    std::cout << "Welcome to morse code translator!!!!" << std::endl;
    Sleep(1000);

    do {
        std::cout << "Would you like to translate from text to morse code, or morse code to text." << std::endl
                  << "\t1 = from text to morse code." << std::endl << "\t2 = from morse code to text" << std::endl;
        std::cin >> x;
        if (x == 1){
            std::cout << "Would you like to translate from the terminal or from a file" << std::endl
                      << "\t1 = from terminal" << std::endl << "\t2 = from file" << std::endl;
            std::cin >> y;
            if (y == 1){
                //type of translation 1 is from text, from the terminal.
                typeOfTranslate = 1;
                std::cout << "Give me your text: " << std::endl;
            }else if (y == 2) {
                //type of translation 2 is from text code, from a file.
                typeOfTranslate = 2;
            }else{
                std::cout << "Incorrect input, Please Try again" << std::endl;
                continue;
            }
        }else if(x == 2) {
            std::cout << "Would you like to translate from the terminal or from a file" << std::endl
                      << "\t1 = from terminal" << std::endl << "\t2 = from file" << std::endl;
            std::cin >> y;
            if (y == 1){
                //type of translation 3 is from morse code, from the terminal
                typeOfTranslate = 3;
                std::cout << "Give me your morse code (one space between each morse-coded letter, and three spaces between each morse-coded word)" << std::endl;
            }else if (y == 2) {
                //type of translation 4 is from morse code, from a file
                typeOfTranslate = 4;
            }else{
                std::cout << "Incorrect input, Please Try again" << std::endl;
                continue;
            }
        }else{
            std::cout << "Incorrect input, Please Try again" << std::endl;
            continue;
        }

    }while(typeOfTranslate == 0);
    return typeOfTranslate;
}

// Function to get user input from the terminal.
std::string userInput(){

    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::string userString;
    std::getline(std::cin, userString);

    return userString;
}

// Function to read content from a file.
std::string readFile () {
    std::ifstream file("fileToRead.txt");

    if(!file.is_open()){
        std::cerr << "error opening file: " << "fileToRead.txt" << std::endl;
        return "";
    }

    std::string fileContent;
    std::string line;

    while (std::getline(file, line)) {
        fileContent += line + "\n";
    }

    file.close();

    return fileContent;
}

// Function to translate text to Morse code.
std::string fromText(const std::string& userString, const std::map<char, std::string>& charToMorse) {
    std::string morseCode;

    for (char c : userString) {
        auto it = charToMorse.find(c);
        if (it != charToMorse.end()) {
            morseCode += it->second + ' ';
        }else {
            morseCode += " ";
        }
    }
    return morseCode;
}

// Function to translate Morse code to text.
std::string fromMorse(const std::string& morseCode, const std::map<std::string, char>& morseToChar) {
    std::string english;
    std::istringstream iss(morseCode);

    std::string morseSymbol;
    while (iss >> morseSymbol) {
        if (morseSymbol == " ") {
            english += ' ';  // Handle space between words
        } else {
            auto it = morseToChar.find(morseSymbol);
            if (it != morseToChar.end()) {
                english += it->second;
            } else {
                english += '?';
            }
        }
    }
    return english;
}

// Function to display the translated output.
void displayOutput(const std::string& outputString){

    std::cout << "the output is: " << outputString << std::endl;

}
