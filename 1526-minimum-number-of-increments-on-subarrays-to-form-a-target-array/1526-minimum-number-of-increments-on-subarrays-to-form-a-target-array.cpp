class Solution {
public:
    int minNumberOperations(vector<int>& v) {
        int a = v[0], ans = v[0];
        for(int i=1;i<v.size();i++) {
            if (v[i] <= a) {
                a = v[i];
            } else ans += v[i] - a, a = v[i];
        }
        return ans;
    }
};

//     1 2 3 2 1
    
//     0 0 0 0 0
//     1 1 1 1 1
//     1 2 2 2 1
//     1 2 3 2 1