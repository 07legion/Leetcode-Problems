class Solution {
public:
    int maxProfit(vector<int>& v) {
        int n = v.size(), ans = 0;
        for(int i=0;i<n;i++) {
            while(i+1 < n && v[i] > v[i+1]) {
                i++;
            }
            int valley = v[i];
            while(i+1 < n && v[i] < v[i+1]) {
                i++;
            }
            int peak = v[i];
            ans += peak - valley;
        }
        return ans;
    }
};