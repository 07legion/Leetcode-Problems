class Solution {
private:
    vector<int> v[100001];
    int n;
    vector<int> labels;
    set<vector<int> > st;
public:
    int dfs(int u, int parent, int prevLabel) {
        if (labels[u] >= 0) return labels[u];
        labels[u] = 1 + prevLabel;
        
        int mn = INT_MAX;
        for(auto it:v[u]) {
            // if (it == parent) continue;
            if (labels[it] == labels[u]-1) continue;
            int recLabel = dfs(it, u, labels[u]);
            if (labels[u] >= recLabel) {
                st.erase({min(u, it), max(u, it)});
            }
            mn = min(mn, recLabel);
        }
        return mn;
    }
    vector<vector<int>> criticalConnections(int N, vector<vector<int>>& connections) {
        n = N;
        for(int i=0;i<connections.size();i++) {
            int a = connections[i][0], b = connections[i][1];
            v[a].push_back(b);
            v[b].push_back(a);
            st.insert({min(a, b), max(a, b)});
        }
        labels.resize(n+1, -2);
        dfs(0, -1, 0);
        vector<vector<int> > temp;
        for(auto it:st) {
            temp.push_back({it[0], it[1]});
        }
        return temp;
    }
};