// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
  public:
    // arr[] : the input array
    // N : size of the array arr[]
    
    //Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int v[], int n) {
        map<int, int> mp;
        int mx = INT_MIN;
        for(int i=0;i<n;i++) mp[v[i]] = i+1;
        for(int i=0;i<n;i++) {
            if (mp.find(v[i]-1) == mp.end()) {
                int j = v[i], a = 0;
                while(mp.find(j) != mp.end()) a++, j++;
                mx = max(mx, a);
            }
        }
        return mx;
    }
};

// { Driver Code Starts.
 
// Driver program
int main()
{
 int  t,n,i,a[100001];
 cin>>t;
 while(t--)
 {
  cin>>n;
  for(i=0;i<n;i++)
  cin>>a[i];
  Solution obj;
  cout<<obj.findLongestConseqSubseq(a, n)<<endl;
 }
      
    return 0;
}  // } Driver Code Ends