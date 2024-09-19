#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm> // for sort and max
#include <functional> // for greater<int>()

using namespace std;

int main() {   
    int n;
    cin >> n;
    cin.ignore();
    
    string line;
    getline(cin, line);  // Read a line of input

    istringstream iss(line);
    vector<int> numbers;
    int num;

    // Parse the line and add integers to the vector
    while (iss >> num) {
        numbers.push_back(num);
    }

    sort(numbers.begin(), numbers.end(), greater<int>());
    int maxTime = 0;
    for (int i = 1; i <= n; i++){
        maxTime = max(maxTime, numbers[i-1] + i);
    }
    maxTime += 1;
    cout << maxTime;
    return 0;
}