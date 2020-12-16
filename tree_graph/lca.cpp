#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
ll n,k;
vector<vi> v,bin; 
vi tin,tout;
ll timer=0;
void dfs(int x,int po)
  {
     tin[x]=timer++;
     bin[x][0]=po;
     for(int i=1;i<k;i++)
       bin[x][i]=bin[bin[x][i-1]][i-1];
     for(int i:v[x])
       if(i!=po)
         dfs(i,x);
     tout[x]=timer++;      
  }
bool is_ancestor(int x,int y)
  {
      if(tin[x]<=tin[y] && tout[x]>=tin[y])
        return true;
      else 
        return false; 
  }  
int lca(int x,int y)
  {
      if(is_ancestor(x,y))
        return x;
      if(is_ancestor(y,x)) 
        return y; 
      for(int i=k-1;i>=0;i--)
        if(!is_ancestor(bin[x][i],y))
          x=bin[x][i];
      return bin[x][0];    
  }  
int main()
 {
     ll x,y;
     cin>>n;
     v=vector<vi>(n);
     for(int i=0;i<n-1;i++)
       {
           cin>>x>>y;
           x--,y--;
           v[x].push_back(y);
           v[y].push_back(x);
       }
    k=log2(n)+1;
    bin=vector<vi>(n,vi(k));
    tin=vi(n);
    tout=vi(n);
    dfs(0,0);
    ll q;
    cin>>q;
    while(q--)
      {
          cin>>x>>y;
          cout<<lca(x-1,y-1)+1<<"\n";
      }
 }