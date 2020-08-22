/*
Nad3z's ROT13
https://en.wikipedia.org/wiki/ROT13
*/

#include <iostream>
#include <sstream>
#include <string>

int main() {
    int variant = 13;
    bool running = true;

    std::cout << "Use the \"/help\" command to see available commands." << std::endl;

    while(running) {
        std::string input, command;
        std::stringstream ss;

        std::cout << ">>> ";
        getline(std::cin, input);

        ss << input;
        ss >> command;

        if(command[0] == '/') {
            command.erase(0, 1);

            if(command == "rot") {
                int oldVariant = variant;
                ss >> variant;
                if(variant == 5 || variant == 13 || variant == 18 || variant == 47)
                    std::cout << std::endl << "Success: Variant changed to " << variant << std::endl << std::endl;
                else {
                    std::cout << std::endl << "ERROR: Unknown variant!" << std::endl << std::endl;
                    variant = oldVariant;
                }
            }
            else if(command == "help") {
                std::cout << "layout: /Command {Args} | Description\n\n/Help | Show all available commands\n/Rot {Variant/Number} | Switch variant, available variants: {5, 13, 18, 47}\n/Quit | Stop the program" << std::endl;
            }
            else if(command == "quit") {
                running = false;
            }
        }
        else {
            for(size_t i = 0; i < input.length(); i++) {
                switch(variant) {
                    case(5):
                        if(input[i] >= 48 && input[i] <= 57) {
                            std::cout << (char)(input[i] >= 53 ? input[i] - 5 : input[i] + 5);
                            break;
                        }
                        else {
                            std::cout << input[i];
                            break;
                        }
                    case(13):
                        if(input[i] >= 65 && input[i] <= 90) {
                            std::cout << (char)(input[i] >= 78 ? input[i] - 13 : input[i] + 13);
                            break;
                        }
                        else if(input[i] >= 97 && input[i] <= 122) {
                            std::cout << (char)(input[i] <= 109 ? input[i] + 13 : input[i] - 13);
                            break;
                        }
                        else {
                            std::cout << input[i];
                        }
                    case(18):
                        if(input[i] >= 48 && input[i] <= 57) {
                            std::cout << (char)(input[i] >= 53 ? input[i] - 5 : input[i] + 5);
                            break;
                        }
                        else if(input[i] >= 65 && input[i] <= 90) {
                            std::cout << (char)(input[i] >= 78 ? input[i] - 13 : input[i] + 13);
                            break;
                        }
                        else if(input[i] >= 97 && input[i] <= 122) {
                            std::cout << (char)(input[i] <= 109 ? input[i] + 13 : input[i] - 13);
                            break;
                        }
                        else {
                            std::cout << input[i];
                            break;
                        }
                    case(47):
                        if(input[i] >= 33 && input[i] <= 126) {
                            std::cout << (char)(input[i] >= 79 ? input[i] - 47 : input[i] + 47);
                            break;
                        }
                        else {
                            std::cout << input[i];
                            break;
                        }
                }
            }

        std::cout << std::endl;
        }
    }

return 0;
}
