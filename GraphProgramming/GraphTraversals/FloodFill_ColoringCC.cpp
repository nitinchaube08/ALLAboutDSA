#include<iostream>
using namespace std;

int dr[] = {1, 1, 0, -1, -1, -1, 0, 1}; // 8 directions
int dc[] = {0, 1, 1, 1, 0, -1, -1, -1};

int floodfill(vector<vector<char> > &grid, int r, int c, char target, char replacement){
    if(r<0 || r>=grid.size() || c<0 || c>=grid[0].size()) return 0; //outside
    if(grid[r][c]!=target) return 0;
    grid[r][c] = replacement;
    int size =1;
    for( int d=0;d<8;d++){
        cout<< "Flood fill is called for dr "<<d<<"dc "<<d<<endl;
        size+= floodfill(grid, r + dr[d], c+dc[d], target, replacement);
    }
    return size;
}

int main(){
    int r, c;
    cout<<"Enter the number of rows and columns:"<<endl;
    cin>>r>>c;

    vector<vector<char> > grid(r, vector<char>(c));
    cout<<"Enter the row as a string:"<<endl;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin>> grid[i][j];
        }
    }
    cout<<"Enter the starting position:"<<endl;
    int startx, starty;
    cin>>startx>>starty;
    cout<<"Enter the target char and replacement of it:"<<endl;
    char target, replacement;
    cin>>target>>replacement;

    int componentSize = floodfill(grid, startx, starty, target, replacement);
    cout<<componentSize<<endl;
    return 0;
}