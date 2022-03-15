class Solution {
public:
    void sortColors(vector<int>& v) {
        int n = v.size();
        // Dutch National Flag Algo!!
        int low = 0, mid = 0, high = n - 1;
        while(mid <= high) {
            if (v[mid] == 0) {
                swap(v[mid], v[low]);
                low++; mid++;
            } else if (v[mid] == 1) mid++;
            else {
                swap(v[mid], v[high]);
                high--;
            }
        }
        return;
    }
};