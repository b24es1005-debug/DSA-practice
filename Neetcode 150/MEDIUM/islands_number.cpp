class Solution {
private:
    // BFS to mark all connected '1's as visited
    void bfs(int row, int col, vector<vector<int>>& vis, vector<vector<char>>& grid) {
        int n = grid.size();      // Number of rows
        int m = grid[0].size();   // Number of columns
        
        // Mark starting cell as visited
        vis[row][col] = 1;
        
        // Queue for BFS traversal
        queue<pair<int, int>> q;
        q.push({row, col});
        
        // Direction vectors for 4-directional movement
        int delrow[] = {-1, 1, 0, 0};  // Up, Down, Left, Right
        int delcol[] = {0, 0, -1, 1};
        
        while(!q.empty()) {
            // Get front element from queue
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            
            // Check all 4 neighbors
            for(int i = 0; i < 4; i++) {
                int nrow = r + delrow[i];
                int ncol = c + delcol[i];
                
                // Check if neighbor is valid and unvisited land
                if(nrow >= 0 && nrow < n && 
                   ncol >= 0 && ncol < m && 
                   !vis[nrow][ncol] && 
                   grid[nrow][ncol] == '1') {
                    vis[nrow][ncol] = 1;    // Mark as visited
                    q.push({nrow, ncol});   // Add to queue
                }
            }
        }
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        // Edge case: empty grid
        if(grid.empty() || grid[0].empty()) return 0;
        
        int n = grid.size();    // Number of rows
        int m = grid[0].size(); // Number of columns
        
        // Visited array
        vector<vector<int>> vis(n, vector<int>(m, 0));
        
        int count = 0;
        
        // Traverse all cells
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {  // ✅ Fixed: j++ not i++
                // If unvisited land found, start new island
                if(grid[i][j] == '1' && !vis[i][j]) {
                    count++;
                    bfs(i, j, vis, grid);
                }
            }
        }
        
        return count;
    }
};
/*
TC: O(NxM)
SC: Grid: All cells are '1'
Start BFS from (0,0):
- Queue will grow in a diamond pattern
- Maximum queue size ≈ O(min(n, m) × max(n, m))
- Worst case: O(n × m)*/