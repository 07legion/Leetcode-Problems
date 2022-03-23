class Solution {
public:
    int search(vector<int>& v, int target) {
        if (!v.size()) return -1;
        if (v.size() == 1) {
            if (v[0] == target) return 0;
            return -1;
        }
        int low = 0, high = v.size() - 1;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if (v[mid] == target) return mid;
            else if (v[low] <= v[mid]) {
                if (target >= v[low] && target < v[mid]) 
                    high = mid - 1;
                else low = mid + 1;
            } else {    
                if (target > v[mid] && target <= v[high]) 
                    low = mid + 1;
                else high = mid - 1;
            }
        }
        return -1;
    }
};