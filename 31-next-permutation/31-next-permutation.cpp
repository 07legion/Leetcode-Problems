class Solution {
public:
    void nextPermutation(vector<int>& v) {
        int n = v.size();
        int ind = -1;
        for(int i=n-1;i>0;i--) {
            if (v[i] > v[i-1]) {
                ind = i-1;
                break;
            }
        }
        if (ind == -1) {
            reverse(v.begin(), v.end());
            return;
        }
        for(int i=n-1;i>=0;i--) {
            if (v[i] > v[ind]) {
                swap(v[i], v[ind]);
                reverse(v.begin()+ind+1, v.end());
                break;
            }
        }
        return;
    }
};