#include "ROT13.h"

bool isCapital(char l) {
    if(l >= 65 && l <= 90) {
        return true;
    }

    return false;
}

std::string ROT13::cipher(std::string input, int variant) {
    std::string output;

    for(int i = 0; i < (int)input.length(); i++) {
        if(std::isdigit(input[i]) && (variant == 5 || variant == 18))
            output += input[i] >= 53 ? input[i] - 5 : input[i] + 5;
        else if(isCapital(input[i]) && !std::isdigit(input[i]) && (variant == 13 || variant == 18))
            output += input[i] >= 78 ? input[i] - 13 : input[i] + 13;
        else if(!isCapital(input[i]) && !std::isdigit(input[i]) && (variant == 13 || variant == 18))
            output += input[i] <= 109 ? input[i] + 13 : input[i] - 13;
        else if(variant == 47)
            output += input[i] >= 80 ? input[i] - 47 : input[i] + 47;
        else
            output += input[i];
    }

    return output;
}
