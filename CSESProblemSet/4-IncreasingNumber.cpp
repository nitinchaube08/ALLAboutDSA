#include<iostream>
using namespace std;

int main(){
    long long n;
    cin>>n;
    int mx=0;
    long long ans=0;
    for(long long i=0;i<n;i++){
        int x;
        cin>>x;
        mx = max(x, mx);
        ans+= mx-x;
    }
    cout<<ans;
}