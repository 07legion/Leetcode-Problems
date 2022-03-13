class Solution {
public:
    int maxSubArray(vector<int>& v) {
        int mx = INT_MIN, curr = 0;
        int n = v.size();
        for(int i=0;i<n;i++) {
            if (curr + v[i] >= v[i]) {
                curr += v[i];
            } else curr = v[i];
            mx = max(mx, curr);
        }
        return mx;
    }
};