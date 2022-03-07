const long long int mod = 1e9 + 7;
class Solution {
private:
    long long int dp[501][501];
private:
    long long int func(int p, int u) {
        if (p == 0 && u == 0) return 1;
        if (p < 0 || u < 0 || u < p) return 0ll;
        if (dp[p][u] != -1ll) return dp[p][u];
        return dp[p][u] = p * func(p-1, u) % mod + (u - p) * func(p, u - 1) % mod;
    }
public:
    int countOrders(int n) {
        memset(dp, -1ll, sizeof dp);
        return int(func(n, n));
    }
};