#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
vector<vi> v;
vi tin,vis,low;
ll timer=0;
vector<pair<ll,ll>> brid;
void dfs_brid(int x,int p)
  {
      vis[x]=1;
      tin[x]=low[x]=timer++;
      for(int i:v[x])
        if(i!=p)
          {
              if(vis[i])
                low[x]=min<ll>(low[x],tin[i]);
              else 
                {
                    dfs_brid(i,x);
                    low[x]=min<ll>(low[x],low[i]);
                    if(low[i]>tin[x])
                      brid.push_back({i+1,x+1}); 
                } 
          }     
  }
int main()
{
    ll n,m;
    cin>>n>>m;
    v=vector<vi>(n);
    tin=vi(n);
    vis=vi(n);
    low=vi(n);
    ll x,y;
    for(int i=0;i<m;i++)
      {
           cin>>x>>y;
           x--,y--;
           v[x].push_back(y);
           v[y].push_back(x);
      }
   dfs_brid(0,-1);
   for(int i=0;i<n;i++)
     cout<<tin[i]<<" ";
   cout<<"\n";
   for(int i=0;i<n;i++)
     cout<<low[i]<<" ";
   cout<<"\n";    
   if(brid.size()==0)
     cout<<"The graph has no bridge\n";
   else 
     {
         cout<<"Bridges are:\n";
         for(int i=0;i<brid.size();i++)
           cout<<brid[i].first<<" "<<brid[i].second<<"\n";
     } 
}  