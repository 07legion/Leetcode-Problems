class Solution {
public:
    vector<int> rearrangeArray(vector<int>& v) {
        vector<int> v1;
        vector<int> v2;
        for(int i=0;i<v.size();i++) {
            if (v[i] < 0) v2.push_back(v[i]);
            else v1.push_back(v[i]);
        }
        int a = 0, b = 0;
        for(int i=0;i<v.size();i++) {
            if (i % 2) v[i] = v2[a++];
            else v[i] = v1[b++];
        }
        return v;
    }
};