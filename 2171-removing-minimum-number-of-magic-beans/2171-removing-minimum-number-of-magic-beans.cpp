typedef unsigned long long int ulli;
class Solution {
public:
    long long minimumRemoval(vector<int>& v) {
        int n = v.size();
        if (n == 1) return 0;
        sort(v.begin(), v.end());
        vector<unsigned long long int> suff(n, 0), pre(n, 0);
        suff[n-1] = v[n-1]; pre[0] = v[0];
        for(int i=n-2;i>=0;i--) suff[i] = suff[i+1] + v[i];
        for(int i=1;i<n;i++) pre[i] = pre[i-1] + v[i];
        unsigned long long int ans = LLONG_MAX;
        bool flag = true;
        for(int i=0;i<n;i++) {
            if (i == n-1) {
                ans = min(ans, pre[i]);
            } 
            else {
                if (v[i] != v[i+1]) flag = false;
                unsigned long long int temp = suff[i+1] - (ulli(v[i+1]) * ulli(n-i-1));
                if (i == 0) {
                    ans = min(ans, suff[i+1] - (ulli(v[i]) * ulli(n-i-1)));
                }
                ans = min(ans, pre[i] + temp);
            }
        }
        if (flag) return 0;
        
        return ans;
    }
};