class Solution {
private:
    long long int dp[201][201];
    vector<vector<int> > v;
public:
    int func(int i, int j) {
        if (i == v.size()) return 0;
        if (dp[i][j] != -1) return dp[i][j];
        return dp[i][j] = v[i][j] + min(func(i+1, j), func(i+1, j+1));
    }
    int minimumTotal(vector<vector<int>>& v1) {
        memset(dp, -1, sizeof dp);
        v = v1;
        return func(0, 0);
    }
};