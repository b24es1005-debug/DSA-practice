class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        //Use vector instead of VLA
        vector<vector<int>> vis(n, vector<int>(m, 0));
        
        int cntFresh = 0;
        queue<pair<pair<int, int>, int>> q; // {{row, col}, time}
        
        // Initialize: add all rotten oranges to queue
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 2) {
                    q.push({{i, j}, 0});
                    vis[i][j] = 2;
                }
                if(grid[i][j] == 1) {
                    cntFresh++;
                }
            }
        }
        
        //Direction arrays (corrected)
        int delrow[] = {-1, 1, 0, 0};
        int delcol[] = {0, 0, -1, 1};
        
        int time = 0;
        int cntRotten = 0;  // Count oranges that become rotten
        
        while(!q.empty()) {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            q.pop();
            
            time = max(time, t);
            
            // Check all 4 directions
            for(int i = 0; i < 4; i++) {
                int nrow = r + delrow[i];
                int ncol = c + delcol[i];
                
                // Check bounds and if fresh orange
                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && 
                   grid[nrow][ncol] == 1 && !vis[nrow][ncol]) {
                    vis[nrow][ncol] = 2;
                    grid[nrow][ncol] = 2;  // Mark as rotten
                    cntRotten++;
                    q.push({{nrow, ncol}, t + 1});  //Push new coordinates
                }
            }
        }
        
        //Check if all fresh oranges are rotten
        if(cntRotten == cntFresh) return time;
        return -1;
    }
};//LC994