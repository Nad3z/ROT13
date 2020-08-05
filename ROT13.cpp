#include "ROT13.h"

bool checkIfCapital(char l) {
    if(l >= 65 && l <= 90) {
        return true;
    }

    return false;
}

char calcUp(char l, int low, int high) {
    if (l + 13 > high)
        return (low - 1) + (13 + (l - high));
    else
        return l + 13;
}

char calcDown(char l, int low, int high) {
    if (l - 13 < low)
        return (high + 1) - (13 - (l - low));
    else
        return l - 13;
}

std::string ROT13::cipher(std::string input) {
    std::string output;

    for(int i = 0; i < input.length(); i++) {
        if(checkIfCapital(input[i])) {
            output += calcUp(input[i], 65, 90);
        }
        else {
            output += calcUp(input[i], 97, 122);
        }
    }

    return output;
}

std::string ROT13::decipher(std::string input) {
    std::string output;

    for(int i = 0; i < input.length(); i++) {
        if(checkIfCapital(input[i])) {
            output += calcDown(input[i], 65, 90);
        }
        else {
            output += calcDown(input[i], 97, 122);
        }
    }

    return output;
}
