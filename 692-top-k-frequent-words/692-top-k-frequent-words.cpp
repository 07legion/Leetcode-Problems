class Solution {
private:
    unordered_map<string, int> r;
public:
    static bool cmp(pair<pair<int, string>, int>& p1, pair<pair<int, string>, int>& p2) {
        return (p1.first.first > p2.first.first) || (p1.first.first == p2.first.first && p1.second < p2.second);
    }
    vector<string> topKFrequent(vector<string>& v, int k) {
        sort(v.begin(), v.end());
        for(int i=0;i<v.size();i++) r[v[i]] = i+1;
        unordered_map<string, int> mp;
        for(auto it:v) mp[it]++;
        vector<pair<pair<int, string>, int> > vect;
        for(auto it:mp) vect.push_back({{it.second, it.first}, r[it.first]});
        sort(vect.begin(), vect.end(), cmp);
        vector<string> ans;
        for(int i=0;i<vect.size() && k--;i++) {
            ans.push_back(vect[i].first.second);
        }
        return ans;
    }
};