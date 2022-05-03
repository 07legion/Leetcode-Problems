class Solution {
private:
    vector<vector<string> > ans;
    string str; int n;
public:
    bool check(string temp) {
        if (temp.size() == 0) return false;
        if (temp.size() == 1) return true;
        int i = 0, j = temp.length()-1;
        while(i < j) {
            if (temp[i] != temp[j]) {
                return false;
            }
            i++; j--;
        }
        return true;
    }
    void func(int i, vector<string> v) {
        if (i == n) {
            ans.push_back(v);
            // for(auto it:v) cout<<it<<" "; cout<<"\n";
            return;
        }
        string a = "";
        for(int j=i;j<n;j++) {
            a += str[j];
            if (check(a)) {
                v.push_back(a);
                func(j+1, v);
                v.pop_back();
            }
        }
    }
    vector<vector<string> > partition(string s) {
        str = s; n = s.length();
        func(0, vector<string> {});
        return ans;
    }
};