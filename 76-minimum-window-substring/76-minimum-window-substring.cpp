class Solution {
public:
    string minWindow(string s, string t) {
        if (t.length() > s.length()) return "";
        if (t == s) return s;
        map<char, int> mp;
        map<char, int> mp1;  for(auto it:t) mp1[it]++;
        for(int i=0;i<t.length();i++) {
            mp[s[i]]++;
        }
        // mp: freq of chars in window
        // mp1: freq of chars of T
        pair<int, int> p = {-1, -1};
        int i = 0, j = t.length()-1;
        while(j < s.length()) {
            // cout<<"hi\n";
            bool sufficient = true;
            for(auto it:mp1) {
                if (mp.find(it.first) == mp.end()) {
                    sufficient = false;
                    break;
                } else {
                    if (mp[it.first] < mp1[it.first]) {
                        sufficient = false;
                        break;                            
                    }
                }
            }
            if (sufficient) {
                if (p.first == -1 || p.second == -1) p.first = i, p.second = j;
                else if (p.second - p.first >= j - i) {
                    p.first = i; p.second = j;
                }
                mp[s[i]]--;
                i++;
            } else {
                if (j + 1 < s.length()) mp[s[j+1]]++;
                j++;
            }
        }
        if (p.first == -1 || p.second == -1) return "";
        string temp = "";
        for(int i=p.first;i<=p.second;i++) temp += s[i];
        return temp;
    }
};