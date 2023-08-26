class Solution {
private:
    vector<vector<int> > v;
    vector<bool> vis;
    int n;
public:
    void dfs1(int u) {
        vis[u] = true;
        vector<int> keys = v[u];
        for(auto it:keys) {
            if (vis[it]) continue;
            dfs1(it);
        }
    }
     bool canVisitAllRooms(vector<vector<int>>& V) {
        v = V;

        n = V.size();
        vis.resize(n, false);
        dfs1(0);
        for(int i=0;i<n;i++) {
            if (!vis[i]) return false;
        }

        return true;
    }
};

