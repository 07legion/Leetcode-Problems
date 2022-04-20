class Solution {
private:
    int n;
    vector<string> words; vector<int> score;
    int mx;
public:
    void func(int i, vector<int> freq, int setScore) {        
        if (i == words.size()) {
            mx = max(mx, setScore);
            return;
        }
        bool canChoose = true;
        int s = 0;
        vector<int> temp = freq;
        for(char ch : words[i]) {
            if (freq[ch-'a'] - 1 >= 0) {
                freq[ch-'a']--;
                s += score[ch-'a'];
            }
            else {
                canChoose = false; 
                break;
            }
        }
        if (canChoose) {
            func(i+1, freq, setScore + s);
        }
        func(i+1, temp, setScore);        
    }
    int maxScoreWords(vector<string>& Words, vector<char>& letters, vector<int>& Score) {
        words = Words; score = Score;
        mx = INT_MIN;
        n = words.size();
        vector<int> freq(26, 0);
        for(char ch : letters) freq[ch-'a']++;
        func(0, freq, 0);
        return mx;
    }
};