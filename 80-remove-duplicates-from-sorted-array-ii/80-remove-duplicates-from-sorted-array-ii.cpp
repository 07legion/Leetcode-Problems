class Solution {
public:
    int removeDuplicates(vector<int>& v) {
        int i = 0;
        for(auto it:v) {
            if (i < 2 || v[i-2] != it) {
                v[i++] = it;
            }
        }
        for(auto it:v) cout<<it<<" "; cout<<"\n";
        return i;
    }
};