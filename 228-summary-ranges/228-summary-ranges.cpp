class Solution {
public:
    vector<string> summaryRanges(vector<int>& v) {
        if (!v.size()) return vector<string> {}; 
        if (v.size() == 1) 
            return vector<string> {to_string(v[0])};
        vector<string> ans;
        string temp = to_string(v[0]);
        int last = v[0];
        for(int i=1;i<v.size();i++) {
            if (v[i] == v[i-1] + 1) continue;
            if (last == v[i-1]) {
                ans.push_back(to_string(last));
            }
            else {
                ans.push_back(to_string(last) + "->" + to_string(v[i-1]));
            }
            last = v[i];
        }
        if (last == v[v.size()-1]) {
                ans.push_back(to_string(last));
            }
            else {
                ans.push_back(to_string(last) + "->" + to_string(v[v.size()-1]));
            }
        return ans;
    }
};