class Solution {
private:
    vector<int> v;
    int n, k;
    int dp[501];
public:
    int func(int i) {
        int mx = -1;
        int ans = 0;
        if (dp[i] != -1) return dp[i];
        for(int j=i;j<min(n, i + k);j++) {
            mx = max(mx, v[j]);
            ans = max(ans, (j - i + 1) * mx + func(j + 1));
        }
        return dp[i] = ans;
    }
    int maxSumAfterPartitioning(vector<int>& V, int K) {
        v = V; k = K; n = v.size();
        memset(dp, -1, sizeof dp);
        return func(0);
    }
};


