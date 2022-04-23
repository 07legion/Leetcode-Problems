class Solution {
private:
    unordered_set<string> st;
    unordered_map<string, int> mp;
public:
    int func(string word) {
        if (mp.find(word) != mp.end()) return mp[word];
        int ans = 1;
        for(int i=0;i<word.length();i++) {
            string temp = word;
            temp.erase(temp.begin() + i);
            if (st.find(temp) != st.end()) 
                ans = max(ans, 1 + func(temp));
        }
        return mp[word] = ans;
    }
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        for(auto it:words) st.insert(it);
        int mx = 0;
        for(int i=0;i<words.size();i++) {
            mx = max(mx, func(words[i]));
        }
        return mx;
    }
};