typedef long long int ll;
class Solution {
public:
    int maxProduct(vector<int>& v) {
        int n = v.size();
        ll currMax = v[0], currMin = v[0], mx = v[0];
        for(int i=1;i<n;i++) {
            ll temp = currMin;
            currMin = min({ll(v[i]), currMax * v[i], currMin * v[i]});
            currMax = max({ll(v[i]), currMax * v[i], temp * v[i]});
            mx = max(mx, currMax);
        }
        return mx;
    }
};