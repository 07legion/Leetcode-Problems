class Solution {
public:
    void wiggleSort(vector<int>& v) {
        int n = v.size();
        if (n == 1) return;
        sort(v.begin(), v.end());
        vector<int> temp(n, 0);
        int i = 1, j = n-1;
        while(i < n && j >= 0) {
            temp[i] = v[j--];
            i += 2;
        }
        i = 0;
        while(i < n && j >= 0) {
            temp[i] = v[j--];
            i += 2;
        }
        v = temp;
    }
};