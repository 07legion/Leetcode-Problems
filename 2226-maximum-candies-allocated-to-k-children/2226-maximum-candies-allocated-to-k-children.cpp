typedef long long ll;
class Solution {
public:
    int maximumCandies(vector<int>& v, long long k) {
        int n = v.size(); ll sm = 0;
        int mx = INT_MIN; //, mn = INT_MAX;
        for(int i=0;i<n;i++) {
            mx = max(mx, v[i]);
            // mn = min(mn, v[i]);
            sm += v[i];
        }
        if (sm < k) return 0;
        int ans = 0, low = 1, high = mx;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            bool flag = false; ll ct = 0;
            for(int j=0;j<n;j++) {
                if (v[j] >= mid) {
                    ct += v[j] / mid;
                }
            }
            flag = (ct >= k);
            if (flag) {
                ans = mid;
                low = mid + 1;
            } else high = mid - 1;
        }
        return ans;
    }
};


// v = [5 10 4]
// k = 3


