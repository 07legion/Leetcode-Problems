class Solution {
public:
    void nextPermutation(vector<int>& v) {
        int n = v.size();
        if (n == 1) return;
    
        int ind = -1;
        for(int i=n-2;i>=0;i--) {
            if (v[i] < v[i+1]) {
                ind = i; break;
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