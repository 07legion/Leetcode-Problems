class Solution {
private:
    vector<vector<int> > ans;
public:
    void func(int i, vector<int> temp, vector<int> v) {
        if (i == -1) {
            ans.push_back(temp);
            return;
        }
        temp.push_back(v[i]);
        func(i-1, temp, v);
        temp.pop_back();
        func(i-1, temp, v);
    }
    vector<vector<int>> subsets(vector<int>& v) {
        func(v.size()-1, vector<int> {}, v);
        return ans;
    }
};