#include<iostream>
using namespace std;

typedef vector<int> vi;
typedef vector<vector<int> > vii;

bool dfs(vii &adjList, int node, vi &color, int col){
    color[node]=col;

    for(int neighbor: adjList[node] ){
        if(color[neighbor]==-1){
            if(!dfs(adjList, neighbor, color, 1-col)){
                return false;
            }
        } else if(color[neighbor] == color[node]){
            return false;
        }
    }
    return true;
}

bool isBipartite(vii &adjList, int v, vi &color){
    for(int i=0;i<v; i++){
        if(color[i]==-1){
            if(!dfs(adjList, i, color,0)){
                return false;
            };
        }
    }
    return true;
}

int main(){
    int v, e;
    cin>>v>>e;
    vii adjList(v);
    for(int i=0;i<e; i++){
        int u, j;
        cin>>u>>j;
        adjList[u].push_back(j);
        adjList[j].push_back(u);
    }
    vi color(v,-1);
    if (isBipartite(adjList, v, color)) {
        cout << "The graph is bipartite.\n";
        cout << "Vertex colors (0 and 1):\n";
        for (int i = 0; i < v; ++i) {
            cout << "Vertex " << i << ": " << color[i] << endl;
        }
    } else {
        cout << "The graph is not bipartite.\n";
    }
    return 0;
}