class Solution {
private:
    vector<int> parent, ran;
public:
    void makeSet(int u) {
        parent[u] = u;
        ran[u] = 0;
    }
    int findSet(int u) {
        if (parent[u] == u) return u;
        return findSet(parent[u]);
    }
    void unionSet(int u, int v) {
        u = findSet(u);
        v = findSet(v);
        if (u != v) {
            if (ran[u] < ran[v]) swap(u, v);
            parent[v] = u;
            if (ran[u] == ran[v]) ran[u]++;
        }
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        ran.resize(n+1, 0);
        parent.resize(n+1, 0);
        for(int i=0;i<n;i++) makeSet(i);
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                if (isConnected[i][j]) {
                    unionSet(i, j);
                }
            }
        }
        set<int> st;
        for(int i=0;i<n;i++) st.insert(findSet(i));
        return st.size();
    }
};


