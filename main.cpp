#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>

#include "Command.h"

#define VERSION "1.0.1"
#define FILENAME "commands.txt"

void print_welcome();
std::vector<Command> load_commands();

int main(int argc, char** argv)
{
    if (argc <= 1) {
        print_welcome();
        return 0;
    }

    std::vector<Command> commands = load_commands();
    if (argc == 2) {
        std::string arg(argv[1]);
        for (Command command : commands) {
            if (command.getName() == arg) {
                system(command.getCommand().c_str());
                return 0;
            }
        }
    }

    std::cout << "Command not found!" << std::endl;
    return 0;
}

void print_welcome() {
    std::cout << "RCMD [Version " << VERSION << ']' << std::endl;
    std::cout << std::endl;
    std::cout << "Usage:" << std::endl;
    std::cout << "\trcmd <command_name>" << std::endl;
}

std::vector<Command> load_commands() {
    std::string filename = FILENAME;
    std::ifstream infile(filename);
    std::vector<Command> commands;

    if (!infile.is_open()) {
        std::cout << "ERROR: Could not open file " << filename << std::endl;
        return commands;
    }

    std::string line;
    while (std::getline(infile, line)) {

        // Remove leading whitespaces
        line.erase(line.begin(), find_if(line.begin(), line.end(), [](unsigned char ch) {
            return !isspace(ch);
        }));

        // Remove trailing whitespaces
        line.erase(find_if(line.rbegin(), line.rend(), [](unsigned char ch) {
            return !isspace(ch);
        }).base(), line.end());


        // Checking for comment liens or empty lines
        if (line.length() == 0 || line[0] == '#') {
            continue;
        }

        size_t pos = line.find(' ');
        if (pos != std::string::npos) {
            commands.push_back(Command(line.substr(0, pos), line.substr(pos + 1)));
        } else {
            std::cout << "ERROR: Unstructured commands found in the file." << std::endl;
        }
    }
    infile.close();

    return commands;
}
