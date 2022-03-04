class Solution {
public:
    double champagneTower(int x, int row, int glass) {
        double dp[110][110] = {0.0};
        // memset(dp, 0.0, sizeof dp);
        dp[0][0] = x;
        for(int i=0;i<=100;i++) {
            for(int j=0;j<=i;j++) {
                if (dp[i][j] >= 1) {
                    dp[i+1][j] += (dp[i][j]-1.0) / 2.0;
                    dp[i+1][j+1] += (dp[i][j]-1.0) / 2.0;
                    dp[i][j] = 1;
                }
            }
        }
        return dp[row][glass];
    }
};