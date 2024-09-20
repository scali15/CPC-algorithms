#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> generate(int numRows) {
    vector<vector<int>> pyramid;

    pyramid.push_back(vector<int>(1, 1));

    for (int i = 1; i < numRows; i++){
        vector<int> currentRow;
        for (int j = 0; j <= i; j++){
            if (j == 0)
                currentRow.push_back(1);
            else if (j == i)
                currentRow.push_back(1);
            else{
                currentRow.push_back(pyramid[i-1][j-1] + pyramid[i-1][j]);
            }
        }
        pyramid.push_back(currentRow);
    }
    return pyramid;
}

int main(){
    int numRows;
    cin >> numRows;
    vector<vector<int>> ans = generate(numRows);

    for (int i = 0; i < numRows; i++){
        for (int j = 0; j < ans[i].size(); j++){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}