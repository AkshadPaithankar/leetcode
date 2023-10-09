//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//Back-end complete function Template for C++

class Solution {
  public:
    int mincost(int i, vector<int>&cost ,int N, vector<int> &dp){
        
        if (i >= N) return 0;
        
        if (dp[i] != -1) return dp[i];
        int op1 = 0;
        
        op1 = cost[i] + mincost(i+1, cost, N, dp);
        int op2 = 0;
        op2 = cost[i] + mincost(i+2, cost, N, dp);
        return dp[i] = min(op1, op2);
    }
    int minCostClimbingStairs(vector<int>&cost ,int N) {
        vector<int> dp(N, -1);
        int ans0 = mincost(0, cost, N, dp);
        int ans1 = mincost(1, cost, N, dp);
        return min(ans0, ans1);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        vector<int>cost(N);
        
        for(int i=0 ; i<N ; i++){
            cin>>cost[i];
        }

        Solution ob;
        cout<<ob.minCostClimbingStairs(cost,N);
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends