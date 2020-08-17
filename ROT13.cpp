#include "ROT13.h"

std::string ROT13::cipher(std::string input, int variant) {
    std::string output;

    for(int i = 0; i < (int)input.length(); i++) {
        if(std::isdigit(input[i]) && (variant == 5 || variant == 18))
            output += input[i] >= 53 ? input[i] - 5 : input[i] + 5;
        else if((input[i] >= 65 && input[i] <= 90) && !std::isdigit(input[i]) && (variant == 13 || variant == 18))
            output += input[i] >= 78 ? input[i] - 13 : input[i] + 13;
        else if((input[i] >= 97 && input[i] <= 122) && !std::isdigit(input[i]) && (variant == 13 || variant == 18))
            output += input[i] <= 109 ? input[i] + 13 : input[i] - 13;
        else if((input[i] >= 33 && input[i] <= 126) && variant == 47)
            output += input[i] >= 79 ? input[i] - 47 : input[i] + 47;
        else
            output += input[i];
    }

    return output;
}
