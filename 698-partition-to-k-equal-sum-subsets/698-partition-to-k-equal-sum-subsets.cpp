class Solution {
private:
    vector<int> v;
    int k;
    vector<bool> vis;
public:
    bool func(int i, int a, int level, int target) {
        if (level == k-1) {
            return true;
        }
        if (i >= v.size()) return false;
        if (a == target) {
            return func(0, 0, level+1, target);
        }
        for(int j=i;j<v.size();j++) {
            if (!vis[j] && a + v[j] <= target) {
                vis[j] = true;
                if (func(j+1, a + v[j], level, target)) 
                    return true;
                vis[j] = false;
            }
        }
        return false;
    }
    bool canPartitionKSubsets(vector<int>& v1, int K) {
        v = v1; k = K;
        int sm = 0;
        for(auto it:v) sm += it;
        if (sm < k || sm % k) return false;
        vis.resize(v1.size(), false);
        sort(v.begin(), v.end(), greater<int> ());
        return func(0, 0, 0, sm/k);
    }
};