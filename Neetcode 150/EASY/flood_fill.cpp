class Solution {
private:
    void bfs(int row, int col, int color, vector<vector<int>>& image) {
        int n = image.size();
        int m = image[0].size();
        
        int startColor = image[row][col];
        
        // ✅ If starting pixel already has target color, return
        if(startColor == color) return;
        
        queue<pair<int, int>> q;
        q.push({row, col});
        image[row][col] = color;
        
        int delrow[] = {-1, 1, 0, 0};
        int delcol[] = {0, 0, -1, 1};
        
        while(!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            
            for(int i = 0; i < 4; i++) {
                int nr = r + delrow[i];
                int nc = c + delcol[i];
                
                if(nr >= 0 && nr < n && nc >= 0 && nc < m && 
                   image[nr][nc] == startColor) {
                    image[nr][nc] = color;
                    q.push({nr, nc});
                }
            }
        }
    }
    
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        // ✅ Edge case: empty image
        if(image.empty() || image[0].empty()) return image;
        
        bfs(sr, sc, color, image);
        return image;
    }
};