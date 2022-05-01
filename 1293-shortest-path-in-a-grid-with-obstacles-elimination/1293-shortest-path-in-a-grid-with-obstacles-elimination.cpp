struct s {
    int i;
    int j;
    int level;
    int obs;
};

class Solution {
public:
    int shortestPath(vector<vector<int>>& v, int k) {
        int n = v.size(), m = v[0].size();
        queue<s> q;
        q.push({0, 0, 0, 0});
        int vis[n+1][m+1]; memset(vis, -1, sizeof vis);
        int ans = INT_MAX;
        int dx[4] = {0, 1, -1, 0};
        int dy[4] = {-1, 0, 0, 1};
        while(!q.empty()) {
            s temp = q.front(); q.pop();
            int i = temp.i, j = temp.j, level = temp.level, obs = temp.obs;
            if (i == n-1 && j == m-1) {
                ans = min(ans, level);
            }
            if (i < 0 || i >= n || j < 0 || j >= m) continue;
            if (v[i][j] == 1) {
                if (obs + 1 <= k) obs++;
                else continue;
            }
            if (vis[i][j] != -1 && vis[i][j] <= obs) continue;
            vis[i][j] = obs;
            for(int p=0;p<4;p++) {
                q.push({i + dx[p], j + dy[p], level + 1, obs});
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};