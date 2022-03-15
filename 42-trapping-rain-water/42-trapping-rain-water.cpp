class Solution {
public:
    int trap(vector<int>& v) {
        int n = v.size(), ans = 0;
        int l = 0, r = n - 1, lMax = 0, rMax = 0;
        while(l <= r) {
            if (v[l] <= v[r]) {
                if (v[l] >= lMax) lMax = v[l];
                else ans += lMax - v[l];
                l++;
            } else {
                if (v[r] >= rMax) rMax = v[r];
                else ans += rMax - v[r];
                r--;
            }
        }
        return ans;
    }
};


