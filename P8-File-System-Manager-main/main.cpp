#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <chrono>
#include <bits/stdc++.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fstream>
#include <unistd.h>

using namespace std;

//initialize variables
int fileCounter = 1;
int DirCounter = 1;
string fileName[12] = {};

class directory{
public:
    string path;
    string user;
    string dirName;
    class file;
    int numFiles;
    ~directory();
};

directory::~directory()
{
    path = "";
    user = "";
    dirName = "";
    int numFiles = 0;
}

class file{
public:
    int memory;
    string author;
    string name;
    string location;
    ~file();
};
file::~file()
{
    author = "";
    name = "";
    location = "";
    int memory = 0;
}
file files[12];

//creates the directory and outputs the name to the user
void DirCreate()
{
    string dCreate;

    //Asks the user for the directory name
    cout << "Please enter the name for the directory: ";
    getline(cin,dCreate);

    //Makes the new directory using the mkdir
    directory Create;

    cout << "the new directory is called " << dCreate << endl;
}

//changes to a new directory and outputs the name to the user
void directoryChange()
{
    const char *dirNew;
    //asks the user for the new directory
    cout << "Please enter the new directory: ";
    mkdir(dirNew);
    chdir(dirNew);
    cout << "the directory is now in " << dirNew << endl;
}

void DirRename()
{
    //asks the user for the directory name and the new file
    string name;
    string newName;
    cout<< "Please give the directory name: ";
    getline(cin, name);
    cout<< "Please give the new directory name: ";
    getline(cin, newName);
    name = newName;
    cout << "the directory is now called " << newName << endl;
}


void DirDuplicate(){
    string change;
    //asks the user for the directory that wants to be changed
    cout<< "give the directory that you want changed: ";
    getline(cin, change);
    string val = to_string(DirCounter);

    //appends the counter to the name and sets the directory's name
    change.append(val);
    directory direct;
    direct.dirName = change;
    //adds to the counter
    DirCounter++;
    cout << "the duplicated directory is called " << change << endl;
}

//Delete directories
void removeDir()
{
    string oldDir;
    //asks the user for the directory and then deletes it
    cout << "please provide the directory that you want to delete: ";
    getline(cin, oldDir);
    //oldDir.~directory();
    cout << "the directory has been deleted" << endl;

}

//gets the information about a directory
void dirProperties()
{
    string dirProp;
    cout << "please provide the directory: ";
    getline(cin, dirProp);
    cout << "Name: " << dirProp << endl;
}

// detailed information about a directory
void dirPropertiesDetailed()
{
    string dirPropD;
    cout << "please provide the directory: ";
    getline(cin, dirPropD);
    // outputs the values found for the directory
    cout << "Name: " << dirPropD << endl;
    cout << "Author: User" << endl;
}

//renames the file
void fileRename()
{
    string oldName;
    cout<< "Please give the old file name: ";
    getline(cin,oldName);

    string newName;
    cout << "Please give the new file name: ";
    getline(cin,newName);
    //sets the new name onto the old name
    newName = oldName;

    cout << " The file has been renamed to " << newName << endl;
}

void removeFile(file file)
{
    //calls on the deconstructor
    file.~file();
    cout << "file has been deleted" << endl;
}

//creates a file
void fileCreate()
{
    string initial;
    cout<< "please give the name of the file that you want to create: ";
    getline(cin, initial);
    //randomly assigns the memory
    int mem = rand()%2048 + 1;
    file file1;
    file1.author = "user";
    file1.memory = mem;
    file1.name = initial;
    //adds the fle to the list
    fileName[fileCounter-1] = initial;
    //outputs the file bytes
    cout << "the number of bytes for this file is" << file1.memory << endl;
}

//Duplicate files
void FileDuplicate(){
    string chan;
    cout<< "give the file that you want changed: ";
    getline(cin, chan);
    //creates the file with the new name added based on the fileCounter
    string val = to_string(fileCounter);
    file Dupfile;
    chan.append(val);
    Dupfile.name = chan;
    fileCounter++;
}

//basic information about a file
void fileProperties()
{
    //outputs the file's information from the name
    string fileprop;
    cout << "please provide the file that you want to see: ";
    getline(cin,fileprop);
    cout << "Name: " << fileprop << endl;
    cout << "Author: user "<< endl;
}

//detailed information about a file
void filePropertiesDetailed()
{
    //outputs the file's detailed information from its name
    string filepropd;
    cout << "please provide the file that you want to see: ";
    getline(cin, filepropd);
    cout << "Name: " << filepropd << endl;
    cout << "Author: user "<< endl;
    cout << "location: system" << endl;

}

//Move files across directories
void fileMove(file fileMove)
{
    //asks the user for the new directory and moves the file to that area
    string move;
    cout<< "please give the directory path that you want the file moved to: ";
    getline(cin, move);
    fileMove.location = move;
}

void functionlist()
{
    // Outputs all function options to the user
    cout << "all functions:" << endl;
    cout << "create a file by typing new" << endl;
    cout << "duplicate a file by typing duplicate" << endl;
    cout << "delete a file by typing delete" << endl;
    cout << "rename a file by typing rename" << endl;
    cout << "create a new directory by typing directory" << endl;
    cout << "move a file by typing move" << endl;
    cout << "search a file by typing the file name" << endl;
    cout << "to learn about a file type properties" << endl;
    cout << "to learn about a file's details type properties-" << endl;
    cout << "to see the current directory type directory" << endl;
    cout << "to view the directory properties type directoryprop" << endl;
    cout << "to view the detailed directory properties type directoryprop-" << endl;
    cout << "to rename the directory type directoryrename" << endl;
    cout << "to duplicate the directory type DirDuplicate" << endl;
    cout << "to remove the directory type removeDir" << endl;
    cout << "to exit enter exit" << endl;
}

int main() {
    //initializes all variables
    srand(time(NULL));
    string userInput;

    //while loop to constantly output different results
    while(true)
    {
        //calls on the function to list all possible values
        functionlist();
        string userInput;
        getline(cin, userInput);
        string ready;

        //if statement to check the user's input
        if(userInput == "new")
        {
            fileCreate();
        }
        else if(userInput == "duplicate")
        {
            FileDuplicate();

        }
        else if(userInput == "delete")
        {
            string removing;
            cout << "please give the name of the file to be deleted" << endl;
            getline(cin, removing);
            for (int check = 0; check < 12; check++) {
                if (removing == fileName[check])
                {
                    file deadfile;
                    removeFile(deadfile);
                }
            }
        }
        else if(userInput == "rename")
        {
            fileRename();
        }
        else if(userInput == "directory")
        {
            DirCreate();
        }
        else if(userInput == "move")
        {
            file file;
            fileMove(file);
        }
        else if(userInput == "properties")
        {
            fileProperties();
        }
        else if(userInput == "properties-")
        {
            filePropertiesDetailed();
        }
        else if(userInput == "directoryprop")
        {
            dirProperties();
        }
        else if(userInput == "directoryprop-")
        {
            directory directory1;
            dirProperties();
        }
        else if(userInput == "directorychange")
        {
            directoryChange();
        }
        else if(userInput == "directoryrename")
        {
            DirRename();
        }
        else if(userInput == "DirDuplicate")
        {
            DirDuplicate();
        }
        else if(userInput == "removeDir")
        {
            removeDir();
        }
        else
        {
            //Outputs a answer to the user for a improper input
            cout << "invalid syntax: please enter a given command" << endl;
        }
    }

    return 0;

}
