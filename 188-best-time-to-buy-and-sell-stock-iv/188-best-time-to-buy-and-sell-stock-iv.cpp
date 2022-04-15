class Solution {
private:
    vector<int> v;
    int k, n;
    int dp[1001][101][2];
public:
    int func(int i, int j, int buy) {
        if (i == n || j == k) {
            return 0;
        }
        if (dp[i][j][buy] != -1) return dp[i][j][buy];
        if (buy == true) {
            return dp[i][j][buy] = max(-v[i] + func(i+1, j, !buy), func(i+1, j, buy));
        } else {
            // sell
            return dp[i][j][buy] = max(v[i] + func(i+1, j+1, !buy), func(i+1, j, buy));
        }
    }
    int maxProfit(int K, vector<int>& prices) {
        k = K; n = prices.size();
        v = prices;
        memset(dp, -1, sizeof dp);
        return func(0, 0, 1);
    }
};