class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& v, int k) {
        int low = 0, high = 0, ans = 0, n = v.size();
        int prod = 1;
        while(low < n && high < n) {
            if (prod * v[high] < k) {
                prod *= v[high];
                ans += high - low + 1;
                high++;
            } else {
                prod /= v[low];
                low++;
                if (low > high) {
                    prod = 1;
                    high = low;
                }
            }
        }
        return ans;
    }
};