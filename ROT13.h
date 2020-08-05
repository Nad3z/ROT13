#pragma once

#include <string>

class ROT13 {
    public:
        std::string cipher(std::string input);
        std::string decipher(std::string input);
};
