
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