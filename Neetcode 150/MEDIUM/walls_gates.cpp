/*LeetCode 286 - Walls and Gates (Islands and Treasure)
You are given an m × n grid where:
-1 → Wall
0 → Gate
INT_MAX (2147483647) → Empty room
For every empty room, fill it with the distance to its nearest gate.
Distance is the number of steps moving up, down, left, or right.
If a room cannot reach any gate, leave it as INT_MAX.*/
class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int, int>> q;
        // Push all gates (0) into the queue
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0)//multi source BFS, we are taking all the cells with 0 at same time and BFS
                    q.push({i, j});
            }
        }

        int delrow[] = {-1, 1, 0, 0};
        int delcol[] = {0, 0, -1, 1};

        while (!q.empty()) {

            auto [r, c] = q.front();
            q.pop();
            // Visit all 4 neighbours
            for (int k = 0; k < 4; k++) {
                int nrow = r + delrow[k];
                int ncol = c + delcol[k];
                // Process only unvisited empty rooms (INF)
                if (nrow >= 0 && nrow < m &&
                    ncol >= 0 && ncol < n &&
                    grid[nrow][ncol] == INT_MAX) {

                    // Distance = parent's distance + 1
                    grid[nrow][ncol] = grid[r][c] + 1;

                    // Continue BFS
                    q.push({nrow, ncol});
                }
            }
        }
        //Now the grid will be updated, the dist to nearest 1 will be in each cell except -1
    }
};