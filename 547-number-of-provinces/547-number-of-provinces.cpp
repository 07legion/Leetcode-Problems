class Solution {
private:
    vector<int> v[201];
    vector<bool> vis;
public:
    void dfs(int u) {
        vis[u] = true;
        for(auto it:v[u]) {
            if (vis[it]) continue;
            dfs(it);
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        // i, j
        for(int i=0;i<isConnected.size();i++) {
            for(int j=0;j<isConnected[i].size();j++) {
                if (i == j) continue;
                if (isConnected[i][j] == 1) {
                    v[i].push_back(j);
                    v[j].push_back(i);
                }
            }
        }
        int ct = 0;
        vis.resize(isConnected.size()+1, false);
        for(int i=0;i<isConnected.size();i++) {
            if (!vis[i]) {
                dfs(i);
                ct++;
            }
        }
        return ct;
    }
};

//   1 2 3
// 1 1 1 0
// 2 1 1 0
// 3 0 0 1


