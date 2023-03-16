# RCMD
 Command line tool to save and run commands from anywhere.

## Installation
 **Windows**  
   
 [![CDNJS](https://img.shields.io/badge/Download%20for-Windows-brightgreen)]()  
 1. Download the binaries for the latest release.
 2. Extract the downloaded zip file into a permanent location such as `c:\rcmd\`.
 3. Then add that path as a entry in the Path environment variable. Don't know how to add/edit environment variables? Google it.
 4. Open command prompt and type rcmd and hit enter to see wheter it's working. If it's working file it should print the rcmd version to the screen.
   
 **Linux**
   
 [![CDNJS](https://img.shields.io/badge/Download%20for-Linux-blue)]()  
 1. Download the binaries for the latest release.
 2. Extract the downloaded zip file into a location such as '/home/rcmd/'.
 3. Then run following command to create a shortcut for rcmd. Assume that rcmd binaries are in the path `/home/rcmd/`

    alias rcmd=/home/rcmd/rcmd

 4. Open command prompt and type rcmd and hit enter to see wheter it's working. If it's working file it should print the rcmd version to the screen.
  
## Usage
 With rcmd executable you will get a file called commands.txt. This file contains all your commands. You can edit the file using a text editor such as Notepad. All the commands should follow following format
 
    <command_name> <actual command>

 eg:  
    `hello echo "Hello World"`  
 Here `hello` is the command name and `echo "Hello World"` is the actual command.  

------
  
**Comments**  
You can add comments to the commands file using #.

eg:  
 `# This is a comment`

------
**Current Directory**  
You can get the current working directoy path by refering to `$(CPATH)` variable which is provided by rcmd.
  
eg:  
`hello mkdir $(CPATH)\hello`  
Above command creates a directory called hello in current path.