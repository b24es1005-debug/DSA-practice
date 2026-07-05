class Solution {
public:
    vector<vector<int>> nearest(vector<vector<int>>& grid) {
        int n = grid.size();      // Number of rows
        int m = grid[0].size();   // Number of columns
        
        // Distance matrix initialized to -1 (unvisited)
        vector<vector<int>> dis(n, vector<int>(m, -1));
        
        // Queue for BFS
        queue<pair<int, int>> q;
        
        // Step 1: Find all cells with 1 (source nodes)
        // These cells have distance 0
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1) {
                    dis[i][j] = 0;      // Distance from itself is 0
                    q.push({i, j});     // Add to queue as starting point
                }
            }
        }
        
        // Direction arrays for 4-directional movement
        // Up, Down, Left, Right
        int delrow[] = {-1, 1, 0, 0};
        int delcol[] = {0, 0, -1, 1};
        
        // Step 2: Multi-source BFS
        while(!q.empty()) {
            int r = q.front().first;    // Current row
            int c = q.front().second;   // Current column
            q.pop();
            
            // Check all 4 neighbors
            for(int i = 0; i < 4; i++) {
                int nrow = r + delrow[i];   // New row
                int ncol = c + delcol[i];   // New column
                
                // Check if neighbor is valid and unvisited
                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                   dis[nrow][ncol] == -1) {
                    
                    // Distance = current distance + 1
                    dis[nrow][ncol] = dis[r][c] + 1;
                    q.push({nrow, ncol});
                }
            }
        }
        
        return dis;
    }
};