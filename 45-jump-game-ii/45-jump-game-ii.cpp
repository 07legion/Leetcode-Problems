class Solution {
public:
    int jump(vector<int>& v) {
        int n = v.size();
        int i = 0, j = 0, ct = 0;
        while(j < n-1) {
            int mx = INT_MIN;
            for(int p=i;p<=j;p++) mx = max(p + v[p], mx);
            i = j+1;
            j = mx;
            ct++;
        }
        return ct;
    }
};