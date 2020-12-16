#include<iostream>
using namespace std;
int main()
{
    string s;
    cin>>s;
    int n=s.length(),i,j;
    int dp[n][n]={};
    for(int i=0;i<n;i++)
      dp[i][i]=1;
    for(int i=0;i<n-1;i++)
      if(s[i]==s[i+1])
        dp[i][i+1]=1;  
    for(int k=2;k<n;k++)
     {
         i=0;
         j=k;
         while(i<n && j<n)
          {
              if(dp[i+1][j-1]==1 && s[i]==s[j])
                dp[i][j]=1;
              i++;
              j++;
          }
     }
for(i=0;i<n;i++)
{
    for(j=0;j<n;j++)
      cout<<dp[i][j]<<" ";
    cout<<endl;  
}
}