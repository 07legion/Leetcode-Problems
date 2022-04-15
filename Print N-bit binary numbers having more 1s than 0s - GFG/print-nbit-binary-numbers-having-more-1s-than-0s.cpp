// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
private:
    int n;
    vector<string> v;
public:	
    void func(int ones, int zeros, int i, string temp) {
        if (i == n) {
            v.push_back(temp);
            return;
        }
        func(ones + 1, zeros, i+1, temp + "1");
        if (ones > zeros) 
            func(ones, zeros+1, i+1, temp + "0");
    }
	vector<string> NBitBinary(int N) {
	    n = N;
        func(0, 0, 0, "");
        return v;
	}
};

// { Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		int n;
   		cin >> n;
        Solution ob;
   		vector<string> ans = ob.NBitBinary(n);

   		for(auto i:ans)
   			cout << i << " ";

   		cout << "\n";
   	}

    return 0;
}  // } Driver Code Ends