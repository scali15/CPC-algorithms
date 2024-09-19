#include <iostream>
#include <fstream>
#include <string>
#include <sstream>


using namespace std;

int main() {
    ifstream inputFile("input.txt"); // Open the input file
    if (!inputFile) {
        cerr << "Error opening file!" << endl;
        return 1;
    }

    string line;
    while (getline(inputFile, line)) {
        if (line == "0 0 0"){ break; }

        istringstream iss(line);
        int a, b, c;
        iss >> a >> b >> c;
        a *= a; b *= b; c *= c;
        if ( (a + b) == c){
            cout << "right\n";
        }
        else{
            cout << "wrong\n";
        }
    }

    inputFile.close(); // Close the file after reading
    return 0;
}