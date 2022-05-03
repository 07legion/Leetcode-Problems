class Solution {
private:
    vector<int> dp, v;
    int k, n;
public:
    int func(int i) {
        if (i == n) return 0;
        int mx = INT_MIN, ans = 0;
        if (dp[i] != -1) return dp[i];
        for(int j=i;j<min(i + k, n);j++) {
            mx = max(mx, v[j]);
            ans = max(ans, mx * (j - i + 1) + func(j+1));
        }
        return dp[i] = ans;
    }
    int maxSumAfterPartitioning(vector<int>& V, int K) {
        v = V; k = K;
        n = v.size();
        dp.resize(n+1, -1);
        return func(0);
    }
};


