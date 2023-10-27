class Solution {
private:
    string s;
    int dp[1002][1002];
public:
    int func(int i, int j) {
        if (i > j) return dp[i][j] = 0;
        if (i == j) return dp[i][j] = 1;
        if (dp[i][j] != -1) return dp[i][j];
        if (s[i] != s[j]) return dp[i][j] = INT_MIN;
        return dp[i][j] = 2 + func(i+1, j-1);
    }
    string longestPalindrome(string str) {
        int n = str.length(), ans = INT_MIN;
        s = str;
        int start = -1, end = -1;
        memset(dp, -1, sizeof dp);
        for(int i=0;i<n;i++) {
            for(int j=i;j<n;j++) {
                int a = func(i, j);
                if (ans < a) {
                    ans = a; start = i; end = j;
                }
            }
        }
        string temp = "";
        if (end == -1 || start == -1) return temp;
        for(int i=start;i<=end;i++) temp += str[i];
        return temp;
    }
};