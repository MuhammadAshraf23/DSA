#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

int main() {
    string find;
    cout << "Enter the cloth you have to find: ";
    getline(cin, find);

    // Split the input string into two parts
    stringstream ss(find);
    string a, b;
    ss >> a >> b;

    // Open the cupboard.txt file to read
    ifstream inputFile("cupboard.txt");
    if (!inputFile.is_open()) {
        cout << "The file cupboard.txt was not found." << endl;
        return 1;
    }

    // Open the available.txt file to write
    ofstream outputFile("available.txt", ios::app); // 'ios::app' to append to the file
    if (!outputFile.is_open()) {
        cout << "An error occurred while opening available.txt for writing." << endl;
        return 1;
    }

    string line;
    bool found = false;

    // Read through each line in cupboard.txt
    while (getline(inputFile, line)) {
        if (line.find(a) == 0 && line.rfind(b) == line.length() - b.length()) {
            outputFile << line << endl;  // Write matching line to available.txt
            cout << "Cloth found: " << line << endl; // Display message when item is found
            found = true;
        }
    }

    // If no matching item was found
    if (!found) {
        cout << "No matching item found." << endl;
    }

    // Close files
    inputFile.close();
    outputFile.close();

    return 0;
}
