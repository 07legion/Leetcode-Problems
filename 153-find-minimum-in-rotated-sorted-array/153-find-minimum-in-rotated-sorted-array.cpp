class Solution {
public:
    int findMin(vector<int>& v) {
        int n = v.size();
        int low = 0, high = n-1, ans = 0;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if (v[low] <= v[high]) return v[low];
            if (v[(mid + 1) % n] >= v[mid] && v[(mid + n - 1) % n] >= v[mid]) 
                return v[mid];
            if (v[low] <= v[mid]) low = mid + 1;
            else high = mid - 1;
        }
        return -1;
    }
};