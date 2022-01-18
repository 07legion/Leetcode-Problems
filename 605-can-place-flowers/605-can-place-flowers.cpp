class Solution {
public:
    bool canPlaceFlowers(vector<int>& v, int n) {
        if (v.size() == 1 && !v[0] && n == 1) return true;
        if (v.size() == 1 && v[0] && n > 0) return false;
        int t = 2;
        while(t--) {
            int N = n;
            if (t == 0) reverse(v.begin(), v.end());
            int ct = 0;
            for(int i=0;i<v.size() && n > 0;i++) {
                if (v[i] == 0) {
                    if (i == 0) {
                        if (i+1 < v.size() && !v[i+1]) {
                            v[i] = 1; n--; ct++;
                        }
                    } else if (i == v.size()-1) {
                        if (i-1 && !v[i-1]) v[i] = 1, n--, ct++;
                    } else {
                        if (!v[i-1] && !v[i+1]) v[i] = 1, n--, ct++;
                    }
                }
            }
            if (!n) return true;
            N = n;
        }
        return false;
    }
};



// [0]
// 2
// [1]
// 1
// [1]
// 5
// [0]
// 7