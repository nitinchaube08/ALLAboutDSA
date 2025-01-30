#include <iostream>
#include <vector>
#include <string>
using namespace std;

void dfs(vector<vector<int> > &adj, int i, vector<bool> &visited) {
    visited[i] = true;
    for (int neighbor : adj[i]) {
        if (!visited[neighbor]) {
            dfs(adj, neighbor, visited);
        }
    }
}

int main() {
    int T;
    cin >> T;
    cin.ignore(); // Ignore the newline after the number of test cases

    while (T--) {
        char LargestNode;
        cin >> LargestNode;
        cin.ignore(); // Ignore the newline after LargestNode input

        int n = LargestNode - 'A' + 1;
        vector<vector<int> > adj(n);
        vector<bool> visited(n, false);

        string edge;
        while (getline(cin, edge) && !edge.empty()) {
            int u = edge[0] - 'A';
            int v = edge[1] - 'A';
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int connectedComponent = 0;
        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                ++connectedComponent;
                dfs(adj, i, visited);
            }
        }

        cout << connectedComponent << endl;
        if (T) {
            cout << endl;
        }
    }

    return 0;
}
