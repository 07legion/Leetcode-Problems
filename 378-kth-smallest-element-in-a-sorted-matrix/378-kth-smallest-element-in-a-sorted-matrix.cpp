class Solution {
public:
    int func(int mid, int n, vector<vector<int> > v) {
        int ct = 0;
        for(int i=0;i<n;i++) {
            if (v[i][0] > mid) break;
            for(int j=0;j<n;j++) {
                if (v[i][j] <= mid) 
                    ct++;
            }
        }
        return ct;
    }
    int kthSmallest(vector<vector<int>>& v, int k) { 
        int n = v.size();
        int low = v[0][0], high = v[n-1][n-1];
        int ans = -1;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            int ct = func(mid, n, v);
            if (ct < k) {
                low = mid + 1;
            } else {
                ans = mid;
                high = mid - 1;
            }
        }
        return ans;
    }
};