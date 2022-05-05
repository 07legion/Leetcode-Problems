class Solution {
public:
    double findMedianSortedArrays(vector<int>& v1, vector<int>& v2) {
        if (v2.size() < v1.size()) {
            swap(v1, v2);
        }
        int n = v1.size(), m = v2.size();
        int low = 0, high = n;
        while(low <= high) {
            int cut1 = low + (high - low) / 2;
            int cut2 = ((n + m + 1) / 2) - cut1;
            
            int l1 = (cut1 == 0) ? INT_MIN : v1[cut1-1];
            int r1 = (cut1 == n) ? INT_MAX : v1[cut1];
            int l2 = (cut2 == 0) ? INT_MIN : v2[cut2-1];
            int r2 = (cut2 == m) ? INT_MAX : v2[cut2];            
            
            if (l1 <= r2 && l2 <= r1) {
                if ((n + m) % 2) return double(max(l1, l2));
                else return double(max(l1, l2) + min(r1, r2)) / 2.0;
            } else if (l1 > r2) {
                high = cut1 - 1;
            } else low = cut1 + 1;
        }
        return -1;
    }
};

// cut1 = 4

// 3 6 7 9 10 13
// 2 5 6 9 11 14 16
