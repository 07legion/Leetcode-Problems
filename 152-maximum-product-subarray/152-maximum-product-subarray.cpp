typedef long long int ll;
class Solution {
public:
    int maxProduct(vector<int>& v) {
        int n = v.size();
        if (n == 0) return 0;
        if (n == 1) return v[0];
        int mx = v[0], mn = v[0], ans = v[0];
        for(int i=1;i<n;i++) {
            int temp = mx;
            mx = max({v[i], mx * v[i], mn * v[i]});
            mn = min({v[i], mn * v[i], temp * v[i]});
            ans = max(ans, mx);
        }
        return ans;
    }
};