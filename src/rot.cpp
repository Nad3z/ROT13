#include "rot.h"
#include <cmath>

char rotateByValue(char input, int val, int minimum, int maximum) {
    if(input >= minimum && input <= maximum) {
        return input >= ceil(maximum - ((maximum - minimum) / 2)) ? input - val : input + val;
    }

    return input;
}

std::string Rot::cipher(std::string input, int variant) {
    for(size_t i = 0; i < input.length(); i++) {
        switch(variant) {
            case(5):
                input[i] = rotateByValue(input[i], 5, 48, 57);
                break;
            case(13):
                input[i] = rotateByValue(input[i], 13, 65, 90);
                input[i] = rotateByValue(input[i], 13, 97, 122);
                break;
            case(18):
                input[i] = rotateByValue(input[i], 5, 48, 57);
                input[i] = rotateByValue(input[i], 13, 65, 90);
                input[i] = rotateByValue(input[i], 13, 97, 122);
                break;
            case(47):
                input[i] = rotateByValue(input[i], 47, 33, 126);
                break;
        }
    }

    return input;
}
