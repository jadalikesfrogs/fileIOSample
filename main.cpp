
#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ofstream myDataFile;          // declare an object for the output file
    ifstream mySourceFile;        // declare an object for the input file
    double averageFromFile = 0.0; // somewhere to store our average.

    /* get exactly 5 integers from the user and write them to a file called data.txt */
    myDataFile.open("data.txt", ios::app);
    for (int i = 0; i < 5; i++) {
        int anInteger = 0;
        cin >> anInteger;
        myDataFile << anInteger << endl;
    }
    myDataFile.close();

    /* get exactly 5 integers from a file called data.txt and print the average to console */
    mySourceFile.open("data.txt");
    if (!mySourceFile.fail()) {
        for (int i = 0; i < 5; i++) {
            int anInteger = 0;
            mySourceFile >> anInteger;
            if (mySourceFile.fail()) {
                break; // assume I cannot recover and must exit the loop?
            }
            averageFromFile += static_cast<double>(anInteger);
        }
        mySourceFile.close();
        averageFromFile /= 5.0;
        cout << "The average from the file is " << averageFromFile << endl;
    }

    /* get all the integers from a file called data.txt and print the average to console */
    int numItems = 0;
    mySourceFile.open("data.txt");
    if (!mySourceFile.fail()) {
        while (!mySourceFile.eof() && !mySourceFile.fail()) {
            int anInteger = 0;
            mySourceFile >> anInteger;
            if (mySourceFile.fail()) {
                break; // assume I cannot recover and must exit the loop?
            }
            numItems++;
            averageFromFile += static_cast<double>(anInteger);
        }
        mySourceFile.close();
        averageFromFile /= static_cast<double>(numItems);
        cout << "The average from the file is " << averageFromFile << endl;
    }




    return 0;
}
//NEW SAMPLE 
/*
* 


* Typewriter program from slide deck 6.2
*
* @file main.cpp
* @author Stephen Graham
* @date   2024-10-09
* @brief  copy text from keyboard to file
*
*/
//#include <iostream> // std::cin, std::cout
//#include <fstream>  // std::ofstream
//#include <string>   // std::string
//using namespace std;

/*
* Open a file specified by the user and attach it to a stream object
*
* @return   none
* @param[in,out]  ofstream& ofs is the stream to be opened
*/
//void open(ofstream& ofs);

/*
* Copy the console input to the output stream specified
*
* @return none
* @param[in,out]  ofstream& ofs is the stream to be "fed"
* @post           file attached to ofs has 0 or more characters inserted
* @post           cin has had 0 or more characters removed

void copyKeyboardTo(ofstream& ofs);

int main() {
    ofstream targetFile;

    // open a user-specified file
    open(targetFile);

    // copy text until ~ character
    copyKeyboardTo(targetFile);

    // close
    targetFile.close();

    return 0;
}

void open(ofstream& ofs) {
    // todo: what error checking do I need?
    string filename;

    // get a filename
    cout << "Target file? ";
    cin >> filename;

    // what if the file already exists?samp
    // what if the open operation fails?
    // open the file
    ofs.open(filename.c_str());

    cout << "Opened the file" << endl;
}

void copyKeyboardTo(ofstream& ofs) {
    // get a char from the console input
    // while the current character is not ~ 
        // put the character in the file
        // get another char from console
    char aCharacter = '\0';

    cin.get(aCharacter);

    while (aCharacter != '~' && !cin.fail() && !ofs.fail()) {
        ofs.put(aCharacter);
        cin.get(aCharacter);
    }

    cout << "Copied to the file" << endl;
}
*/