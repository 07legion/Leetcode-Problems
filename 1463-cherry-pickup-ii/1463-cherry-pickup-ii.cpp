class Solution {
private:
    int dp[70][70][70];
    int n, m;
public:
    int func(int i, int j, int y, vector<vector<int>>& v) {
        if (i < 0 || i >= n || j < 0 || j >= m || y < 0 || y >= m) return 0;
        if (dp[i][j][y] != -1) return dp[i][j][y];
        int temp = max({func(i+1, j-1, y-1, v) , func(i+1, j-1, y, v) , func(i+1, j-1, y+1, v) , func(i+1, j, y-1, v), func(i+1, j, y, v) , func(i+1, j, y+1, v) , func(i+1, j+1, y-1, v) , func(i+1, j+1, y, v) , func(i+1, j+1, y+1, v)});
        if (j == y) {
            return dp[i][j][y] = v[i][j] + temp;
        }
        return dp[i][j][y] = v[i][j] + v[i][y] + temp;
    }
    int cherryPickup(vector<vector<int>>& v) {
        memset(dp, -1, sizeof dp);
        n = v.size(); m = v[0].size();
        return func(0, 0, m-1, v);
    }
};