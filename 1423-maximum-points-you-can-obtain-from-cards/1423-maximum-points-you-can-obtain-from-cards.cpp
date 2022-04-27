class Solution {
public:
    int maxScore(vector<int>& v, int k) {
        int n = v.size();
        int left = 0, right = 0;
        for(int i=0;i<k;i++) left += v[i];
        int ans = left;
        for(int i=0;i<k;i++) {
            left -= v[k-i-1];
            right += v[n-i-1];
            ans = max(ans, left + right);
        }
        return ans;
    }
};