#include<iostream>
using namespace std;
#include <sstream>

int dr[]={1,1,0,-1,-1,-1,0,1};
int dc[]={0,1,1,1,0,-1,-1,-1};
vector<string> grid;
vector<vector<bool> > visited;
int rows, cols;

int floodFills(int r, int c){
    if(r<0 || r>=rows || c<0 || c>=cols || grid[r][c]!='W' || visited[r][c]){
        return 0;
    }
    visited[r][c]=true;
    int size=1;
    for(int i=0;i<8;i++){
        size+= floodFills(r+dr[i], c+dc[i]);
    }

    return size;
}



int main(){

    int T;
    cin>>T;
    cin.ignore();
    cin.ignore();

    while(T--){
        grid.clear();
        string line;

        while(getline(cin, line) && !line.empty() && (line[0] =='W' || line[0]=='L')){
            grid.push_back(line);
        }
        rows = grid.size();
        cols = grid[0].size();

        do {
            int r, c;
            stringstream ss(line);
            if (ss >> r >> c) { // Extract integers from the line
                visited.assign(rows, vector<bool>(cols, false));
                cout << floodFills(r - 1, c - 1) << endl; // Convert to 0-based indexing
            }
            getline(cin, line); // Read the next line
        } while (!line.empty());


        if (T) cout << endl; // Blank line between test cases

    }

    return 0;
}