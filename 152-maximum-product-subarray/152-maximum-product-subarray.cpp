typedef long long int ll;
class Solution {
public:
    int maxProduct(vector<int>& v) {
        int n = v.size();
        int mx = v[0];
        int curr_min = v[0], curr_max = v[0];
        for(int i=1;i<n;i++) {
            int temp = curr_min;
            curr_min = min({curr_min * v[i], curr_max * v[i], v[i]});
            curr_max = max({curr_max * v[i], temp * v[i], v[i]});
            mx = max(mx, curr_max);
        }
        return mx;
    }
};