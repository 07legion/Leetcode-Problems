// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
vector<string> AllParenthesis(int n) ;


 // } Driver Code Ends
//User function Template for C++

// N is the number of pairs of parentheses
// Return list of all combinations of balanced parantheses
class Solution {
private:
    vector<string> v;
public:
    void func(int open, int close, string temp) {
        if (!open && !close) {
            v.push_back(temp);
            return;
        }
        if (open > 0) {
            temp += "(";
            func(open-1, close, temp);
            temp.pop_back();
        }
        if (close > open) {
            temp += ")";
            func(open, close-1, temp);
            temp.pop_back();
        }
    }
    vector<string> AllParenthesis(int n) {
        func(n, n, "");
        return v;
    }
};

// { Driver Code Starts.


int main() 
{ 
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		Solution ob;
		vector<string> result = ob.AllParenthesis(n); 
		sort(result.begin(),result.end());
		for (int i = 0; i < result.size(); ++i)
			cout<<result[i]<<"\n";
	}
	return 0; 
} 
  // } Driver Code Ends