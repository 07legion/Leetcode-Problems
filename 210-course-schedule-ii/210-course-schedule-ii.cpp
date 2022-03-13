class Solution {
private:
    vector<int> rec, vis;
    vector<int> v[100009];
    stack<int> st;
public:
    bool dfs(int u) {
        vis[u] = true;
        rec[u] = true;
        for(auto it:v[u]) {
            if (!vis[it] && dfs(it)) return true;
            else if (vis[it] && rec[it]) return true;
        }
        rec[u] = false;
        st.push(u);
        return false;
    }
    vector<int> findOrder(int n, vector<vector<int>>& p) {
        vector<int> ans;
        for(int i=0;i<p.size();i++) {
            int a = p[i][0], b = p[i][1];
            v[b].push_back(a);
        }
        vis.resize(n+1, false);
        rec.resize(n+1, false);
        bool a = false;
        for(int i=0;i<n;i++) {
            if (!vis[i]) {
                a |= dfs(i);
            }
        }
        if (a) return vector<int> {};
        while(!st.empty()) ans.push_back(st.top()), st.pop();
        return ans;
    }
};