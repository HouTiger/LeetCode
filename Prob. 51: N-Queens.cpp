class Solution {
    vector<string> grid;
    int num; // how many Queens
    vector<vector<string>> ans;
    set<int> col;
    set<int> k; // 截距1
    set<int> b; // 截距2

public:
    vector<vector<string>> solveNQueens(int n) {
        string s = ".";
        for (int i = 1; i < n; ++i) {
            s += ".";
        }
        for (int j = 0; j < n; ++j) {
            grid.push_back(s);
        }
        num = n;
        Recurse(n);
        return ans;
        
    }
    void Recurse(int n) {
        // 在index = n - 1行放置棋子
        if (n == 0) {
            ans.push_back(grid);
            return;
        }
        for (int i = 0; i < num; ++i) {
            if (col.find(i) == col.end() && k.find(1 - n - i) == k.end() 
                && b.find(1 - n + i) == b.end()) {
                col.insert(i);
                k.insert(1 - n - i);
                b.insert(1 - n + i);
                grid[n - 1][i] = 'Q';
                Recurse(n - 1);
                grid[n - 1][i] = '.';
                b.erase(1 - n + i);
                k.erase(1 - n - i);
                col.erase(i);
                
            } 
        }
        return;
        
    }
};