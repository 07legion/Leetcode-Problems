class Solution {
public:
    int lengthOfLIS(vector<int>& v) {
        int n = v.size(), ans = 1;
        vector<int> lis(n+1);
        lis[0] = 1;
        for(int i=1;i<n;i++) {
            lis[i] = 1;
            for(int j=0;j<i;j++) {
                if (v[i] > v[j] && lis[i] < lis[j] + 1)
                    lis[i] = lis[j] + 1;
            }
            ans = max(ans, lis[i]);
        }
 //       for(int i=0;i<n;i++) ans = max(ans, lis[i]);
        return ans;
    }
};