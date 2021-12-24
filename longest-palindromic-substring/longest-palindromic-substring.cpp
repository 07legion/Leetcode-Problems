class Solution {
public:
    string longestPalindrome(string str) {
        
        int n = str.length(), mx = -1;
        int dp[n][n]; memset(dp, -1, sizeof dp);
        function<int(int, int)> func = [&](int i, int j) -> int {
            if (i >= j) return 1;
            if (dp[i][j] != -1) return dp[i][j];
            if (str[i] == str[j]) return dp[i][j] = func(i+1, j-1);
            else return 0;
            // return 1;
        };
        int a = 0, b = 0;
        for(int i=0;i<n;i++) {
            for(int j=i;j<n;j++) {
                if (func(i, j)) {
                    if (mx < abs(i-j)+1) {
                        mx = max(mx, abs(i-j) + 1);
                        a = i; b = j;
                    }
                }
            }
        }
        string ans = "";
        for(int i=a;i<=b;i++) ans += str[i];
        return ans;
    }
};