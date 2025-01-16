#include<iostream>
using namespace std;
const int MOD = 1000000;
vector<vector<int> >memo;

int FindWays(int n,int k){
    if(k==1){
        cout<<"Since k is one there is only one way to represent "<<n<<endl;
        return 1;
    }
    if(memo[n][k]!=-1){
        return memo[n][k];
    }
    int result=0;
    for(int x=0; x<=n; x++){
        cout<<"FindWays("<<n-x<<k-1<<") is getting calculated"<<endl;
        int ways = FindWays(n-x, k-1);
        cout<<"FindWays("<<n-x<<k-1<<") is resulting: "<<ways<<endl;
        result = (result + ways)%MOD;
        
    }
    return memo[n][k]=result;
}

int main(){
    int n,k;
    memo.assign(n+1, vector<int>(k+1,-1));
    cin>>n>>k;
    cout<< FindWays(n,k)<<endl;
}