class Solution {
    vector<vector<int> > ans;
    vector<int> v;
    vector<bool> vis;
public:
    void func(int i, vector<int> temp) {
        if (i == v.size()) {
            ans.push_back(temp);
            return;
        }
        for(int j=i;j<v.size();j++) {
            swap(v[i], v[j]);
            temp.push_back(v[i]);
            func(i+1, temp);
            temp.pop_back();            
            swap(v[i], v[j]);            
        }
        // for(int j=0;j<v.size();j++) {
        //     if (!vis[j]) {
        //         vis[j] = true;
        //         temp.push_back(v[j]);
        //         func(i+1, temp);
        //         temp.pop_back();
        //         vis[j] = false;
        //     }
        // }
    }
    vector<vector<int>> permute(vector<int>& V) {
        v = V;
        vis.resize(v.size(), false);
        func(0, vector<int> {});
        return ans;
    }
};

// 1 2 3 4 
