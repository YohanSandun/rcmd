#include "Command.h"

Command::Command(std::string name, std::string command)
{
    name_ = name;
    command_ = command;
}

Command::~Command()
{
    //dtor
}

std::string Command::getName() {
    return name_;
}

std::string Command::getCommand() {
    return command_;
}
