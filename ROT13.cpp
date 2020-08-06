#include "ROT13.h"

bool checkIfCapital(char l) {
    if(l >= 65 && l <= 90) {
        return true;
    }

    return false;
}

char calcUp(char l, int ammount, int low, int high) {
    if(l + ammount > high)
        return (low - 1) + (ammount + (l - high));
    else
        return l + ammount;
}

char calcDown(char l, int ammount, int low, int high) {
    if(l - ammount < low)
        return (high + 1) - (ammount - (l - low));
    else
        return l - ammount;
}

std::string ROT13::cipher(std::string input) {
    std::string output;

    for(int i = 0; i < input.length(); i++) {
        if(std::isdigit(input[i])) output += input[i];
        else if(checkIfCapital(input[i])) {
            output += calcUp(input[i], 13, 65, 90);
        }
        else {
            output += calcUp(input[i], 13, 97, 122);
        }
    }

    return output;
}

std::string ROT13::decipher(std::string input) {
    std::string output;

    for(int i = 0; i < input.length(); i++) {
        if(std::isdigit(input[i])) output += input[i];
        else if(checkIfCapital(input[i])) {
            output += calcDown(input[i], 13, 65, 90);
        }
        else {
            output += calcDown(input[i], 13, 97, 122);
        }
    }

    return output;
}
