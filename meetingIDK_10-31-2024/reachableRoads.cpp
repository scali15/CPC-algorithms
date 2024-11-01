#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> nodes;
vector<bool> visit;

void bfs(int start) {
    queue<int> q;
    q.push(start);
    visit[start] = true;

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        for (int neighbor : nodes[current]) {
            if (!visit[neighbor]) {
                visit[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}

int main() {
    int n;
    cin >> n;
    while (n-- > 0) {
        int m, r;
        cin >> m;
        visit.assign(m, false);
        nodes.assign(m, vector<int>());

        cin >> r;
        for (int i = 0; i < r; i++) {
            int a, b;
            cin >> a >> b;
            nodes[a].push_back(b);
            nodes[b].push_back(a);
        }

        int count = 0;
        for (int i = 0; i < m; i++) {
            if (!visit[i]) {
                count++;
                bfs(i);
            }
        }
        cout << count - 1 << endl;
    }

    return 0;
}