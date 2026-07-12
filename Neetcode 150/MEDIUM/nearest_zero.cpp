class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> ans(m,vector<int>(n,-1));
        queue<pair<int,int>> q;
        for(int i= 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(mat[i][j] == 0){
                    ans[i][j] = 0;
                    q.push({i,j});
                }
            }
        }
        
        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            int delrow[] = {-1,1,0,0};
            int delcol[] = {0,0,-1,1};
            for(int i = 0;i<4;i++){
                int nrow = r + delrow[i];
                int ncol = c + delcol[i];
                if(nrow>=0 && nrow<m && ncol>=0 && ncol<n &&
                ans[nrow][ncol] == -1){
                    ans[nrow][ncol] = ans[r][c] + 1;
                    q.push({nrow,ncol});
                }
            }
        }
        return ans;
    }
};