#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
vector<vi> v,bin_lif;
ll n,k;
void dfs(int x,int po)
  {
      for(int i:v[x])
        if(i!=po)
          {
              bin_lif[i][0]=x;
              dfs(i,x);
          }
  }
void build()
  {
      ll p,q;
      for(int i=1;i<k;i++)
       {
           for(int j=0;j<n;j++)
              {
                 
                 p=bin_lif[j][i-1];
                 if(p==-1)
                   bin_lif[j][i]=-1;
                 else 
                   {
                       q=bin_lif[p][i-1];
                       bin_lif[j][i]=q;
                   } 
              }
       }
  }
int query(int i,int j)
 {
    ll x=1,y=j;
    vi an; 
    ll po=0;
    while(x<=y)
      {
          if((x&y))
            an.push_back(po);
          x*=2;  
          po++;
      }
    y=i;
    for(int i=0;i<an.size();i++)
      {
          if(an[i]>=k) 
            {
                y=-1;
                break;
            }
         y=bin_lif[y][an[i]];
         if(y==-1)
           break;
      }
   return y;
 }
int main()
 {
       cin>>n;
       ll x,y,p;
       v=vector<vi>(n);
       for(int i=0;i<n-1;i++)
         {
             cin>>x>>y;
             x--,y--;
             v[x].push_back(y);
             v[y].push_back(x);
         }
       k=log2(n)+1;
       bin_lif=vector<vi>(n,vi(k,-1));
       bin_lif[0][0]=-1;
       dfs(0,-1);
       build();
       cin>>x;
       while(x--)
         {
             cin>>y>>p;
             cout<<query(y-1,p)+1<<"\n";
         }
 }