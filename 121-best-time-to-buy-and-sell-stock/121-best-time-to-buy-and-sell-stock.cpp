class Solution {
public:
    int maxProfit(vector<int>& v) {
        int n = v.size();
        vector<int> rightMax(n, 0);
        rightMax[n-1] = v[n-1];
        for(int i=n-2;i>=0;i--) {
            rightMax[i] = max(v[i], rightMax[i+1]);
        }
        int mx = INT_MIN;
        for(int i=0;i<n-1;i++) {
            mx = max(mx, rightMax[i+1] - v[i]);
        }
        return mx >= 0 ? mx : 0;
    }
};