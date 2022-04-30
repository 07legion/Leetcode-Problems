class Solution {
public:
    int firstMissingPositive(vector<int>& v) {
        set<int> st(v.begin(), v.end());
        int j = 0;
        for(auto it:st) v[j++] = it;
        if (v.size() == 1) {
            if (v[0] == 1) return 2;
            return 1;
        }
        int ans = -1;
        if (v[0] > 0 && v[0] != 1) return 1;
        
        bool flag = false;
        for(int i=0;i<v.size();i++) {
            if (v[i] == 1) {
                flag = true;
                break;
            }
        }
        if (!flag) return 1;
        for(int i=0;i<v.size() - 1;i++) {
            if (v[i+1] - v[i] != 1) {
                if (v[i] + 1 <= 0) continue;
                ans = v[i] + 1; break;
            }
        }
        if (ans == -1) {
            if (v.back() + 1 <= 0) return 1;
            return v.back() + 1;
        }
        return ans;
    }
};

// -2, -1