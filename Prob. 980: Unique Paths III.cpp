class Solution {
    int x[4] = {-1, 0, 1, 0};
    int y[4] = {0, 1, 0, -1};
    int strx, stry; // 起点
    int endx, endy; // 终点
    int line, col; 
    int ans = 0;
    int EmptyNum = 0; // 可走的格子数量，含起点终点
    vector<vector<int>> g;
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        g = grid;
        line = grid.size(); // 行数
        col = grid[0].size(); // 列数

        for (int i = 0; i < line; ++i) {
            for (int j = 0; j < col; ++j) {
                if (grid[i][j] == 1) {
                    strx = i;
                    stry = j;
                    EmptyNum += 1;
                }
                if (grid[i][j] == 2) {
                    endx = i;
                    endy = j;
                    EmptyNum += 1;
                }
                if (grid[i][j] == 0)
                    EmptyNum += 1;
            }
        }
        
        dfs(strx, stry, EmptyNum);
        
        return ans;
    }
    
    void dfs(int sx, int sy, int leftzero) {
        leftzero -= 1;
        if (leftzero < 0)
            return;
        if (sx == endx && sy == endy && leftzero == 0) {
            ans += 1;
            return;
        }
        int save = g[sx][sy];
        g[sx][sy] = 3;
        for (int i = 0; i < 4; ++i) {
            int tx = sx + x[i];
            int ty = sy + y[i];
            if (tx < 0 || tx >= line || ty < 0 || ty >= col)
                continue;
            if (g[tx][ty] == 0 || g[tx][ty] == 2) {
                dfs(tx, ty, leftzero);
            }
        }
        g[sx][sy] = save;
        
        return;    
    }
};