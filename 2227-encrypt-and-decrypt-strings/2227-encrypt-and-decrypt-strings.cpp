class Encrypter {
private:
    int ans;
    unordered_map<char, string> mp;
    unordered_map<string, int> mp1;
public:
    Encrypter(vector<char>& keys, vector<string>& values, vector<string>& dictionary) {
        ans = 0;
        mp.clear(); mp1.clear();
        for(int i=0;i<keys.size();i++) {
            mp[keys[i]] = values[i];
        }
        for(string &it : dictionary) {
            mp1[encrypt(it)]++;
        }
    }
    
    string encrypt(string word1) {
        string ans = "";
        for(char ch:word1) {
            if (!mp.count(ch)) return "";
            ans += mp[ch];
        }
        return ans;
    }
    int decrypt(string str) {
        return mp1[str];
    }
};

/**
 * Your Encrypter object will be instantiated and called as such:
 * Encrypter* obj = new Encrypter(keys, values, dictionary);
 * string param_1 = obj->encrypt(word1);
 * int param_2 = obj->decrypt(word2);
 */