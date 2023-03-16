#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>
#include <unistd.h>

#ifdef _WIN32
#include <Windows.h>
#endif

#include "Command.h"

#define VERSION "1.0.1"
#define FILENAME "commands.txt"

const std::string VAR_CPATH = "$(CPATH)";

void print_welcome();
std::vector<Command> load_commands(std::string);
std::string get_exec_path();

int main(int argc, char** argv)
{
    if (argc <= 1) {
        print_welcome();
        return 0;
    }

    std::vector<Command> commands = load_commands(get_exec_path() + FILENAME);
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

std::vector<Command> load_commands(std::string filename) {
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


        // Checking for comment lines or empty lines
        if (line.length() == 0 || line[0] == '#') {
            continue;
        }

        size_t pos = line.find(' ');
        if (pos != std::string::npos) {
            size_t path_pos = line.find(VAR_CPATH);
             if (path_pos != std::string::npos) {
                char cwd[1024];
                if (getcwd(cwd, sizeof(cwd)) != NULL) {
                    line.replace(path_pos, VAR_CPATH.length(), cwd);
                } else {
                    std::cout << "ERROR: Error while reading the current working directory." << std::endl;
                    break;
                }
            }

            commands.push_back(Command(line.substr(0, pos), line.substr(pos + 1)));
        } else {
            std::cout << "ERROR: Unstructured commands found in the file." << std::endl;
        }
    }
    infile.close();

    return commands;
}

std::string get_exec_path() {
    char exePath[1024];
    std::string exeDir = "";
#ifdef _WIN32
    GetModuleFileName(NULL, exePath, 1024);
#else
    ssize_t len = readlink("/proc/self/exe", exePath, sizeof(exePath));
    if (len != -1) {
        exePath[len] = '\0';
    }
#endif

    std::string pathString(exePath);
    size_t lastSlashPos = pathString.find_last_of("/\\");
    if (lastSlashPos != std::string::npos) {
        exeDir = pathString.substr(0, lastSlashPos + 1);
    }

    return exeDir;
}