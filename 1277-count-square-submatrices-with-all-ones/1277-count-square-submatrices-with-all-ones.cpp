class Solution {
public:
    int countSquares(vector<vector<int>>& v) {
        int n = v.size(), m = v[0].size();
        int dp[n+1][m+1];
        for(int i=0;i<n;i++) dp[i][0] = v[i][0];
        for(int i=0;i<m;i++) dp[0][i] = v[0][i];
        for(int i=1;i<n;i++) {
            for(int j=1;j<m;j++) {
                if (v[i][j] == 1)
                    dp[i][j] = 1 + min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]});
                else dp[i][j] = 0;
            }
        }
        int ans = 0;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) ans += dp[i][j];
        }
        return ans;
    }
};