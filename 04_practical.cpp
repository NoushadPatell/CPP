/*
Write a C++ program that creates an output file, writes information to it, closes the file, open it again as an input file and read the information from the file.
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    // Creating an output file
    ofstream outputFile("example.txt");

    // Writing information to the file
    if (outputFile.is_open()) {
        outputFile << "Hello, this is written to the file!\n";
        outputFile << "Additional line of information.\n";
        outputFile.close();
        cout << "Data written to the file successfully.\n";
    } else {
        cerr << "Unable to open the output file.\n";
        return 1;
    }

    // Opening the file as an input file and reading information
    ifstream inputFile("example.txt");

    if (inputFile.is_open()) {
        cout << "\nReading from the file:\n";
        string line;
        while (getline(inputFile, line)) {
            cout << line << endl;
        }
        inputFile.close();
    } else {
        cerr << "Unable to open the input file.\n";
        return 1;
    }

    return 0;
}
