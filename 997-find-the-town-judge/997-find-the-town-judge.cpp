class Solution {
public:
    int findJudge(int n, vector<vector<int>>& v) {
        vector<int> vect(n+1, 0);
        for(auto it:v) {
            vect[it[1]]++;
        }
        int ct = 0, a = -1;
        for(int i=1;i<=n;i++) {
            if (vect[i] == n-1) 
                a = i, ct++;
        }
        if (a == -1 || ct > 1) return -1;
        for(auto it:v) {
            if (it[0] == a) return -1;
        }
        return a;
    }
};