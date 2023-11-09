//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution{   
public:
    long maximumSumSubarray(int K, vector<int> &arr , int N){
        long temp = 0;
        if (N < K) return 0;
        for (int i = 0; i < K; i++){
            temp += arr[i];
        }
        long maxi = temp;
        if (N == K) return temp;
        for (int i = K; i < N; i++){
            temp += arr[i] - arr[i-K];
            maxi = max(temp, maxi);
            
        }
        return maxi;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N,K;
        cin >> N >> K;;
        vector<int>Arr;
        for(int i=0;i<N;++i){
            int x;
            cin>>x;
            Arr.push_back(x);
        }
        Solution ob;
        cout << ob.maximumSumSubarray(K,Arr,N) << endl;
    }
    return 0; 
} 
// } Driver Code Ends