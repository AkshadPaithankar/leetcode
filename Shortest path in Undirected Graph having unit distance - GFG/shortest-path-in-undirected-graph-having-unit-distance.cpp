//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
   
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        int vis[N] = {0};
        vector<int> dist(N, 0);
        queue<int> q;
        q.push(src);
        vis[src] = 1;
        dist[src] = 0;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for (auto edge: edges){
                if (edge[0] == node && !vis[edge[1]]){
                    vis[edge[1]] =1;
                    dist[edge[1]] = dist[edge[0]] + 1;
                    q.push(edge[1]);
                }
                if (edge[1] == node && !vis[edge[0]]){
                    vis[edge[0]] = 1;
                    dist[edge[0]] = dist[edge[1]] + 1;
                    q.push(edge[0]);
                }
            }
        }
        for (int i = 0; i < N; i++){
            if (dist[i] == 0 && i != src) dist[i] = -1;
        }
        return dist;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for(int j=0; j<2; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src; cin >> src;

        Solution obj;

        vector<int> res = obj.shortestPath(edges, n, m, src);

        for (auto x : res){
            cout<<x<<" ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends