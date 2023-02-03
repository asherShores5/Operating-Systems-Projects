#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;

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
  cout << "type 'clear' to clear the console\n";
  cout << "type 'quit' to end session\n";
  return;
}

int main() {

  //initializing vars
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
      }
      // 'clear' command to clear console
      else if (UserInput == "clear") {
        cout << string(50, '\n');
      } else if (UserInput == "quit") {
        cout << "session terminated\n";
        exit(EXIT_FAILURE);
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