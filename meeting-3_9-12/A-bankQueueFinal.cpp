#include <iostream>
#include <queue>
#include <vector>
#include <sstream>

using namespace std;

int main() {   
    // Define a priority queue with pairs and a custom comparator
    auto cmp1 = [](const pair<int, int>& a, const pair<int, int>& b) {
        // Compare pairs by the second element, time willing to wait
        return a.second > b.second;
    };

    auto cmp2 = [](const pair<int, int>& a, const pair<int, int>& b) {
        // Compare pairs by the first element, amount of money
        return a.first > b.first;
    };

    // sorted heap of customers by wait time smallest-greatest
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp1)> minHeap(cmp1);
    // sorted heap of the T customers that end up being served by money least-most
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp2)> wealthyCustomers(cmp2);
    
    string line;
    getline(cin, line);  // Read a line of input

    istringstream iss(line);
    int n, time;
    iss >> n >> time;

    for (int i = 0; i < n; i++){
        getline(cin, line);
        int money, wait;
        istringstream cust(line);
        cust >> money >> wait;
        minHeap.push({money, wait});
    }
    vector<pair<int, int>> customers;
    while (!minHeap.empty()) {
        customers.push_back(minHeap.top());
        minHeap.pop();
    }
    int numServed = 0;
    int currentTime = 0;
    for (pair<int, int> customer : customers) {
        currentTime = max(currentTime, customer.second);
        if (numServed <= currentTime){
            wealthyCustomers.push(customer);
            numServed++;
            // cout << "Added customer with $" << customer.first << endl;
        }
        else if (customer.first > wealthyCustomers.top().first){
            // cout << "Removed customer with $" << wealthyCustomers.top().first << endl;
            wealthyCustomers.pop();
            wealthyCustomers.push(customer);
            // cout << "Added customer with $" << customer.first << endl;
        }
        // else customer doesnt have more money than the poorest customer we might serve, so they are ignored
    }
    int moneySum = 0;
    while(!wealthyCustomers.empty()) {
        moneySum += wealthyCustomers.top().first;
        wealthyCustomers.pop();
    }
    cout << moneySum;
}