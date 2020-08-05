#include <iostream>
#include <sstream>
#include <string>

#include "ROT13.h"

int main() {
    ROT13 rot13 = ROT13();
    std::string command;
    std::string input;
    std::stringstream ss;
    std::string text;

    std::cout << "Use the \"help\" command to see available commands." << std::endl;

    while(command != "quit") {
        command = "";
        input = "";
        ss.clear();

        std::cout << ">>> ";
        getline(std::cin, input);

        ss << input;
        ss >> command;

        if(command == "c" or command == "cipher") {
            ss >> text;
            std::cout << rot13.cipher(text) << std::endl;
        }
        else if(command == "d" or command == "decipher") {
            ss >> text;
            std::cout << rot13.decipher(text) << std::endl;
        }
        else if(command == "help") {
            std::cout << "layout: [Command],[Alias] {Args}\n\n        [Cipher],[c] {Word}\n        [Decipher],[d] {Word}" << std::endl; 
        }
        else if(command != "quit") {
            std::cout << "Unknown command!" << std::endl;
        }
    }

    return 0;
}
