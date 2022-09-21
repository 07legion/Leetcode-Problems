class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1) return vector<int> {0};
        unordered_set<int> v[n+1];
        for(auto it:edges) {
            v[it[0]].insert(it[1]);
            v[it[1]].insert(it[0]);
        }
        vector<int> leaves;
        for(int i=0;i<n;i++) {
            if (v[i].size() == 1) 
                leaves.push_back(i);
        }
        while(leaves.size() > 1) {
            if (leaves.size() == 2) {
                if (*v[leaves[0]].begin() == leaves[1] && leaves[0] == *v[leaves[1]].begin())
                    return leaves;
            }
            unordered_set<int> st;
            for(auto it:leaves) {
                int parent = *v[it].begin();
                v[parent].erase(it);
                if (v[parent].size() == 1)
                    st.insert(parent);
            }
            leaves = vector<int> (st.begin(), st.end());
        }
        return leaves;
    }
};