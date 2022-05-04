class Solution {
private:
    vector<int> adj[2001];
    vector<bool> vis, rec;
    int n;
public:
    bool dfs(int u) {
        vis[u] = true;
        rec[u] = true;
        for(auto it:adj[u]) {
            if (vis[it] && rec[it]) return true;
            else if (!vis[it] && dfs(it)) return true;
        }
        rec[u] = false;
        return false;
    }
    bool canFinish(int N, vector<vector<int>>& p) {
        n = N;
        for(int i=0;i<p.size();i++) {
            adj[p[i][1]].push_back(p[i][0]);
        }
        vis.resize(n+1, false);
        rec.resize(n+1, false);        
        bool isCycle = false;
        for(int i=0;i<n;i++) {
            if (!vis[i]) {
                isCycle |= dfs(i);
            }
        }
        if (isCycle) return false;
        for(int i=0;i<n;i++) {
            if (!vis[i]) return false;
        }
        return true;
    }
};