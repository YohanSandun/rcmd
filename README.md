# RCMD
 Command line tool to save and run commands from anywhere.

## Installation
 **Windows**  
   
 [![CDNJS](https://img.shields.io/badge/Download%20for-Windows-brightgreen)](https://github.com/YohanSandun/rcmd/releases/download/V1.0.1/rcmd-windows.zip)  
 [Download](https://github.com/YohanSandun/rcmd/releases/download/V1.0.1/rcmd-windows.zip) the binaries for the latest release. Extract the downloaded zip file into a permanent location such as `c:\rcmd\`. Then add that path as a entry in the Path environment variable.  
 Open command prompt and type `rcmd` and hit enter to see wheter it's working. If it's working file it should print the rcmd version to the screen.
   
------
 **Linux**
   
 [![CDNJS](https://img.shields.io/badge/Download%20for-Linux-blue)](https://github.com/YohanSandun/rcmd/releases/download/V1.0.1/rcmd-linux.zip)  
 [Download](https://github.com/YohanSandun/rcmd/releases/download/V1.0.1/rcmd-linux.zip) the binaries for the latest release. Extract the downloaded zip file into a location such as '/home/rcmd/'. Then run following command to create a shortcut for rcmd. Assume that rcmd binaries are in the path `/home/user/rcmd/`.
 
    alias rcmd=/home/user/rcmd/rcmd

 Open terminal and type `rcmd` and hit enter to see wheter it's working. If it's working file it should print the rcmd version to the screen.

-----

## Usage 
 With rcmd executable you will get a file called commands.txt. This file contains all your commands. You can edit the file using a text editor such as Notepad. All the commands should follow following format
 
    <command_name> <actual command>

 eg:  

    hello echo "Hello World"

 Here `hello` is the command name and `echo "Hello World"` is the actual command.  

------
  
**Comments**  
You can add comments to the commands file using #.

eg:  

    # This is a comment

------

**Arguments**  
You can pass arguments to the commands using $(ARG) placeholder.

eg:  

    # hello echo "Hello, $(ARG) $(ARG)"
    # # Above hello command expecting two arguments and we can call it as follows,
    # # rcmd hello Jane Doe
    # # $(ARG) placeholders will replace with corresponding argument. If there are less or more arguments are passed than expected, the command is not executed.

------
**Current Directory**  
You can get the current working directoy path by refering to `$(CPATH)` placeholder which is provided by rcmd.
  
eg:  

    hello mkdir $(CPATH)\hello

Above command creates a directory called hello in current path.