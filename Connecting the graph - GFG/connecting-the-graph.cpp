//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class DisjointSet {
    
    public:
    vector<int> rank, parent;
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
    int Solve(int n, vector<vector<int>>& edge) {
        int e = edge.size();
        int extra = 0;
        DisjointSet ds(n);
        for (auto it: edge){
            int u = it[0];
            int v = it[1];
            if (ds.findULP(u) == ds.findULP(v)) extra++;
            else ds.UnionByRank(u, v);
        }
        int prov = 0;
        for (int i = 0; i < n; i++){
            if (ds.parent[i] == i) prov++;
        }
        if (extra >= prov - 1) return prov - 1;
        else return -1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 2; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution Obj;
        cout << Obj.Solve(n, adj) << "\n";
    }
    return 0;
}
// } Driver Code Ends