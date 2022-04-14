class Solution {
private:
    vector<int> v;
    int h;
public:
    bool func(int m) {
        int have = h;
        for(auto it:v) {
            have -= ceil(double(it) / m);
            if (have < 0) return false;
        }
        return have >= 0;
    }
    int minEatingSpeed(vector<int>& V, int H) {
        v = V; h = H;
        int low = 1, high = 1e9, ans = INT_MAX;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if (func(mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};