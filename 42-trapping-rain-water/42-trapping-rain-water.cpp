class Solution {
public:
    int trap(vector<int>& v) {
        int n = v.size();
        int lMax = 0, rMax = 0;
        int i = 0, j = n-1, ans = 0;
        while(i <= j) {
            if (v[i] <= v[j]) {
                if (v[i] >= lMax) lMax = v[i];
                else ans += lMax - v[i];
                i++;
            } else {
                if (v[j] >= rMax) rMax = v[j];
                else ans += rMax - v[j];
                j--;
            }
        }
        return ans;
    }
};


