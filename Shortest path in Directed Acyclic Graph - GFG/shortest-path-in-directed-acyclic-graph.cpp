//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    
    void dfs(int node, vector<vector<int>>& edges, int vis[], stack<int> &topo){
        vis[node] = 1;
        for (auto edge: edges){
            if (edge[0] == node){
                if (!vis[edge[1]]) dfs(edge[1], edges, vis, topo);
                
            }
        }
        topo.push(node);
    }
    vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        int vis[N] = {0};
        stack<int> topo;
        for (int i = 0; i < N; i++){
            if (!vis[i]) {
                dfs(i, edges, vis, topo);
            }
        }
        vector<int> ans(N, 1e9);
        ans[0] = 0;
        
        while (!topo.empty()){
            int node = topo.top();
            topo.pop();
            
            for (auto it : edges){
                if (it[0] == node){
                    int v = it[1];
                    int wt = it[2];
                    if (wt + ans[node] < ans[v]) ans[v] = wt + ans[node];
                }
            }
        }
        for (int i = 0; i < N; i++){
            if(ans[i] == 1e9) ans[i] = -1;
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends