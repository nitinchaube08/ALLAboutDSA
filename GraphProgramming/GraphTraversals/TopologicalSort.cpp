#include<iostream>
#include<unordered_set>
#include<unordered_map>
#include<stack>
#include<vector>


using namespace std;

void dfs(int node, unordered_map<int, vector<int> > &graph, unordered_set<int> &visited, stack<int> &st){
    visited.insert(node);
    for(int neighbor: graph[node]){
        if(visited.find(neighbor) == visited.end()){
            dfs(neighbor, graph, visited, st);
        }

    }
    st.push(node);


}


vector<int> topologicalSortDFS(int numNodes, unordered_map<int, vector<int> > &graph){
    unordered_set<int> visited;
    stack<int> st;
    vector<int> result;

    for(int i=0;i<numNodes; i++){
        if(visited.find(i) == visited.end()){
            dfs(i, graph,  visited, st);
        }
    }

    while(!st.empty()){
        result.push_back(st.top());
        st.pop();
    }
    return result;

}

int main(){
    int numNodes = 6; // Number of nodes
    unordered_map<int, vector<int> > graph = {
        {0, {2}},  // A -> C
        {1, {2, 3}},  // B -> C, B -> D
        {2, {4}},  // C -> E
        {3, {5}},  // D -> F
        {4, {}},   // E has no neighbors
        {5, {}}    // F has no neighbors
    };

    vector<int> result = topologicalSortDFS(numNodes, graph);

    cout << "Topological Order (DFS): ";
    for (int node : result) {
        cout << node << " ";
    }
    cout << endl;
    return 0;
}