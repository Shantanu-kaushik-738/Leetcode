class Solution {
public:
    bool safe(vector<vector<char>>& board, int r, int c, char d) {

        for (int i = 0; i < 9; i++) { // horizontal
            if (board[r][i] == d) return false;
        }

        for (int i = 0; i < 9; i++) { // vertical
            if (board[i][c] == d) return false;
        }

        int sr = (r / 3) * 3, sc = (c / 3) * 3;
        for (int i = sr; i < sr + 3; i++) { // 3 X 3 grid
            for (int j = sc; j < sc + 3; j++) {
                if (board[i][j] == d) return false;
            }
        }
        return true;
    }

    bool helper(vector<vector<char>>& board, int r, int c) {
        if (r == 9) return true;

        int nr = r, nc = c + 1;
        if (nc == 9) {
            nr = r + 1;
            nc = 0;
        }

        if (board[r][c] != '.') return helper(board, nr, nc);
        else { // place digit
            for (char i = '1'; i <= '9'; i++) {
                if (safe(board, r, c, i)) {
                    board[r][c] = i;
                    if (helper(board, nr, nc)) return true;
                    board[r][c] = '.';
                }
            }
        }
        return false;
    }

    void solveSudoku(vector<vector<char>>& board) { 
        helper(board, 0, 0); 
    }
};