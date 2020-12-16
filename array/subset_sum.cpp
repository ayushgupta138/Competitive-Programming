#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
vi subset_sum(vi &a,ll x)
  {
      ll sum=0;
      for(ll i:a)
        sum+=i;
      vi an;
      if(x>sum)
        {
           an.push_back(-1);
           return an;
        }  
     else
       {
           ll n=a.size();
           int dp[n][x+1]={};
           for(int i=0;i<n;i++)
            dp[i][0]=1;
           if(a[0]<=x)
             dp[0][a[0]]=1;
           int check[n][x+1];
           memset(check,-1,sizeof(check));
           for(int i=1;i<n;i++)
              {
                  for(int j=0;j<=x;j++)
                     {
                      if(j>=a[i] && dp[i-1][j-a[i]])
                       {
                           dp[i][j]=1;
                           check[i][j]=j-a[i];
                       }
                     dp[i][j]|=dp[i-1][j];
                     if(check[i][j]==-1 && dp[i][j])
                       check[i][j]=j;
                     }
              }  
          if(dp[n-1][x])
            {
                ll k=x;
                for(int i=n-1;check[i][k]!=-1;i--)
                  if(check[i][k]!=k)
                    {
                        an.push_back(i);
                        k=check[i][k];
                    }
            }
         else
            an.push_back(-1);
         return an;
        }
  }
int main()
 {
     ll n,x;
     cin>>n;
     vi a(n);
     for(int i=0;i<n;i++)
       cin>>a[i];
     cin>>x; 
     vi an=subset_sum(a,x);
     if(an[0]==-1)
       cout<<"Sum is not possible\n";
     else 
       {
           cout<<"Sum is possible, index is \n";
           for(int i:an)
             cout<<i<<" ";
           cout<<"\nsum is:\n";
           for(int i:an)
             cout<<a[i]<<" + ";
           cout<<"\n";     
       }  
 }  