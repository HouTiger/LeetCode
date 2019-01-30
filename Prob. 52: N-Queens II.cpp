class Solution {
    int num; // how many Queens
    int ans = 0;
    set<int> col;
    set<int> k; // 截距
    set<int> b; // 截距
public:
    int totalNQueens(int n) {
        num = n;
        Recurse(n);
        return ans;
    }
    void Recurse(int n) {
        // 在index = n - 1行放置棋子
        if (n == 0) {
            ans += 1;
            return;
        }
        for (int i = 0; i < num; ++i) {
            if (col.find(i) == col.end() && k.find(1 - n - i) == k.end() 
                && b.find(1 - n + i) == b.end()) {
                col.insert(i);
                k.insert(1 - n - i);
                b.insert(1 - n + i);
                
                Recurse(n - 1);
                
                b.erase(1 - n + i);
                k.erase(1 - n - i);
                col.erase(i);
                
            } 
        }
        return;
    }
};