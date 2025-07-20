class Solution {
public:
    void dfs(int i, int j, vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();

        if (i < 0 || i >= n || j < 0 || j >= m || board[i][j] != 'O')
            return;

        board[i][j] = '#'; // Temporarily mark

        dfs(i+1, j, board);
        dfs(i-1, j, board);
        dfs(i, j+1, board);
        dfs(i, j-1, board);
    }

    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();

        // Step 1: Mark all border-connected 'O's
        for (int i = 0; i < n; i++) {
            dfs(i, 0, board);
            dfs(i, m-1, board);
        }

        for (int j = 0; j < m; j++) {
            dfs(0, j, board);
            dfs(n-1, j, board);
        }

        // Step 2: Flip surrounded 'O's to 'X', and restore '#' back to 'O'
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 'O')
                    board[i][j] = 'X';
                else if (board[i][j] == '#')
                    board[i][j] = 'O';
            }
        }
    }
};