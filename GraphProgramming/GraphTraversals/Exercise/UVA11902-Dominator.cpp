#include <iostream>
#include <vector>
using namespace std;

typedef vector<vector<bool>> vvi;

vector<bool> visited;
vector<bool> initial_reachable;
int V;

void dfs(vvi &graphMat, int v, int disabled = -1) {
    visited[v] = true;
    for (int i = 0; i < V; i++) {
        if (graphMat[v][i] && !visited[i] && i != disabled) {
            dfs(graphMat, i, disabled);
        }
    }
}

int main() {
    int T;
    cin >> T;
    int caseNumber = 1; // Separate case counter

    while (T--) {
        cin >> V;

        // Resize and initialize graph matrix
        vvi graphMat(V, vector<bool>(V, false));
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                int edge;
                cin >> edge;
                graphMat[i][j] = edge;
            }
        }

        // Perform initial DFS to determine reachability
        visited.assign(V, false);
        dfs(graphMat, 0);
        initial_reachable = visited;

        // Output case header
        cout << "Case " << caseNumber++ << ":\n";

        // Generate dominator matrix
        for (int i = 0; i < V; i++) {
            // Print top border for the row
            cout << "+";
            for (int j = 0; j < 2 * V - 1; j++) cout << "-";
            cout << "+\n|";

            for (int j = 0; j < V; j++) {
                if (initial_reachable[j]) {
                    visited.assign(V, false);
                    if (i == j) {
                        cout << "Y|"; // A vertex always dominates itself
                    } else {
                        dfs(graphMat, 0, i); // Disable vertex i and perform DFS
                        cout << (visited[j] ? "N" : "Y") << "|";
                    }
                } else {
                    cout << "N|"; // If not initially reachable, it cannot be dominated
                }
            }
            cout << "\n";
        }

        // Print bottom border
        cout << "+";
        for (int j = 0; j < 2 * V - 1; j++) cout << "-";
        cout << "+\n";
    }

    return 0;
}
