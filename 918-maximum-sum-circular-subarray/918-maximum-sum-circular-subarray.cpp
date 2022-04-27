class Solution {
public:
    int maxSubarraySumCircular(vector<int>& v) {
        int n = v.size();
        bool flag = false;
        for(auto it:v) {
            if (it > 0) {
                flag = true; break;
            }
        }
        if (!flag) return *max_element(v.begin(), v.end());
        int sm = 0;
        for(int i=0;i<n;i++) {
            v[i] *= -1;
            sm += v[i];
        }
        int mx = INT_MIN, curr_sum = 0;
        for(int i=0;i<n;i++) {
            if (curr_sum + v[i] >= v[i]) {
                curr_sum += v[i];
            } else curr_sum = v[i];
            mx = max(mx, curr_sum);
        }
        int a = mx - sm;
        for(int i=0;i<n;i++) {
            v[i] *= -1;
        }
        curr_sum = 0; mx = INT_MIN;
        for(int i=0;i<n;i++) {
            if (curr_sum + v[i] >= v[i]) {
                curr_sum += v[i];
            } else curr_sum = v[i];
            mx = max(mx, curr_sum);
        }
        return max(a, mx);
    }
};