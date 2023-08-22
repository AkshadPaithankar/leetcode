//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
       
        int count = 0;
        priority_queue<vector<int>, vector<vector<int>> , greater<vector<int>>> pq;
        int vis[V] = {0};
        pq.push({0, 0, -1});
        while(!pq.empty()){
            auto it = pq.top();
            int wt = it[0];
            int node = it[1];
            int parent = it[2];
            
            pq.pop();
            if(vis[node] == 1) continue;
            vis[node] = 1;
            count += wt;
            
            for (auto adjnode : adj[node]){
                int v = adjnode[0];
                int adjwt = adjnode[1];
                if (vis[v] == 0){
                    pq.push({adjwt, v, node});
                }
            }
        }
        return count;
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends