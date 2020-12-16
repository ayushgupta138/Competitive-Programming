#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
vector<vi> v;
vi f,g;
void getans(int x,int po=-1)
 {
     if(v[x].size()==1)
       {
           f[x]=1;
           g[x]=0;
       } 
     else
       {
           for(int i:v[x])
             {
                 if(i!=po)
                   {
                       getans(i,x);
                       f[x]*=(1+f[i]);
                       g[x]+=g[i]+f[i];
                   }
             }
       }
  }
int main()
{
    ll n,x,y;
    cin>>n;
    v=vector<vi>(n);
    f=vi(n,1);
    g=vi(n);
    for(int i=0;i<n-1;i++)
      {
           cin>>x>>y;
           x--,y--;
           v[x].push_back(y);
           v[y].push_back(x);
      }
    getans(0);
    cout<<f[0]+g[0]<<"\n";
}