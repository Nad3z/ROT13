#include "ROT5.h"

std::string ROT5::cipher(std::string input) {
    std::string output;

    for(int i = 0; i < input.length(); i++) {
        if(std::isdigit(input[i])) {
            if(input[i] + 5 > 57)
                output += input[i] - 5;
            else
                output += input[i] + 5;
        }
        else {
            output += input[i];
        }
    }

    return output;
}

std::string ROT5::decipher(std::string input) {
    std::string output;

    for(int i = 0; i < input.length(); i++) {
        if(std::isdigit(input[i])) {
            if(input[i] - 5 < 48)
                output += input[i] + 5;
            else
                output += input[i] - 5;
        }
        else {
            output += input[i];
        }
    }

    return output;
}
