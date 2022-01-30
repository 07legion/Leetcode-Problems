class Solution {
public:
    void rotate(vector<int>& v, int k) {
        int n = v.size();
        k %= n;
        reverse(v.begin(), v.begin() + n - k);
        reverse(v.begin() + n - k, v.end());
        reverse(v.begin(), v.end());
    }
};