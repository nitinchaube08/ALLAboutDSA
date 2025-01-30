#include<iostream>
using namespace std;

typedef vector<int> vi;
typedef vector<vector<int> > vii;

bool isBipartite(vii &adjList, int v, vi &color){
    for(int start = 0; start<v; start++){
        if(color[start]== -1){
            color[start]=0;
            queue<int> q;
            q.push(start);
            while(!q.empty()){
                int node = q.front();
                q.pop();
                for(int neighbor: adjList[node]){
                    if(color[neighbor]==-1){
                        color[neighbor] = 1 - color[node];
                        q.push(neighbor);
                    }else if (color[neighbor] == color[node]){
                        return false;
                    }
                }
            }
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