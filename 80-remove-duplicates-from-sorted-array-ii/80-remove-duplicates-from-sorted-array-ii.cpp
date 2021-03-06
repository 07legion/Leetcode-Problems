class Solution {
public:
    int removeDuplicates(vector<int>& v) {
        int n = v.size();
        int i = 0;
        for(auto it:v) {
            if (i < 2 || v[i-2] != it) v[i++] = it;
        }
        return i;
    }
};