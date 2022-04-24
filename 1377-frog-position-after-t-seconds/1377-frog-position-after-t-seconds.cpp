class Solution {
private:
    vector<int> v[101];
    vector<bool> vis;
    int n, t, target;
public:
    void dfs(int u, int tim, double p, double &ans) {
        vis[u] = true;
        int ct = 0;
        for(auto it:v[u]) {
            if (it == u) continue;
            if (!vis[it]) ct++;
        }
        if (target == u) {
            if (tim == t || (ct == 0 && tim < t)) {
                ans = p;
            } else ans = 0; 
            return;
        }
        for(auto it:v[u]) {
            if (vis[it]) continue;
            dfs(it, tim + 1, ((p == 0) ? 1.0 / ct : p * (1.0 / ct)), ans);
        }
    }
    double frogPosition(int N, vector<vector<int>>& edges, int T, int Tar) {
        n = N; t = T; target = Tar;
        for(int i=0;i<edges.size();i++) {
            v[edges[i][0]].push_back(edges[i][1]);
            v[edges[i][1]].push_back(edges[i][0]);
        }
        if (edges.size() == 0) return 1.00000;
        vis.resize(n+1, false);
        double ans = 0.0;
        dfs(1, 0, 0.0, ans);
        return ans;
    }
};