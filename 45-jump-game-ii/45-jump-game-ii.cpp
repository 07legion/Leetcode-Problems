class Solution {
public:
    int jump(vector<int>& v) {
        if (v.size() == 1) return 0;
        int n = v.size();
        int l = 0, r = 0, ans = 0;
        while(r < n-1) {
            int farthest = 0;
            for(int j=l;j<=r;j++) 
                farthest = max(farthest, j + v[j]);
            l = r + 1;
            r = farthest;
            ans++;
        }
        return ans;
    }
};