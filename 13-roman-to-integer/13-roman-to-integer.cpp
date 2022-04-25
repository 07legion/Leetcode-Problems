class Solution {
private:
    unordered_map<string, int> mp;
public:
    void prepare() {
        mp["I"] = 1;
        mp["V"] = 5;
        mp["X"] = 10;
        mp["L"] = 50;
        mp["C"] = 100;
        mp["D"] = 500;
        mp["M"] = 1000;
        mp["IV"] = 4; mp["IX"] = 9;
        mp["XL"] = 40; mp["XC"] = 90;
        mp["CD"] = 400; mp["CM"] = 900;
        return;
    }
    int romanToInt(string s) {
        int ans = 0;
        prepare();
        for(int i=0;i<s.length();i++) {
            string temp = ""; temp += s[i];
            if (mp.find(temp) != mp.end()) {
                if (i + 1 < s.length() && mp.find(temp + s[i+1]) != mp.end()) {
                    ans += mp[temp + s[i+1]]; 
                    i++;
                } else {
                    ans += mp[temp];
                }
            }
        }
        return ans;
    }
};