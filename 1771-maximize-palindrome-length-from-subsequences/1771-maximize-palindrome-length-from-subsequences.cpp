class Solution {
private:
    string str1, str2, str;
    int dp[2001][2001];
    int n, m, N;
    int ans;
public:
    int func(int i, int j) {
        if (i > j) return 0;
        if (i == j) return 1 + func(i+1, j-1);
        if (dp[i][j] != -1) return dp[i][j];
        if (str[i] == str[j]) {
            int a = 2 + func(i+1, j-1);
            if (i < n && j >= n) 
                ans = max(ans, a);
            return dp[i][j] = a;
        }
        return dp[i][j] = max(func(i+1, j), func(i, j-1));
    }
    int longestPalindrome(string word1, string word2) {
        string str1 = word1, str2 = word2;
        n = str1.length(); m = str2.length();
        memset(dp, -1, sizeof dp);
        str = word1 + word2;
        int a = func(0, n + m -1);
        return ans;
    }
};