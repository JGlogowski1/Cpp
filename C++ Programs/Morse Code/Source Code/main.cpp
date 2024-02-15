#include "functions.h"
#include <iostream>
#include <map>
#include <windows.h>
#include <limits>
#include <fstream>
#include <sstream>

int main() {
    // Both maps for morse to char, and char to morse
    std::map<char, std::string> charToMorse = {
        {'a', ".--"}, {'b', "-..."}, {'c', "-.-."}, {'d', "-.."}, {'e', "."}, {'f', "..-."},
        {'g', "--."}, {'h', "...."}, {'i', ".."}, {'j', ".---"}, {'k', "-.-"}, {'l', ".-.."},
        {'m', "--"}, {'n', "-."}, {'o', "---"}, {'p', ".--."}, {'q', "--.--"}, {'r', ".-.-"},
        {'s', "..."}, {'t', "-"}, {'u', "..-"}, {'v', "...-"}, {'w', ".--"}, {'x', "-..-"},
        {'y', "-.--"}, {'z', "--.."}, {' ', "   "}
    };

    std::map<std::string, char> morseToChar = {
        {".--", 'a'}, {"-...", 'b'}, {"-.-.", 'c'}, {"-..", 'd'}, {".", 'e'}, {"..-.", 'f'},
        {"--.", 'g'}, {"....", 'h'}, {"..", 'i'}, {".---", 'j'}, {"-.-", 'k'}, {".-..", 'l'},
        {"--", 'm'}, {"-.", 'n'}, {"---", 'o'}, {".--.", 'p'}, {"--.--", 'q'}, {".-.-", 'r'},
        {"...", 's'}, {"-", 't'}, {"..-", 'u'}, {"...-", 'v'}, {".--", 'w'}, {"-..-", 'x'},
        {"-.--", 'y'}, {"--..", 'z'}, {"   ", ' '}
    };

    int translationType;
    std::string userString;
    std::string outputString;
    std::string fileString;

    // Function to prompt user for type of translation
    translationType = userMenu();

    // Function to read file and set to a variable
    switch (translationType) {
        // Case 1 is from text, from the terminal
        case 1:
            userString = userInput();
            outputString = fromText(userString, charToMorse);
            displayOutput(outputString);
            break;
        // Case 2 is from text, from a file
        case 2:
            fileString = readFile();
            outputString = fromText(fileString, charToMorse);
            displayOutput(outputString);
            break;
        // Case 3 is from morse code, from the terminal
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
