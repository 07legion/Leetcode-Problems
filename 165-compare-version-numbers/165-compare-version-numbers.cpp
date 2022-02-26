class Solution {
public:
    int compareVersion(string str1, string str2) {
        while(str1.length() < str2.length()) {
            str1 += ".0";
        }
        while(str1.length() > str2.length()) {
            str2 += ".0";
        }
        str1 += '.';
        str2 += '.';
        int n = str1.length();
        int i = 0, j = 0;
        string temp1 = "", temp2 = "";
        while(i < str1.length() && j < str2.length()) {
            if (str1[i] == '.' || str2[j] == '.') {
                if (str1[i] == '.' && str2[j] == '.') {
                    int a = stoi(temp1), b = stoi(temp2);
                    if (a > b) return 1;
                    if (a < b) return -1;
                    temp1 = "";
                    temp2 = "";
                    i++;j++;
                } else if (str1[i] == '.') {
                    temp2 += str2[j++];
                } else {
                    temp1 += str1[i++];
                }
            } else {
                temp1 += str1[i++]; 
                temp2 += str2[j++];
            }
        }
        return 0;
    }
};