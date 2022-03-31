// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
private:
vector<string> v;
public:
    void func(int i, int n, string temp, string str) {
        if (i == n) {
            if (temp != "")
                v.push_back(temp);
            return;
        };
        temp.push_back(str[i]);
        func(i+1, n, temp, str);
        temp.pop_back();
        func(i+1, n, temp, str);
    }
	vector<string> AllPossibleStrings(string str){
	    func(0, str.length(), "", str);
	    sort(v.begin(), v.end());
	    return v;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		Solution ob;
		vector<string> res = ob.AllPossibleStrings(s);
		for(auto i : res)
			cout << i <<" ";
		cout << "\n";

	}
	return 0;
}  // } Driver Code Ends