#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
vector<vector<pair<ll,ll>>> v,bin;
ll n,k;
void dfs(pair<ll,ll> pr,int po)
 {
     ll x,w;
     x=pr.first;
     w=pr.second;
     bin[x][0].first=po;
     bin[x][0].second=w;
     for(int i=1;i<k;i++)
       {
           bin[x][i].first=bin[bin[x][i-1].first][i-1].first;
           bin[x][i].second=min<ll>(bin[x][i-1].second,bin[bin[x][i-1].first][i-1].second);
       }
     for(auto i:v[pr.first])
       if(i.first!=po)
          dfs(i,x);
 }
int query(int i,int j)
 {
     ll x=i,ans=3e10;
     for(int bit=k-1;bit>=0;bit--)
       {
            if((j&(1LL<<bit)))
              {
                 ans=min<ll>(ans,bin[x][bit].second);
                 x=bin[x][bit].first;
              }
       }
    return ans;
 }
int main()
 {
     ll x,y,z=0;
     cin>>n;
     v=vector<vector<pair<ll,ll>>>(n);
     k=log2(n)+1;
     bin=vector<vector<pair<ll,ll>>>(n,vector<pair<ll,ll>>(k));
     for(int i=0;i<n-1;i++)
       {
           cin>>x>>y>>z;
           x--,y--;
           v[x].push_back({y,z});
           v[y].push_back({x,z});
       }
    pair<ll,ll> pr={0,2e10};
    dfs(pr,0);
    cin>>z;
    while(z--)
      {
         cin>>x>>y;
          cout<<query(x-1,y)<<"\n";
      }
 }