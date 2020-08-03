#include <iostream>
#include <string>

std::string cipher(std::string input) {
    std::string output;

    for (int i = 0; i < input.length(); i++) {
        if(input[i] >= 65 && input[i] <= 90) {
            if (input[i] + 13 > 90)
                output += 64 + (13 + (input[i] - 90));
            else
                output += input[i] + 13;
        }
        else if(input[i] >= 97 && input[i] <= 122) {
            if (input[i] + 13 > 122)
                output += 96 + (13 + (input[i] - 122));
            else
                output += input[i] + 13;
        }
        else
            output += input[i];
    }

    return output;
}

std::string decipher(std::string input) {
    std::string output;

    for (int i = 0; i < input.length(); i++) {
        if(input[i] >= 65 && input[i] <= 90) {
            if (input[i] - 13 < 65)
                output += 91 - (13 - (input[i] - 65));
            else
                output += input[i] - 13;
        }
        else if(input[i] >= 97 && input[i] <= 122) {
            if (input[i] - 13 < 97)
                output += 123 - (13 - (input[i] - 97));
            else
                output += input[i] - 13;
        }
        else
            output += input[i];
    }

    return output;
}

int main() {
    while(true) {
        int choice;
        std::cout << "0. Cipher\n1. Decipher\n>>> ";
        std::cin >> choice;

        std::string input;
        std::cout << "Enter string: ";
        std::cin.get();
        getline(std::cin, input);

        if (choice == 0)
            std::cout << cipher(input) << std::endl;
        else if(choice == 1)
            std::cout << decipher(input) << std::endl;

        std::cout << "Press \"[ENTER]\" to run the program again or \"[CTRL] + [C]\" to quit.";
        std::cin.get();
    }
    return 0;
}
