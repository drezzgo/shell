#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <unistd.h>
#include "commands.h"

void executeCommand(const std::string& command, const std::vector<std::string>& args) {
    if (command == "ls") {
        listDirectory(args);
    }
    // Añade más comandos aquí.
    else {
        std::cerr << "Comando no encontrado: " << command << std::endl;
    }
}

int main() {
    std::string input;
    while (true) {
        std::cout << "myshell> ";
        if (!std::getline(std::cin, input)) break;
        
        std::istringstream iss(input);
        std::vector<std::string> tokens;
        std::string token;
        while (iss >> token) {
            tokens.push_back(token);
        }
        
        if (!tokens.empty()) {
            std::string command = tokens[0];
            tokens.erase(tokens.begin());
            executeCommand(command, tokens);
        }
    }
    return 0;
}