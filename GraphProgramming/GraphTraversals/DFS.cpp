#include<iostream>
using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

const auto UNVISITED=0;
const auto VISITED=1;

vector<vii> adjList;
vi dfs_num;

void dfs(int v){
    dfs_num[v]=VISITED;
    for(int j=0; j< (int)adjList[v].size(); j++){
        ii u = adjList[v][j];
        if(dfs_num[u.first] == UNVISITED){
            cout<<(u.first);
            dfs(u.first);
        }
    }
}

int main(){
    int v,e;
    cin>>v>>e;
    adjList.assign(v, vii());
    dfs_num.assign(v, UNVISITED); // Initialize dfs_num as UNVISITED

    for(int i=0; i<e; i++){
        int u, v, w;
        cin>>u>>v>>w;
        adjList[u].push_back(ii(v,w));


    }
    cout<<"Starting dfs from vertex zero"<<endl;

    dfs(0);
    cout << "\nDFS visitation state:\n";
    for (int i = 0; i < v; i++) {
        cout << "Vertex " << i << ": " << (dfs_num[i] == VISITED ? "Visited" : "Unvisited") << endl;
    }

    return 0;
}