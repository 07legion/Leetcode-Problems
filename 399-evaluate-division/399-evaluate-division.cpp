class Solution {
public:
    void dfs(string start, string end, unordered_set<string>& st, unordered_map<string, map<string, double> > mp, double ans, double& isFound) {
        if (mp[start].size() == 0) return;
        if (start == end) {
            isFound = ans;
            return;
        }
        st.insert(start);
        for(auto it:mp[start]) {
            if (st.find(it.first) != st.end()) continue;
            dfs(it.first, end, st, mp, ans * it.second, isFound);
        }
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, map<string, double> > mp;
        for(int i=0;i<equations.size();i++) {
            mp[equations[i][0]].insert({equations[i][1], values[i]});
            if (values[i] != 0) 
                mp[equations[i][1]].insert({equations[i][0], 1 / values[i]});
        }
        vector<double> ans;
        for(int i=0;i<queries.size();i++) {
            double isFound = -1.0;
            unordered_set<string> st;
            dfs(queries[i][0], queries[i][1], st, mp, 1.0, isFound);
            ans.push_back(isFound);
        }
        return ans;
    }
};