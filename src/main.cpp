#include "rot.h"
#include <string.h>
#include <algorithm>
#include <iterator>
#include <iostream>

std::string parseArgs(int start, int end, char* argv[]) {
    std::string output = "";

    for (int i = start; i < end; i++) {
        output += argv[i];
        if (i < end - 1) { output += " "; }
        else { output += "\n"; }
    }

    return output;
}

int main(int argc, char* argv[]) {
    Rot rot;
    int variant = 13;
    int availableVariants[4] = {5, 13, 18, 47};

    if (argc >= 2) {
        if (strcmp(argv[1], "--help") == 0 || strcmp(argv[1], "-h") == 0){
            std::cout << "Usage: ROT13 [OPTION]...\n\n"
                         "Options:\n"
                         "  --help, -h            Show this help message.\n"
                         "  --variant, -v=i       Change the variant [5, 13, 18, 47] (Default: 13).\n";
            return 0;
        } else if (strcmp(argv[1], "--variant") == 0 || strcmp(argv[1], "-v") == 0) {
            try {
                variant = std::stoi(argv[2]);
                if (std::find(std::begin(availableVariants), std::end(availableVariants), variant) == std::end(availableVariants)) { throw 505; }
            } catch(...){
                std::cout << "Invalid variant!" << std::endl;
            }

            std::cout << rot.cipher(parseArgs(3, argc, argv), variant);

            return 0;
        }
    }

    std::cout << rot.cipher(parseArgs(1, argc, argv), variant);

    return 0;
}
