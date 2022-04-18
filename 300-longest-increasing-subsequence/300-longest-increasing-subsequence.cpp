class Solution {
public:
    int lengthOfLIS(vector<int>& v) {
        int n = v.size();
        vector<int> ans;
        for(int i=0;i<n;i++) {
            if (ans.empty()) ans.push_back(v[i]);
            else {
                if (v[i] > ans.back()) ans.push_back(v[i]);
                else {
                    int index = lower_bound(ans.begin(), ans.end(), v[i]) - ans.begin();
                    ans[index] = v[i];
                }
            }
        }
        return ans.size();
        // int n = v.size();        
        // vector<int> lis(n);
        // lis[0] = 1;
        // for(int i=1;i<n;i++) {
        //     lis[i] = 1;
        //     for(int j=0;j<i;j++) {
        //         if (v[i] > v[j] && lis[i] < lis[j] + 1) {
        //             lis[i] = lis[j] + 1;
        //         }
        //     }
        // }
        // int mx = INT_MIN;
        // for(auto it:lis) mx = max(mx, it);
        // return mx;
    }
};