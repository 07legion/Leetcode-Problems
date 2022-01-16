class Solution {
public:
    int getMaxLen(vector<int>& v) {
        int ans = 0, n = v.size();
        int pos = 0, neg = 0;
        for(int i=0;i<n;i++) {
            if (v[i] == 0) {
                pos = 0;
                neg = 0;
            } else if (v[i] > 0) {
                pos++;
                neg = neg == 0 ? 0 : neg + 1; 
            } else {
                int temp = pos;
                pos = neg == 0 ? 0 : neg + 1;
                neg = temp + 1;
            }
            ans = max(ans, pos);
        }
        return ans;
    }
};