//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
class DisjointSet {
    vector<int> rank, parent;
    public:
    DisjointSet(int n){
        rank.resize(n+1, 0);
        parent.resize(n+1);
        for (int i = 0; i <= n; i++){
            parent[i] = i;
        }
    }
    int findULP(int u){
        if (parent[u] == u) return u;
        
        return parent[u] = findULP(parent[u]);
    }
    void UnionByRank(int u, int v){
        int ulp_u = findULP(u);
        int ulp_v = findULP(v);
        if (ulp_u == ulp_v) return;
        if (rank[ulp_u] > rank[ulp_v]) {
            parent[ulp_v] = ulp_u;
        }
        else if (rank[ulp_u] == rank[ulp_v]){
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
        else {
            parent[ulp_u] = ulp_v;
        }
    }
};
class Solution {
  public:
    int numProvinces(vector<vector<int>> adj, int V) {
        int n = adj.size();
        DisjointSet ds(n);
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                if (adj[i][j] == 1){
                    ds.UnionByRank(i, j);
                }
            }
        }
        unordered_set<int> st;
        for (int i = 0; i <= n; i++){
            st.insert(ds.findULP(i));
        }
        return st.size() - 1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends