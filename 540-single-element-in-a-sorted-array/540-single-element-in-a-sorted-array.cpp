class Solution {
public:
    int singleNonDuplicate(vector<int>& v) {
        if (v.size() == 1) return v[0];
        int n = v.size();
        if (v[0] != v[1]) return v[0];
        if (v[n-1] != v[n-2]) return v[n-1];
        int low = 0, high = n-1;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if (v[mid] > v[mid-1] && v[mid] < v[mid+1]) return v[mid];
            else if (mid % 2 == 0) {
                if (v[mid] == v[mid+1]) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            } else {
                if (v[mid-1] == v[mid]) {
                    low = mid + 1;
                } else high = mid - 1;
            }
        }  
        return -1;
    }
};