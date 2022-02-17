class Solution {
private:
    vector<vector<int> > ans; 
    vector<int> v;
public:
    void func(int i, int target, vector<int> temp) {
        if (i == v.size()) {
            if (target == 0) ans.push_back(temp);
            return;
        }
        if (target - v[i] >= 0) {
            temp.push_back(v[i]);
            func(i, target-v[i], temp);
            temp.pop_back();
            func(i+1, target, temp);
        } else {
            func(i+1, target, temp);
        }
    }
    vector<vector<int> > combinationSum(vector<int>& v1, int target) {
        v = v1;
        func(0, target, vector<int> {});
        return ans;
    }
};