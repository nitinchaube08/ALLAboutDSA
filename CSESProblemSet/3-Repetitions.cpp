#include<iostream>
#include <algorithm>
using namespace std;

int main(){
    string s;
    cin>>s;
    int max_ans=1, count=0;
    char f ='A';
    for(char i:s){
        if(f==i){
            count+=1;
            max_ans = max(count, max_ans);
        }else{
            f=i;
            count=1;
        }
    }
    cout<<max_ans;
    return 0;
}