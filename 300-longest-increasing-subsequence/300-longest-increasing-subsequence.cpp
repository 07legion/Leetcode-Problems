class Solution {
public:
    int lengthOfLIS(vector<int>& v) {
        // int n = v.size();
        // vector<int> ans;
        // for(int i=0;i<n;i++) {
        //     if (ans.empty()) {
        //         ans.push_back(v[i]);
        //     } else {
        //         if (v[i] > ans.back()) ans.push_back(v[i]);
        //         else {
        //             int ind = lower_bound(ans.begin(), ans.end(), v[i]) - ans.begin();
        //             ans[ind] = v[i];
        //         }
        //     }
        // }
        // return ans.size();
        int n = v.size();
        vector<int> lis(n, 0);
        lis[0] = 1;
        int mx = INT_MIN;
        for(int i=1;i<n;i++) {
            lis[i] = 1;
            for(int j=0;j<i;j++) {
                if (v[j] < v[i] && lis[i] < lis[j] + 1) {
                    lis[i] = lis[j] + 1;
                }
            }
        }
        for(int i=0;i<n;i++) mx = max(mx, lis[i]);
        return mx;
    }
};