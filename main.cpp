#include <iostream>
#include <sstream>
#include <string>

std::string cipher(std::string input, std::string variant) {
    std::string output;

    for(int i = 0; i < (int)input.length(); i++) {
        if(std::isdigit(input[i]) && (variant == "5" || variant == "18"))
            output += input[i] >= 53 ? input[i] - 5 : input[i] + 5;
        else if((input[i] >= 65 && input[i] <= 90) && !std::isdigit(input[i]) && (variant == "13" || variant == "18"))
            output += input[i] >= 78 ? input[i] - 13 : input[i] + 13;
        else if((input[i] >= 97 && input[i] <= 122) && !std::isdigit(input[i]) && (variant == "13" || variant == "18"))
            output += input[i] <= 109 ? input[i] + 13 : input[i] - 13;
        else if((input[i] >= 33 && input[i] <= 126) && variant == "47")
            output += input[i] >= 79 ? input[i] - 47 : input[i] + 47;
        else
            output += input[i];
    }

    return output;
}

int main() {
    std::string command, input, text, variant = "13";
    std::stringstream ss;

    std::cout << "Use the \"help\" command to see available commands." << std::endl;

    while(command != "quit") {
        command = "";
        input = "";
        ss.clear();

        std::cout << ">>> ";
        getline(std::cin, input);

        ss << input;
        ss >> command;

        if(command == "c" || command == "cipher") {
            getline(ss, text);
            text.erase(0, 1);
            std::cout << cipher(text, variant) << std::endl;
        }
        else if(command == "r" || command == "rot") {
            ss >> text;
            if(text == "5" || text == "13" || text == "18" || text == "47")
                variant = text;
            else
                std::cout << "Unknown variant!" << std::endl;
        }
        else if(command == "help") {
            std::cout << "layout: [Command],[Alias] {Args}\n\n        [cipher],[c] {Word}\n        [rot],[r] {Variant/Number} // Available variants: 5, 13, 18, 47\n        [quit]" << std::endl;
        }
        else if(command != "quit") {
            std::cout << "Unknown command!" << std::endl;
        }
    }

    return 0;
}
