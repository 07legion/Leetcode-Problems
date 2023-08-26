class Solution {
private:
    vector<vector<int> > v;
    int n;
    vector<int> parent;
    vector<int> ran; // rank;
public:
    void makeSet(int u) {
        parent[u] = u;
        ran[u] = 0;
    }
    int findSet(int u) {
        if (parent[u] == u) return u;
        return parent[u] = findSet(parent[u]);
    }
    void unionSet(int u, int v) {
        if (u == v) return;
        u = findSet(u);
        v = findSet(v);
        if (ran[u] < ran[v]) swap(u, v);
        parent[v] = u;
        if (ran[u] == ran[v]) ran[u]++;
    }
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        v = dislikes;
        n = N;
        parent.resize(n+1, 0);
        ran.resize(n+1, 0);
        for(int i=0;i<=n;i++) makeSet(i);
        vector<int> vect[2011];
        for(auto it:v) {
            vect[it[0]].push_back(it[1]);
            vect[it[1]].push_back(it[0]);
        }
        for(int i=1;i<=n;i++) {
            int a = findSet(i);
            if (vect[i].size()) {
                for(int j=0;j<vect[i].size()-1;j++) {
                    unionSet(vect[i][j], vect[i][j+1]);
                }
                if (a == findSet(vect[i][0])) 
                    return false;
            }
        }
        return true;
    }
};