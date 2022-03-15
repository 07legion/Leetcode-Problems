class Solution {
public:
    double findMedianSortedArrays(vector<int>& v1, vector<int>& v2) {
        if (v2.size() < v1.size()) 
            return findMedianSortedArrays(v2, v1);
        int n = v1.size(), m = v2.size();
        int low = 0, high = n;
        while(low <= high) {
            
            int cut1 = low + (high - low) / 2;
            int cut2 = (n + m + 1) / 2 - cut1;
            
            int l1 = cut1 == 0 ? INT_MIN : v1[cut1 - 1];
            int l2 = cut2 == 0 ? INT_MIN : v2[cut2 - 1];
            int r1 = cut1 == n ? INT_MAX : v1[cut1];
            int r2 = cut2 == m ? INT_MAX : v2[cut2];
            
            if (l1 <= r2 && l2 <= r1) {
                if ((n + m) % 2) return double(max(l1, l2));
                else return (max(l1, l2) + min(r1, r2)) / 2.0;
            } else if (l1 > r2) {
                high = cut1 - 1;
            } else low = cut1 + 1;
        }
        return -1;
    }
};


// 1 2 4 7 8 12 20
// 3 5 8 13 
    
// 1 2 3 4 5 7 8 8 12 13 20