class Solution {
public:
    int ladderLength(string str1, string str2, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(), wordList.end());
        queue<string> q;
        q.push(str1);
        int a = 1;
        while(!q.empty()) {
            int n = q.size();
            for(int j=0;j<n;j++) {
                string temp = q.front();
                q.pop();
                if (temp == str2) return a;
                st.erase(temp);
                for(int i=0;i<temp.length();i++) {
                    char c = temp[i];
                    for(char ch='a';ch<='z';ch++) {
                        temp[i] = ch;
                        if (st.find(temp) != st.end()) {
                            q.push(temp);
                        }
                        temp[i] = c;
                    }
                }
            }
            a++;            
        }
        return 0;
    }
};