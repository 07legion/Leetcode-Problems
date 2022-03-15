class Solution {
public:
    int maxProfit(vector<int>& v) {
        int n = v.size();
        vector<int> left(n+1, 0), right(n+1, 0);
        int lMin = v[0];
        for(int i=1;i<n;i++) {
            left[i] = max(left[i-1], v[i] - lMin);
            lMin = min(lMin, v[i]);
        }
        int rMax = v[n-1];
        for(int i=n-2;i>=0;i--) {
            right[i] = max(right[i+1], rMax - v[i]);
            rMax = max(rMax, v[i]);
        }
        int ans = right[0];
        for(int i=1;i<n;i++) {
            ans = max(ans, left[i-1] + right[i]);
        }
        return ans;
   }
};