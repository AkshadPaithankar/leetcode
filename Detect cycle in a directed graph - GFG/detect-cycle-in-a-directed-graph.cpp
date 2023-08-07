//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool dfs(int i, vector<int> &vis,  vector<int> &pathvis, vector<int> edges[]){
	vis[i] = 1;
	pathvis[i] = 1;
	
	for (auto it: edges[i]){
		if(!vis[it]){
			if (dfs(it, vis, pathvis, edges)) return true;
		}
		else if(pathvis[it]) return true;
	}
	
	pathvis[i] = 0;
	return false;
}


    // Function to detect cycle in a directed graph.
    bool isCyclic(int v, vector<int> edges[]) {
        vector<int> vis(v+1, 0);
	    vector<int> pathvis(v+1, 0);
	    for(int i = 0; i < v; i++){
	    	if(dfs(i, vis, pathvis, edges)) return true;
	    }
	    return false; 
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends