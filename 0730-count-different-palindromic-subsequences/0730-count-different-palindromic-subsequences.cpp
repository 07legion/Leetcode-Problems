class Solution {
private:
    int dp[1000][1000];
public:
    // int solve(string s, int i, int j) {
    //     if(i > j) return 0;
    //     if(i == j) return 1;
    //     if(dp[i][j] != -1) return dp[i][j];
    //     if(s[i] == s[j]){
    //         int cnt = 0;
    //         cnt += 2 * solve(s, i + 1, j - 1);
    //         int l = i + 1, r = j - 1;
    //         while(l <= r && s[l] != s[i]) l++;
    //         while(l <= r && s[r] != s[j]) r--;
    //         if(l < r) cnt -= solve(s, l + 1, r - 1);
    //         else if(l == r) cnt += 1;
    //         else cnt += 2;
    //         dp[i][j] = cnt;
    //     }
    //     else dp[i][j] = solve(s, i + 1, j) + solve(s, i, j - 1) - solve(s, i + 1, j - 1);
    //     return dp[i][j] = dp[i][j] < 0 ? dp[i][j] + 1000000007 : dp[i][j] % 1000000007;
    // }

    // int countPalindromicSubsequences(string s) {
    //     memset(dp, -1, sizeof(dp));
    //     return solve(s, 0, s.size() - 1);
    // }

        int countPalindromicSubsequences(string s) {
        int n = s.size();
        int dp[n][n];
        memset(dp, 0, sizeof(dp));
        for(int i = 0; i < n; i++)
            dp[i][i] = 1;
        for(int k = 1; k < n; k++) {
            int i = 0, j = k;
            while(j < n) {
                if(s[i] == s[j]){
                    int cnt = 0;
                    cnt += 2 * dp[i + 1][j - 1];
                    int l = i + 1, r = j - 1;
                    while(l <= r && s[l] != s[i]) l++;
                    while(l <= r && s[r] != s[j]) r--;
                    if(l < r) cnt -= dp[l + 1][r - 1];
                    else if(l == r) cnt += 1;
                    else cnt += 2;
                    dp[i][j] = cnt;
                }
                else dp[i][j] = dp[i + 1][j] + dp[i][j - 1] - dp[i + 1][j - 1];
                dp[i][j] = dp[i][j] < 0 ? dp[i][j] + 1000000007 : dp[i][j] % 1000000007;
                i++;
                j++;
            }
        }
        return dp[0][n - 1];
    }
};