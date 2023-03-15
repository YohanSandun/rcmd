#ifndef COMMAND_H
#define COMMAND_H

#include <iostream>

class Command
{
    public:
        Command(std::string name, std::string command);
        virtual ~Command();

        std::string getName();
        std::string getCommand();

    private:
        std::string name_;
        std::string command_;
};

#endif // COMMAND_H
