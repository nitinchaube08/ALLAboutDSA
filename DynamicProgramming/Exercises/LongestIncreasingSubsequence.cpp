#include<iostream>
using namespace std;

int findLIS(vector<int> arr, int n){  // This give the LongestIncreasing Sequence in O(nlogk) where k is length of L.
    vector<int> L;

    for(int i:arr){
        auto pos = lower_bound(arr.begin(), arr.end(), i);
        if(pos==arr.end()){
            L.push_back(i);
        }else{
            *pos = i;
        }
    }

    return L.size();

}



int LIS(vector<int> arr, int n){ // This takes O(n^2)
    int max_length = INT_MIN;
    vector<int> LIS(n,1);
    for(int i=1;i<n; i++){
        for(int j=0; j<i; j++){
            if(arr[j]<arr[i]){
                LIS[i] = max(LIS[i], LIS[j]+1);
            }
        }
    } 


    return *max_element(LIS.begin(), LIS.end());
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n; i++){
        cin>>arr[i];
    }
    int longestSequece = LIS(arr,n);
    cout<<"Longest increasing subsequece length is: "<<longestSequece<<endl;
    return 0;
}