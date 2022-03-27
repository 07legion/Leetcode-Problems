class Solution {
public:
    void setZeroes(vector<vector<int>>& v) {
        int n = v.size(), m = v[0].size();
        vector<bool> row(n, false), col(n, false);
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if (v[i][j] == 0) {
                    row[i] = true;
                    col[j] = true;
                }
            }
        }
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if (row[i] || col[j]) {
                    v[i][j] = 0;
                }
            }
        }
    }
};