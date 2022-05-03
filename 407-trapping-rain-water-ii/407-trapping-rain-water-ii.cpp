class Solution {
public:
    int trapRainWater(vector<vector<int>>& v) {
        priority_queue<vector<int> , vector<vector<int> >, greater <vector<int> > > pq;
        int n = v.size(), m = v[0].size();
        int vis[n+1][m+1];
        memset(vis, false, sizeof vis);
        for(int i=0;i<n;i++) {
            pq.push({v[i][0], i, 0});
            pq.push({v[i][m-1], i, m-1});
            vis[i][0] = vis[i][m-1] = true;
        }
        for(int i=0;i<m;i++) {
            pq.push({v[0][i], 0, i});
            pq.push({v[n-1][i], n-1, i});
            vis[0][i] = vis[n-1][i] = true;
        }
        int dx[4] = {0, -1, 1, 0};
        int dy[4] = {1, 0, 0, -1};
        int ans = 0;
        while(!pq.empty()) {
            int h = pq.top()[0];
            int i = pq.top()[1]; 
            int j = pq.top()[2];            
            pq.pop();
            for(int p=0;p<4;p++) {
                int x = i + dx[p];
                int y = j + dy[p];
                if (x >= 0 && x < n && y >= 0 && y < m && !vis[x][y]) {
                    ans += max(0, h - v[x][y]);
                    vis[x][y] = true;
                    pq.push({max(v[x][y], h), x, y});
                }
            }
        }
        return ans;
    }
};