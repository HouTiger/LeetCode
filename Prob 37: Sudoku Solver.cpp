class Solution {
    bool row[9][9] = {};
    bool col[9][9] = {};
    bool grid[9][9] = {};
    bool found = false;
public:
    void solveSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] != '.') {
                    row[i][board[i][j] - '1'] = true;
                    col[j][board[i][j] - '1'] = true;
                    grid[(i / 3) * 3 + (j / 3) % 3][board[i][j] - '1'] = true;
                }
            }
        }
        place(0, board);
        return;
    }
    void place(int n, vector<vector<char>>& board) {
        if (n == 81) {
            // board = g;
            found = true;
            return;
        }
        
        int i = n / 9, j = n % 9;
        int index = (i / 3) * 3 + (j / 3) % 3;
        if (board[i][j] == '.') {
            for (int c = 0; c < 9; ++c) {
                if (!row[i][c] && !col[j][c] && !grid[index][c]) {
                    row[i][c] = true;
                    col[j][c] = true;
                    grid[index][c] = true;
                    board[i][j] = c + '1';
                    
                    place(n + 1, board);
                    
                    if (found)
                        return;
                    
                    board[i][j] = '.';
                    row[i][c] = false;
                    col[j][c] = false;
                    grid[index][c] = false;
                    
                }
            }
        }
        else 
            place(n + 1, board);
        return;
    }
};