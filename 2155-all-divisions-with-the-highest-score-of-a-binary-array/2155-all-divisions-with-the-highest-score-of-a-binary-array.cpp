class Solution {
public:
    vector<int> maxScoreIndices(vector<int>& v) {
        vector<int> ans;
        int n = v.size();
        vector<int> pre0(n, 0), pre1(n, 0);
        pre0[0] = (v[0] == 0 ? 1 : 0);
        pre1[0] = (v[0] == 1 ? 1 : 0);
        for(int i=1;i<n;i++) {
            pre0[i] = pre0[i-1] + (v[i] == 0 ? 1 : 0);
            pre1[i] = pre1[i-1] + (v[i] == 1 ? 1 : 0);
        }
        int mx = -1;
        for(int i=0;i<=n;i++) {
            int left = i != 0 ? pre0[i-1] : 0; // 0 to i-1
            int right = i != 0 ? pre1[n-1] - pre1[i-1] : pre1[n-1] ; // i to n-1;
            if (mx < left + right) {
                mx = left + right;
                ans.clear();
                ans.push_back(i);
            } else if (mx == left + right) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};