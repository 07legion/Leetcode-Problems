class Solution {
private:
    int n, m;
    vector<int> parent, ran;
    bool vis[502][502];
    vector<int> dx, dy;
    map<int, int> mp;
    vector<vector<int> > v;
public:
    void makeSet(int u) {
        parent[u] = u;
        ran[u] = 0;
    }
    int findSet(int u) {
        if (u == parent[u]) return u;
        return findSet(parent[u]);
    }
    void unionSet(int u, int v) {
        u = findSet(u);
        v = findSet(v);
        if (v == u) return;
        if (ran[u] < ran[v]) swap(u, v);
        parent[v] = u;
        if (ran[u] == ran[v]) ran[u]++;
    }
    void dfs(int i, int j, int& size) {
        vis[i][j] = true;
        size++;
        for(int p=0;p<4;p++) {
            int x = i + dx[p], y = j + dy[p];
            if (x < 0 || x >= n || y < 0 || y >= m) continue;
            if (vis[x][y] || v[x][y] == 0) continue;
            unionSet(i * m + j, x * m + y);
            dfs(x, y, size);
        }
    }
    int largestIsland(vector<vector<int>>& V) {
        v = V;
        n = v.size();
        m = v[0].size();
        dx = {0, 1, 0, -1}; dy = {1, 0, -1, 0};
        memset(vis, false, sizeof vis);
        parent.resize(n * m + 2);
        ran.resize(n * m + 2);
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) 
                makeSet(i * m + j);
        }
        int ans = 0;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if (!vis[i][j] && v[i][j] == 1) {
                    int size = 0;
                    dfs(i, j, size);
                    ans = max(ans, size);
                    mp[findSet(i * m + j)] = size;
                }
            }
        }

        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if (v[i][j] == 0) {
                    set<int> st; int temp = 0;
                    for(int p=0;p<4;p++) {
                        int x = i + dx[p], y = j + dy[p];
                        if (x >= 0 && x < n && y >= 0 && y < m && v[x][y] == 1) {
                            int root = findSet(x * m + y);
                            if (st.find(root) == st.end()) {
                                st.insert(root);
                                temp += mp[root];
                            }
                        }
                    }
                    ans = max(ans, temp + 1);
                }
            }
        }
        return ans;
    }
};

//   0 1 2
// 0 1 0 1
// 1 1 1 0
// 2 0 0 1

// m = 3
// i * m + j

// i,j
// 0,0     0
// 0,1     1
// 0,2     2    
// 1,0     3
// 1,1     4
// 1,2     5
// 2,0     6
// 2,1     7
// 2,2     8