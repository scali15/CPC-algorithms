#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>


using namespace std;

int main() {

    string line;
    while (getline(cin, line)) {
        if (line == "0 0 0"){ break; }

        istringstream iss(line);
        int a, b, c;
        iss >> a >> b >> c;
        int arr[3] = {a, b, c};  // Put a, b, and c into an array
        sort(arr, arr + 3);
        a = arr[0]; b = arr[1]; c = arr[2];
        a *= a; b *= b; c *= c;
        if ( (a + b) == c){
            cout << "right\n";
        }
        else{
            cout << "wrong\n";
        }
    }

    return 0;
}