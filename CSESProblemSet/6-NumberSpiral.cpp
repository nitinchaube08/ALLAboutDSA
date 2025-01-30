#include<iostream>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int y, x;
        cin>>y>>x;
        if(x==y){
            cout<<(x*x) - (y-1);
            return 0;
        }
        if(x%2!=0){
            cout<<(x*x)- (y-1);
        }




        cout<<endl;
    }
}