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


// Function to count the number of minions a certain integer value will satisfy
int skewerCount(priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp1)>& rectangles, int skewer){
    int count = 0;
    vector<pair<int, int>> copy;
    while(!rectangles.empty()){
        if (skewer >= rectangles.top().first && skewer <= rectangles.top().second){
            count++;
        }
        copy.push_back(rectangles.top());
        rectangles.pop();
    }
    for (const auto& rec : copy){
        rectangles.push(rec);
    }
    return count;
}

void removeStabbed(priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp1)>& rectangles, int skewer){
    vector<pair<int, int>> intactRectangles;

    while(!rectangles.empty()){
        pair<int, int> curr = rectangles.top();
        rectangles.pop();
        if (skewer < curr.first || skewer > curr.second){
            intactRectangles.push_back(curr);
        }
    }
    for (const auto& rectangle : intactRectangles){
        rectangles.push(rectangle);
    }
}

int main() {

    // Min heap implemented with priority queue below
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp1)> preferredTemps(cmp1);

    int n;
    cin >> n;

    int x, y;
    for (int i = 0; i < n; i++){
        cin >> x >> y;
        preferredTemps.push(pair<int, int>(x, y));
    }

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
