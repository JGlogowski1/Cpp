//Title: Morse Code Translator
//Author: Joe Glogowski
//Date: November 23, 2023
//Filename: functions.h
//Purpose: Assignment 4

#ifndef MORSECODE_FUNCTIONS_H
#define MORSECODE_FUNCTIONS_H

#include <string>
#include <map>


int userMenu();

std::string userInput();

std::string readFile();

std::string fromText(const std::string& userString, const std::map<char, std::string>& charToMorse);

std::string fromMorse(const std::string& userString, const std::map<std::string, char>& morseToChar);

void displayOutput(const std::string& displayOutput);


#endif //MORSECODE_FUNCTIONS_H
