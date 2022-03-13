class Solution {
private:
    vector<int> v[100007];
    vector<bool> vis;
    vector<bool> rec;
public:
    bool dfs(int u) {
        vis[u] = true;
        rec[u] = true;
        for(auto it:v[u]) {
            if (vis[it] && rec[it]) return true;
            if (!vis[it] && dfs(it)) return true;
        }
        rec[u] = false;
        return false;
    }
    bool canFinish(int n, vector<vector<int>>& p) {
        for(int i=0;i<p.size();i++) {
            int a = p[i][0], b = p[i][1];
            v[b].push_back(a);
        }
        vis.resize(n, false);
        rec.resize(n, false);        
        bool a = false;
        for(int i=0;i<n;i++) {
            if (!vis[i])
                a |= dfs(i);
        }
        return !a;
    }
};