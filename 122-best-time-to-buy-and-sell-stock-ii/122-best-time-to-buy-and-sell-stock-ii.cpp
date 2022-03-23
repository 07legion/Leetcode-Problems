class Solution {
public:
    int maxProfit(vector<int>& v) {
        int ans = 0, n = v.size(), peak = 0, valley = 0;
        for(int i=0;i<n;i++) {
            while(i+1 < n && v[i] >= v[i+1]) {
                i++;
            }
            valley = v[i];
            while(i+1 < n && v[i] <= v[i+1]) {
                i++;
            }
            peak = v[i];
            ans += peak - valley;
        }
        return ans;
    }
};
    

       