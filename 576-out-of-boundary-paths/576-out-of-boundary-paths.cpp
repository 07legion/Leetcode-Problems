typedef long long int ll;
const ll mod = 1e9 + 7;
class Solution {
private:
    ll n, m;
    ll dp[52][52][52];
public:
    ll func(ll i, ll j, ll t) {
        if (i >= n || i < 0 || j < 0 || j >= m) {
            if (t >= 0ll) return 1ll;
            return 0ll;
        }
        if (t < 0ll) return 0ll;
        if (dp[i][j][t] != -1ll) return dp[i][j][t] % mod;
        return dp[i][j][t] = ((func(i, j+1, t-1) % mod) + (func(i, j-1, t-1) % mod) + (func(i+1, j, t-1) % mod) + (func(i-1, j, t-1) % mod)) % mod;
    }
    int findPaths(int M, int N, int maxMove, int startRow, int startColumn) {
        n = M; m = N;
        memset(dp, -1ll, sizeof dp);
        return func(startRow, startColumn, maxMove) % mod;
    }
};