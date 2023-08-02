//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to find the number of islands.
    void bfs(vector<vector<char>>& grid, vector<vector<int>> &vis, int i, int j, int n, int m){
        vis[i][j] = 1;
        queue<pair<int, int>> q;
        q.push({i, j});
        
        //int drow[] = {0, 0, 1, -1, 1, -1, 1, -1};
        //int dcol[] = {1, -1, 0, 0, 1, 1, -1, -1};
        
        while (!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            for (int drow = -1; drow <= 1; drow++){
                for (int dcol = -1; dcol <= 1; dcol++){
                    
                    int nrow = row + drow;
                    int ncol = col + dcol;
                    if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m
                    && grid[nrow][ncol] == '1' && !vis[nrow][ncol] ){
                        vis[nrow][ncol] = 1;
                        q.push({nrow, ncol});
                    }
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int> (m, 0));
        int count = 0;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                
                if (grid[i][j] == '1' && vis[i][j] != 1) {
                    count++;
                    bfs(grid, vis, i, j, n, m);
                }
            }
        }
        return count;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends