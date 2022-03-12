class Solution {
public:
    bool carPooling(vector<vector<int>>& v, int capacity) {
        int a[1010]; memset(a, 0, sizeof a);
        for(auto it:v) a[it[1]] += it[0], a[it[2]] -= it[0];
        int sm = 0;
        for(auto it:a) {
            sm += it;
            if (sm > capacity) return false;
        }
        return true;
    }
};