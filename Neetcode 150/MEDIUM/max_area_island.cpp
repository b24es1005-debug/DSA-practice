class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        int ans = 0;

        int delrow[] = {-1, 1, 0, 0};
        int delcol[] = {0, 0, -1, 1};

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                // Start BFS only if we find an unvisited land cell
                if (grid[i][j] == 1) {

                    queue<pair<int,int>> q;
                    q.push({i, j});
                    grid[i][j] = 0;      // Mark as visited

                    int area = 1;

                    while (!q.empty()) {

                        auto [r, c] = q.front();
                        q.pop();

                        // Explore all 4 directions
                        for (int k = 0; k < 4; k++) {

                            int nrow = r + delrow[k];
                            int ncol = c + delcol[k];

                            if (nrow >= 0 && nrow < n &&
                                ncol >= 0 && ncol < m &&
                                grid[nrow][ncol] == 1) {

                                area++;                    // Increase island size
                                grid[nrow][ncol] = 0;      // Mark visited
                                q.push({nrow, ncol});      // Continue BFS
                            }
                        }
                    }

                    // Update maximum area found so far
                    ans = max(ans, area);
                }
            }
        }

        return ans;
    }
};