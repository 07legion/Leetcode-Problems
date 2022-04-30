class Solution {
public:
    int firstMissingPositive(vector<int>& v) {
        int n = v.size();
        for(int i = 0; i < n; i++) {
            int j = i;
            while(v[j] >= 1 && v[j] <= n && v[v[j] - 1] != v[j]) {
                swap(v[v[j]-1], v[j]);
            }
        }   
        for(int i=0;i<n;i++) {
            if (v[i] != i+1) return i+1;
        }
        return n+1;
    }
};


// 3 4 -1 1
// 1 2  3 4
// 0 1  2 3



    