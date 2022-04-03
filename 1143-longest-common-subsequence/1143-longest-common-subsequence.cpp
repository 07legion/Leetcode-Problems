class Solution {
private:
    int dp[1001][1001];
    string s1, s2;
public:
    int func(int i, int j) {
        if (i == s1.length() || j == s2.length()) return 0;
        if (dp[i][j] != -1) return dp[i][j];
        if (s1[i] == s2[j]) return dp[i][j] = 1 + func(i+1, j+1);
        else return dp[i][j] = max(func(i+1, j), func(i, j+1));
    }
    int longestCommonSubsequence(string str1, string str2) {
        memset(dp, -1, sizeof dp);
        s1 = str1; s2 = str2;
        return func(0, 0);
    }
};