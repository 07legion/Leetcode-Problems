class Solution {
private:
    int n, m;
    int dp[1001][1001];    
    string str1, str2;
public:
    int func(int i, int j) {
        if (j == m) return 1;
        if (i == n) return 0;
        if (dp[i][j] != -1) return dp[i][j];
        int ans = 0;
        if (str1[i] == str2[j]) {
            ans += func(i+1, j+1) + func(i+1, j);
        } else {
            ans += func(i+1, j);
        }
        return dp[i][j] = ans;
    }
    int numDistinct(string s1, string s2) {
        str1 = s1; str2 = s2;
        n = str1.length();
        m = str2.length();
        memset(dp, -1, sizeof dp);        
        return func(0, 0);
    }
};