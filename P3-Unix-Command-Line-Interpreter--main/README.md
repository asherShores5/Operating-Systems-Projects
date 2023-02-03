#Project 1: Unix/Linux Command Line Interpreter 

Asher Shores & Philip Varkey
CST-315 - Operating Systems Lecture & Lab
Dr. Ricardo Citro
February 6th, 2022
This is our own work.

# Running the program .cpp
1. Download included zip file
2. Download g++
3. No non-default libs needed
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

"type 'whoami' to display current user\n";
"type 'su' to login as super user\n";
"type 'ls to see list of files in directory\n";
"type 'pwd' to see current location\n";
"type 'history' to see list of used commands\n";
"type 'clear' to clear the console\n";
"type 'quit' to end session\n";

Commands can be entered sequentially separated by semicolons
Each command while be queue and executed after the prior
i.e. "whoami ; pwd ; history"

