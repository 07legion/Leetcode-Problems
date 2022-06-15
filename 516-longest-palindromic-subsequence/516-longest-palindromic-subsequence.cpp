class Solution {
private:
    int dp[1001][1001];
    string str;
public:
    int func(int i , int j) {
        if (i == j) {
            if (str[i] == str[j])
                return 1;
            return 0;
        }
        if (i > j) {
            return 0;
        }
        if (dp[i][j] != -1) return dp[i][j];
        if (str[i] == str[j]) {
            return dp[i][j] = 2 + func(i+1, j-1);
        } 
        else return dp[i][j] = max(func(i, j-1), func(i+1, j));
    }
    int longestPalindromeSubseq(string s) {
        str = s;
        memset(dp, -1, sizeof dp);
        return func(0, str.length()-1);
    }
};