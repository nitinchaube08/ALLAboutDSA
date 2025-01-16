#include<iostream>
using namespace std;

int boundedKnapsack(int S, vector<int> values, vector<int> weights, vector<int> counts){
    int n = weights.size();
    vector<int> dp(S+1 , 0);

    for(int i=0; i<n; i++){
        int weight = weights[i];
        int value = values[i];
        int count = counts[i];

        for(int k=1; count>0; k*=2){
            int take = min(k, count);
            for(int w=S; w>= weight; w--){
                dp[w] = max(dp[w], dp[w - weight]+value);
            }
            count-=take;
        }
    }
    return dp[S];
}

int main(){
    vector<int> values = {100, 70};
    vector<int> weights = {5, 4};
    vector<int> counts = {2, 3};
    int S = 17;

    cout << "Maximum value: " << boundedKnapsack(S, values, weights, counts) << endl;
    return 0;
}