#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s,t,ans;
    cin>>s>>t;
    int n=s.length(),m=t.length();
    int dp[n][m]={};
    for(int i=0;i<n;i++)
      {
          for(int j=0;j<m;j++)
             {
                   if(s[i]==t[j])
                     {
                     if(!i || !j)
                        dp[i][j]++;
                     else    
                     dp[i][j]=dp[i-1][j-1]+1;
                     
                     }
                   else 
                     dp[i][j]=max(dp[max(0,i-1)][j],dp[i][max(0,j-1)]); 
             }
      }    
    cout<<dp[n-1][m-1]<<"\n";
}