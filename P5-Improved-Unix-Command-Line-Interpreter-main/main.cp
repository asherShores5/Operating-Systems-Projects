#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <chrono>
using namespace std;

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
//Authors: Asher Shores & Philip Varkey
//Assignment: Project 2: Improved UNIX/Linux Command Line Interpreter
//Class: CST-315, Operating Systems Lecture & Lab
//Instructor: Ricardo Citro
//Date: February 18, 2022
//This is my own work
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

string login() {
  //login func for gaining root access ('su' command)
  string password;
  cout << "\nenter password:\t";
  cin >> password;

  //password for root is "root"
  if (password == "root") {
    return "root";
  } else {
    cout << "incorrect credentials";
    return "user";
  }
}

void print_stuff() {

  cout << "type 'whoami' to display current user\n";
  cout << "type 'su' to login as super user\n";
  cout << "type 'ls to see list of files in directory\n";
  cout << "type 'pwd' to see current location\n";
  cout << "type 'history' to see list of used commands\n";
  cout << "type 'df' to see available disk space for system\n"; 
  cout << "type ifconfig to view available network interfaces\n";
  cout << "type 'uptime' to view elapsed time of current session\n";
  cout << "type 'uname' to display core system information\n";
  cout << "type 'top' to display currently running processes\n";
  cout << "type 'clear' to clear the console\n";
  cout << "type 'help' to show a list of possible commands\n";
  cout << "type 'quit' to end session\n";
  return;
}

int main() {
  //initializing vars
  chrono::steady_clock::time_point begin = chrono::steady_clock::now();
  string UserInput;
  vector < string > seglist;
  string user = "user";
  string path = "/";
  vector < string > history;

  //welcomes and how to use greeting
  printf("Welcome to ConsoleConsole");
  printf("\ntype help for list of commands");

  //main loop that runs continuously
  while (true) {
    //---------
    seglist.clear(); //clear buffer of commands
    cout << "\n" + user + "$ "; //print for new command
    getline(cin, UserInput); //accept new input
    history.push_back(UserInput); //append history vector with cin
    //---------

    //parses through commands for multiple in sequence 
    stringstream test(UserInput);
    string segment;
    while (getline(test, segment, ';')) {
      seglist.push_back(segment);
    }
    //inner for loop for running through all buffered commands
    for (string UserInput: seglist) {
      //removes all spaces from input str
      UserInput.erase(remove(UserInput.begin(), UserInput.end(), ' '), UserInput.end()); 
      
      //'su' command allows root access
      if (UserInput == "su") {
        user = login();
        continue;
        // 'whoami' command identifies current user
      } else if (UserInput == "whoami") {
        cout << user << endl;
        continue;
        // 'help' command to list available commands
      } else if (UserInput == "help") {
        print_stuff();
        continue;
        // 'ls' command to display current directory files
      } else if (UserInput == "ls") {
        char cmd[50];
        strcpy(cmd, "ls");
        system(cmd);
        // 'pwd' cmd to show current location
      } else if (UserInput == "pwd") {
        char cmd[50];
        strcpy(cmd, "pwd");
        system(cmd);
        // 'history' cmd to display all used commands
      } else if (UserInput == "history") {
        for (string i: history)
          cout << i << endl;
       // 'clear' command to clear console
      } else if (UserInput == "clear") {
        cout << string(50, '\n');
      // 'quit' command to quit current session
      } else if (UserInput == "quit") {
        cout << "session terminated\n";
        exit(EXIT_FAILURE);
      // 'df' cmd to show disk space usage
      } else if (UserInput == "df") {
        char cmd[50];
        strcpy(cmd, "df");
        system(cmd);
      // 'ifconfig' cmd to view network interfaces
      } else if (UserInput == "ifconfig") {
        char cmd[50];
        strcpy(cmd, "ifconfig");
        system(cmd);
      // 'uname' cmd to view core system info
      } else if (UserInput == "uname") {
        char cmd[50];
        strcpy(cmd, "uname");
        system(cmd);
      // 'top' cmd to view current processes
      } else if (UserInput == "top") {
        char cmd[50];
        strcpy(cmd, "top");
        system(cmd);
      // 'uptime' cmd to view elapsed time
      } else if (UserInput == "uptime") {
        chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
        cout << "Elapsed Time = " << chrono::duration_cast<chrono::seconds>(end - begin).count() << " [seconds]" << endl;
      }

      // else catch-all for non-conforming commands
      else {
        cout << "\ncommand not found\n";
        continue;
      }

    } //loop back to for loop

  } //loop back to while(true) loop

  return 0;
  //end main
  //program should not be able to exit here however
}