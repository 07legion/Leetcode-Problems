class Solution {
public:
    int findPeakElement(vector<int>& v) {
        if (v.size() == 1) return 0;
        int low = 0, high = v.size() - 1;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if (mid == 0) {
                if (v[0] > v[1]) return 0;
                else return 1;
            } else if (mid == v.size() - 1) {
                if (v[v.size()-1] > v[v.size()-2]) return v.size()-1;
                else return v.size()-2;
            } else {
                if (v[mid] > v[mid-1] && v[mid] > v[mid+1]) {
                    return mid;
                } else {
                    if (v[mid] < v[mid - 1]) high = mid - 1;
                    else low = mid + 1;
                }
            }
        }
        return -1;
    }
};