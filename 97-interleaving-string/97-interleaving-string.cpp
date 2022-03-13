class Solution {
private:
    int dp[102][102];
    string str1, str2, str3;
    int n, m, len;
public:
    bool func(int i, int j, int k) {
        if (i == n && j == m && k == len)
            return true;
        if (dp[i][j] != -1) return dp[i][j];
        if (str1[i] == str3[k] && str2[j] == str3[k]) {
            return dp[i][j] = func(i+1, j, k+1) || func(i, j+1, k+1);
        } else if (str1[i] == str3[k]) {
            return dp[i][j] = func(i+1, j, k+1);
        } else if (str2[j] == str3[k]) {
            return dp[i][j] = func(i, j+1, k+1);
        } else {
            return dp[i][j] = false;
        }
    }
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.length() + s2.length() != s3.length()) return false;
        memset(dp, -1, sizeof dp);
        str1 = s1;
        str2 = s2;
        str3 = s3;
        n = s1.length();
        m = s2.length();
        len = s3.length();
        return func(0, 0, 0);
    }
};