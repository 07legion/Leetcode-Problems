class Solution {
public:
    int compress(vector<char>& v) {
        int low = 0, n = v.size();
        for(int i=0;i<n;i++) {
            int j = i, freq = 1;
            char ch = v[i];
            while(j + 1 < n && v[j] == v[j+1]) {
                freq++; j++;
            }
            if (freq == 1) {
                v[low++] = ch;
            } else {
                v[low++] = ch;
                string str = to_string(freq);
                for(int k=0;k<str.length();k++)
                    v[low++] = str[k];
            }
            i = j;
        }
        return low;
    }
};