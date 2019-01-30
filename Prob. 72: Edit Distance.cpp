class Solution {
public:
    int minDistance(string word1, string word2) {
        const int n1 = word1.length();
        const int n2 = word2.length();
        int dp[n1 + 1][n2 + 1] = {};
        for (int i = 0; i <= n1; ++i) {
            dp[i][0] = i;
        }
        for (int j = 0; j <= n2; ++j) {
            dp[0][j] = j;
        }
        for (int i = 1; i <= n1; ++i) {
            for (int j = 1; j <= n2; ++j) {
                if (word1[i - 1] == word2[j - 1]) { // dp[i][j]下标表示前i个字符，对应到word里下标要减1
                    dp[i][j] = min(dp[i - 1][j - 1], dp[i - 1][j] + 1);
                    dp[i][j] = min(dp[i][j], dp[i][j - 1] + 1);
                }
                else {
                    dp[i][j] = min(dp[i - 1][j - 1] + 1, dp[i - 1][j] + 1);
                    dp[i][j] = min(dp[i][j], dp[i][j - 1] + 1);
                }
            }
        }
        return dp[n1][n2];
        // w1[i] == w2[j]
        // dp[i][j] = min{dp[i - 1][j - 1], dp[i - 1][j] + 1, dp[i][j - 1] + 1}
        // w1[i] != w2[j]
        // dp[i][j] = min{dp[i - 1][j - 1] + 1, dp[i - 1][j] + 1, dp[i][j - 1] + 1}
    }
};