#include<iostream>
using namespace std;

typedef pair<int, int> ii;
typedef vector< ii> vii;
typedef vector<int> vi;

int main(){
    int v, e, s;
    cin>>v>>e>>s;

    vector<vii> adjList(v);
    for(int i=0; i<e; i++){
        int u,v;
        cin>>u>>v;
        adjList[u].push_back(ii(v,i));
    }
    vi d(v, INT_MAX);
    d[s]=0;

    queue<int> q;
    q.push(s);

    while(!q.empty()){
        int u = q.front();
        q.pop();

        for(int i=0; i<(int)adjList[u].size(); i++){
            ii v = adjList[u][i];
            if(d[v.first] == INT_MAX){
                d[v.first] = d[u]+1;
                q.push(v.first);
            }
        }
    }

    // Output the distances
    cout << "Shortest distances from source vertex " << s << ":\n";
    for (int i = 0; i < v; i++) {
        if (d[i] == INT_MAX) {
            cout << "Vertex " << i << ": Unreachable\n";
        } else {
            cout << "Vertex " << i << ": " << d[i] << endl;
        }
    }



    return 0;
}