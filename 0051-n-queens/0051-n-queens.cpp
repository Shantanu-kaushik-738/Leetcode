class Solution {
public:
    bool safe(int i, int j, vector<string> board, int n) {
        int row = i, col = j;

        while (i >= 0 && j >= 0) { // upper left diagonal
            if (board[i--][j--] == 'Q') return false;
        }

        i = row;
        j = col;

        while (j >= 0) { // left row
            if (board[i][j--] == 'Q') return false;
        }

        i = row;
        j = col;

        while (i < n && j >= 0) { // lower left diagonal
            if (board[i++][j--] == 'Q') return false;
        }
        return true;
    }

    void solve(int j, vector<string>& board, vector<vector<string>>& ans, int n) {
        if (j == n) { // all col filled
            ans.push_back(board);
            return;
        }

        for (int i = 0; i < n; i++) { // each row
            if (safe(i, j, board, n)) {
                board[i][j] = 'Q';
                solve(j + 1, board, ans, n);
                board[i][j] = '.'; // backtrack
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n, string(n, '.'));

        solve(0, board, ans, n);
        return ans;
    }
};