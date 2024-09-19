#include <iostream>
#include <queue>
#include <vector>
#include <sstream>

using namespace std;

// Define custom comparator for min heap sorted by narrowest to widest range of minions preferred tempuratures
auto cmp1 = [](const pair<int, int>& a, const pair<int, int>& b) {
    // Compare pairs by the second element, time willing to wait
    return (a.second - a.first) > (b.second - b.first);
};

// Function to count the number of minions a certain integer value will satisy
int skewerCount(priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp1)> rectangles, int skewer){
    int count = 0;
    while(!rectangles.empty()){
        if (skewer >= rectangles.top().first && skewer <= rectangles.top().second){
            count++;
        }
        rectangles.pop();
    }
    return count;
}

void removeStabbed(priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp1)>& rectangles, int skewer){
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp1)> rCopy(cmp1);
    rectangles.swap(rCopy);
    while(!rCopy.empty()){
        pair<int, int> curr = rCopy.top();
        rCopy.pop();
        if (skewer < curr.first || skewer > curr.second){
            rectangles.push(curr);
        }
    }
}

int main() {

    /* ALMOST DONE, JUST GOTTA DO THE INPUT AND THIS SHOULD WORK 
    
    FINISH LATER THOUGH BECAUSE I GOTTA GET TO SOFTWARE ENGINEERING CLASS */

    // Min heap implemented with priority queue below
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp1)> preferredTemps(cmp1);
    // sorted queue ordered 
    priority_queue preferredTempsCopy(preferredTemps);
    vector<pair<int, int>> rectangles;

    pair<int, int> strictestMinion;
    int numSkewers = 0;
    while(!preferredTemps.empty()){
        numSkewers++;
        strictestMinion = preferredTemps.top();
        preferredTemps.pop();

        int mostStabbed = -1;
        int stabCount = 0;
        int bestSkewer;
        for (int i = strictestMinion.first; i <= strictestMinion.second; i++){
            stabCount = skewerCount(preferredTemps, i);
            if (stabCount > mostStabbed){
                mostStabbed = stabCount;
                bestSkewer = i;
            }
        }
        removeStabbed(preferredTemps, bestSkewer);
    }

    cout << numSkewers;
    return 0;
}
