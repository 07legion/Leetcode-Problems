class Solution {
public:
    bool searchMatrix(vector<vector<int>>& v, int t) {
        int n = v.size(), m = v[0].size();
        int low = 0, high = n-1;
        int row = 0;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if (v[mid][m-1] == t) {
                row = mid;
                high = mid - 1;
            } else if (v[mid][m-1] < t) {
                low = mid + 1;
            } else {
                row = mid;
                high = mid - 1;
            }
        }
        low = 0; high = m-1;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if (v[row][mid] == t) return true;
            else if (v[row][mid] < t)
                low = mid + 1;
            else high = mid - 1;
        }
        return false;
    }
};