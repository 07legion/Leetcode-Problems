// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
unordered_map<string,int> mp;
int mod = 1003;

int solve(string s, int i, int j, bool isTrue)
{
   //BC
   if(i>j)
       return 0;
   if(i==j)
   {
       if(isTrue == true)
           return s[i]=='T';
       else
           return s[i] =='F';
   }
   
   string temp = to_string(i);
   temp.push_back(' ');
   temp.append(to_string(j));
   temp.push_back(' ');
   temp.append(to_string(isTrue));
   
   
   if(mp.find(temp) != mp.end())
       return mp[temp];
   
   int ans=0;
   for(int k=i+1; k<=j-1; k=k+2)
   {
      int lT=solve(s,i,k-1,true);
      int lF=solve(s,i,k-1,false);
      int rT=solve(s,k+1,j,true);
      int rF=solve(s,k+1,j,false);
      
      if(s[k] == '&')
      {
          if(isTrue == true)
              ans= ans+ (lT*rT);
          
          else
              ans=ans + (lF*rF) + (lF*rT) + (lT*rF);
          
      }
      
      else if(s[k] == '|')
      {
          if(isTrue == true)
              ans=ans+ (lT*rT) + (lF*rT) + (lT*rF);
         
          else
              ans=ans + (lF*rF);
          
      }
      
      else if(s[k]=='^')
      {
           if(isTrue == true)
              ans=ans +(lF*rT) + (lT*rF);
         
          else
              ans=ans+ (lF*rF)+ (lT*rT);
          
      }
   }
      return mp[temp] = ans %mod;
   
}
   int countWays(int N, string S){
       // code here
       mp.clear();
       
       return solve(S,0,N-1,true)%mod;
   }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        string S;
        cin>>S;
        
        Solution ob;
        cout<<ob.countWays(N, S)<<"\n";
    }
    return 0;
}  // } Driver Code Ends