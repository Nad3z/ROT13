#include <iostream>
#include <sstream>
#include <string>

#include "ROT5.h"
#include "ROT13.h"

int main() {
    ROT5 rot5 = ROT5();
    ROT13 rot13 = ROT13();
    std::string command;
    std::string input;
    std::stringstream ss;
    std::string text;
    std::string variant = "13";

    std::cout << "Use the \"help\" command to see available commands." << std::endl;

    while(command != "quit") {
        command = "";
        input = "";
        ss.clear();

        std::cout << ">>> ";
        getline(std::cin, input);

        ss << input;
        ss >> command >> text;

        if(command == "c" or command == "cipher") {
            if(variant == "5")
                std::cout << rot5.cipher(text) << std::endl;
            else if(variant == "13")
                std::cout << rot13.cipher(text) << std::endl;
            else if(variant == "18")
                std::cout << rot13.cipher(rot5.cipher(text)) << std::endl;
        }
        else if(command == "d" or command == "decipher") {
            if(variant == "5")
                std::cout << rot5.cipher(text) << std::endl;
            else if(variant == "13")
                std::cout << rot13.decipher(text) << std::endl;
            else if(variant == "18")
                std::cout << rot13.cipher(rot5.cipher(text)) << std::endl;
        }
        else if(command == "rot") {
            if(text == "5" || text == "13" || text == "18")
                variant = text;
            else
                std::cout << "Unknown variant!" << std::endl;
        }
        else if(command == "help") {
            std::cout << "layout: [Command],[Alias] {Args}\n\n        [cipher],[c] {Word}\n        [decipher],[d] {Word}\n        [rot] {Variant/Number} // Available variants: 5, 13, 18" << std::endl;
        }
        else if(command != "quit") {
            std::cout << "Unknown command!" << std::endl;
        }
    }

    return 0;
}
