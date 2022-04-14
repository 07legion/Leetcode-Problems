class Solution {
private:
    int n;
    vector<int> v[30001];
    vector<int> count;
    vector<int> sm;
    vector<bool> vis;
public:
    int dfs(int u) {
        vis[u] = true;
        int ct = 1;
        for(auto it:v[u]) {
            if (vis[it]) continue;
            int a = dfs(it);
            ct += a;
            sm[0] += a;
        }
        return count[u] = ct;
    }
    void dfsa(int u) {
        vis[u] = true;
        for(auto it:v[u]) {
            if (vis[it]) continue;
            sm[it] = sm[u] - count[it] + (n - count[it]);
            dfsa(it);
        }
    }    
    vector<int> sumOfDistancesInTree(int N, vector<vector<int>>& edges) {
        n = N;
        for(int i=0;i<edges.size();i++) {
            int a = edges[i][0], b = edges[i][1];
            v[a].push_back(b);
            v[b].push_back(a);
        }
        count.resize(n, 1);
        sm.resize(n, 0);
        vis.resize(n, false);
        dfs(0);
        fill(vis.begin(), vis.end(), false);
        dfsa(0);
        return sm;
    }
};