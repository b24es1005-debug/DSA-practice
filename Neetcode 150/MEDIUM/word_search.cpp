class Solution {
public:
    int m, n;

    bool dfs(vector<vector<char>>& board, string& word,
             int i, int j, int index) {

        // Entire word matched
        if (index == word.size())
            return true;

        // Invalid cell
        if (i < 0 || i >= m || j < 0 || j >= n)
            return false;

        // Character mismatch
        if (board[i][j] != word[index])
            return false;

        char temp = board[i][j];
        board[i][j] = '#';      // mark visited

        bool found =
            dfs(board, word, i + 1, j, index + 1) ||
            dfs(board, word, i - 1, j, index + 1) ||
            dfs(board, word, i, j + 1, index + 1) ||
            dfs(board, word, i, j - 1, index + 1);

        board[i][j] = temp;     // backtrack

        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {

        m = board.size();
        n = board[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (dfs(board, word, i, j, 0))
                    return true;
            }
        }

        return false;
    }
};