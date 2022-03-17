class Solution {
public:
    int orangesRotting(vector<vector<int>>& v) {
        queue<pair<pair<int, int> , int> > q;
        int n = v.size(), m = v[0].size();
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if (v[i][j] == 2) q.push({{i, j}, 0});
            }
        }
        bool vis[n+1][m+1];
        memset(vis, false, sizeof vis);
        int ans = 0;
        while(!q.empty()) {
            auto[i, j] = q.front().first; 
            int t = q.front().second;
            q.pop();
            if (vis[i][j]) continue;
            ans = max(ans, t);
            vis[i][j] = true;
            ans = max(ans, t);
            if(i + 1 < n && !vis[i + 1][j] && v[i + 1][j] == 1) 
                q.push({{i + 1, j}, t + 1});
            if(i - 1 >= 0 && !vis[i - 1][j] && v[i - 1][j] == 1) 
                q.push({{i - 1, j}, t + 1});
            if(j + 1 < m && !vis[i][j + 1] && v[i][j + 1] == 1) 
                q.push({{i, j + 1}, t + 1});
            if(j - 1 >= 0 && !vis[i][j - 1] && v[i][j - 1] == 1) 
                q.push({{i, j - 1}, t + 1});
        }
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if (!vis[i][j] && v[i][j] == 1) return -1;
            }
        }
        return ans;
    }
};