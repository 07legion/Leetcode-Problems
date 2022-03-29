// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

 // } Driver Code Ends


class Solution {
public:
    bool search(vector<vector<int> > v, int n, int m, int target)  {
        int i = 0, j = m - 1;
        while(i < n && j >= 0) {
            if (v[i][j] > target) {
                j--;
            } else if (v[i][j] < target) {
                i++;
            } else return true;
        }
        return false;
    }
};

// { Driver Code Starts.
int main() 
{ 
	int t;
    cin>>t;
    while(t--)
    {

 		int n, m;
    	cin>> n>> m;
        vector<vector<int> > matrix(n);
            
        for(int i=0; i<n; i++)
        {
            matrix[i].assign(m, 0);
            for( int j=0; j<m; j++)
            {
                cin>>matrix[i][j];
            }
        }
        
        int x;
        cin>>x;
        Solution obj;
        if (obj.search(matrix,n,m,x)) 
            cout << "1\n"; 
        else
            cout << "0\n"; 
    }
	return 0; 
} 

  // } Driver Code Ends