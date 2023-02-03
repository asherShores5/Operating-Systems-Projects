#Project 2: Improved Unix/Linux Command Line Interpreter 

Asher Shores & Philip Varkey
CST-315 - Operating Systems Lecture & Lab
Dr. Ricardo Citro
February 20th, 2022
This is our own work.

# Running the program .cpp
1. Download included zip file
2. Download g++
3. Please ensure the following libs are installed
<stdio.h>
<stdlib.h>
<string>
<iostream>
<sstream>
<vector>
<algorithm>
<string.h>
<chrono>
4. Open zip file and locate .cpp file
5. Determine file's location
6. Open the terminal & navigate to the file location
7. Run "g++ -o [Executable FileName] main.cpp"
8. Above command will generate a executable with the filename given
9. Run "./[FileName]

Alternatively simply run the executable file including called "exec"

//----------//

When running the program, use "help" to display all commands
Here is "help"s output

"type 'whoami' to display current user
"type 'su' to login as super user
"type 'ls to see list of files in directory
"type 'pwd' to see current location
"type 'history' to see list of used commands
"type 'df' to see available disk space for system 
"type ifconfig to view available network interfaces
"type 'uptime' to view elapsed time of current session
"type 'uname' to display core system information
"type 'top' to display currently running processes
"type 'clear' to clear the console
"type 'help' to show a list of possible commands
"type 'quit' to end session

#Terminal Commands Available
1. whoami
2. su
3. ls
4. pwd
5. history
6. df
7. ifconfig
8. uptime
9. uname
10. top
11. clear
12. help
13. quit

#Note for cmd top
Cmd top uses system() to display processes. It runs continously and must be exited using q. 

Commands can be entered sequentially separated by semicolons
Each command while be queue and executed after the prior
i.e. "whoami ; pwd ; history"

