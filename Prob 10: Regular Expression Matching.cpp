class Solution {
public:
    bool isMatch(string s, string p) {
        const int m = s.length();
        const int n = p.length();
        bool dp[m + 1][n + 1] = {}; // dp[i][j]表示前i个和前j个能否匹配
        dp[0][0] = true;
        for (int j = 1; j <= n; ++j) {
            dp[0][j] = (p[j - 1] == '*') && dp[0][j - 2];
        }
        // cout << dp[0][2] << endl;
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (p[j - 1] == '.' || s[i - 1] == p[j - 1])
                    dp[i][j] = dp[i - 1][j - 1];
                else if (p[j - 1] == '*') {
                    if (p[j - 2] != s[i - 1] && p[j - 2] != '.') // 对应到字符串中注意下标
                        dp[i][j] = dp[i][j - 2];
                    else
                        dp[i][j] = dp[i][j - 2] || dp[i - 1][j - 2] || dp[i - 1][j]; 
                        
                }
                else
                    dp[i][j] = false;
            }
        }
        return dp[m][n];
    }
};
/*

if p[j - 1] == '.' || s[i - 1] == p[j - 1]
    dp[i][j] = dp[i - 1][j - 1]
else if p[j - 1] == '*'
    if p[j - 2] != s[i - 1]
        dp[i][j] = dp[i][j - 2]
    else
        dp[i][j] = dp[i][j - 2] || dp[i - 1][j - 2] || dp[i - 1][j] 
        dp[i][j - 2]对应0个p[j - 2]
        dp[i - 1][j - 2]对应1个p[j - 2]
        dp[i - 1][j]对应多个p[j - 2]
        
else
    dp[i][j] = false;

*/