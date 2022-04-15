class Solution {
public:
    int maxProfit(vector<int>& v) {
        int ans = 0, n = v.size();
        vector<int> left(n, 0), right(n, 0);
        int lMin = v[0], rMax = v[n-1];
        for(int i=1;i<n;i++) {
            left[i] = max(left[i-1], v[i] - lMin);
            lMin = min(lMin, v[i]);
        }
        for(int i=n-2;i>=0;i--) {
            right[i] = max(right[i+1], rMax - v[i]);
            rMax = max(rMax, v[i]);
        }
        ans = right[0];
        for(int i=0;i<n-1;i++) {
            ans = max(ans, left[i] + right[i+1]);
        }
        return ans;
   }
};