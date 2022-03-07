const long long int mod = 1e9 + 7;
class Solution {
public:
    int countOrders(int n) {
        long long int dp[n+1];
        dp[1] = 1;
        // dp[2] = 6;
        for(int i=2;i<=n;i++) {
            long long int a = 2 * 1ll * i - 1ll;
            dp[i] = dp[i-1] * (((a * (a + 1ll)) / 2) % mod);
            dp[i] = dp[i] % mod;
        }
        return dp[n];
    }
};