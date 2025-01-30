#include<iostream>
using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
vi dfs_num;
const auto UNVISITED=0;
const auto VISITED=1;
const auto EXPLORED=2;
vi dfs_parent;

void graphCheck(vector<vii> &adjlist, int u) {
    dfs_num[u] = EXPLORED;  // Mark current node as "being explored"

    for (int i = 0; i < (int)adjlist[u].size(); i++) {
        ii v = adjlist[u][i];  // Get adjacent vertex
        
        if (dfs_num[v.first] == UNVISITED) {  // Tree Edge
            dfs_parent[v.first] = u;
            cout << "Tree Edge (" << u << ", " << v.first << ")\n";
            graphCheck(adjlist, v.first);
        } else if (dfs_num[v.first] == EXPLORED) {  // Back Edge
            if (v.first == dfs_parent[u]) {
                // Ignore the bidirectional case for undirected graphs
                cout << "Two-way Edge (" << u << ", " << v.first << ")\n";
            } else {
                cout << "Back Edge (" << u << ", " << v.first << ") (Cycle)\n";
            }
        } else if (dfs_num[v.first] == VISITED) {  // Forward or Cross Edge
            if (v.first != dfs_parent[u]) {
                cout << "Forward/Cross Edge (" << u << ", " << v.first << ")\n";
            }
        }
    }

    dfs_num[u] = VISITED;  // Mark current node as "fully visited"
}


int main(){
    int v, e;
    cin>>v>>e;
    vector<vii> adjlist(v);
    dfs_num.assign(v,UNVISITED);
    dfs_parent.assign(v, INT_MAX);
    for(int i=0;i<e;i++){
        int u,v;
        cin>>u>>v;
        adjlist[u].push_back(ii(v,i));
    }
    for (int i = 0; i < v; i++) {
        if (dfs_num[i] == UNVISITED) {
            graphCheck(adjlist, i);
        }
    }

    return 0;
}