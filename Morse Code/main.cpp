//Title: Morse Code Translator
//Author: Joe Glogowski
//Date: November 23, 2023
//Filename: morseCode.cpp
//Purpose: Assignment 4
//files i will include:
#include "functions.h"


#ifndef MORSECODE_MAIN_CPP
#define MORSECODE_MAIN_CPP


int main() {

    //both maps for morse to char, and char to morse
    std::map<char, std::string> charToMorse = {{'a', ".--"},{'b', "-..."},{'c', "-.-."},{'d', "-.."},{'e', "."},{'f', "..-."},{'g', "--."},{'h', "...."},{'i', ".."},{'j', ".---"},{'k', "-.-"},{'l', ".-.."},{'m', "--"},{'n', "-."},{'o', "---"},{'p', ".--."},{'q', "--.--"},{'r', ".-.-"},{'s', "..."},{'t', "-"},{'u', "..-"},{'v', "...-"},{'w', ".--"},{'x', "-..-"},{'y', "-.--"},{'z', "--.."},{' ', "   "},{' ', "   "}};
    std::map<std::string, char> morseToChar = {{".--", 'a'},{"-...", 'b'},{"-.-.", 'c'},{"-..", 'd'},{".", 'e'},{"..-.", 'f'},{"--.", 'g'},{"....", 'h'},{"..", 'i'},{".---", 'j'},{"-.-", 'k'},{".-..", 'l'},{"--", 'm'},{"-.", 'n'},{"---", 'o'},{".--.", 'p'},{"--.--", 'q'},{".-.-", 'r'},{"...", 's'},{"-", 't'},{"..-", 'u'},{"...-", 'v'},{".--", 'w'},{"-..-", 'x'},{"-.--", 'y'},{"--..", 'z'},{"   ", ' '},{"   ", ' '}};

    int translationType;
    std::string userString;
    std::string userIn;
    std::string outputString;
    std::string fileString;

    //function to prompt user for type of translate
    translationType = userMenu();

    //function to read file and set to a variable
    switch (translationType) {
        //case 1 is from text, from the terninal
        case 1:
            userString = userInput();
            outputString = fromText(userString, charToMorse);
            displayOutput(outputString);


            break;
            //case 2 is from text, from a file
        case 2:
            //function to connect, read, and assign the file contents to a variable
            fileString = readFile();
            //use the fromText function to convert to morse code
            outputString = fromText(fileString, charToMorse);
            displayOutput(outputString);
            //displayOutput

            break;
            //case 3 is from morse code, from the terminal
        case 3:
            userString = userInput();
            outputString = fromMorse(userString, morseToChar);
            displayOutput(outputString);


            break;
        case 4:
            fileString = readFile();
            outputString = fromMorse(fileString, morseToChar);
            displayOutput(outputString);

            break;
    }


    return 0;
}

#endif // MORSECODE_MAIN_CPP