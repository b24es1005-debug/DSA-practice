class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        
        // Transpose the matrix
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){  // Only swap upper triangle
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        
        // Reverse each row
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n / 2; j++){  // Only go to middle
                swap(matrix[i][j], matrix[i][n - 1 - j]);
            }
        }
    }
};