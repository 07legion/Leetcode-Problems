class Solution {
public:
    int lengthOfLIS(vector<int>& v) {
        int n = v.size();
        vector<int> lis(n+1);
        lis[0] = 1; int mx = 1;
        for(int i=1;i<n;i++) {
            lis[i] = 1;
            for(int j=0;j<i;j++) {
                if (v[j] < v[i] && lis[i] < lis[j] + 1) {
                    lis[i] = lis[j] + 1;
                }
                mx = max(mx, lis[i]);
            }
        }
        return mx;
    }
};