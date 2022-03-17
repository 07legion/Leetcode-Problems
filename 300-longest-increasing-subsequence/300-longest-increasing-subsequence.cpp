class Solution {
public:
    int lengthOfLIS(vector<int>& v) {
        int n = v.size();
        vector<int> ans;
        for(int i=0;i<n;i++) {
            if (ans.empty()) ans.push_back(v[i]);
            else if (v[i] > ans.back()) ans.push_back(v[i]);
            else {
                int index = lower_bound(ans.begin(), ans.end(), v[i]) - ans.begin();
                ans[index] = v[i]; 
            }
        }
        return ans.size();
    }
};