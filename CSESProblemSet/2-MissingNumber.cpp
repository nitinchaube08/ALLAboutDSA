#include<iostream>
using namespace std;

int main(){
    long long n, sum=0;

    cin>>n;
    for(int i=0;i<n-1;i++){
        long long x;
        cin>>x;
        sum+=x;

    }
    long long total_sum = n*(n+1)/2;
    cout<<(total_sum-sum);
    return 0;
}