#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
vector<vi> v;
vi vis,po;
bool dfs_cy(ll &st,ll &en,int x)
  {
     vis[x]=1;
     for(int i:v[x])
      if(i!=po[x])
        {
            if(vis[i]==0)
              {
                  po[i]=x;
                  if(dfs_cy(st,en,i))
                    return true;
              }
           else if(vis[i]==1)
             {
                 st=i;
                 en=x;
                 return true;
             }
        }
   vis[x]=2;
   return false;
  }
vi cycle_detection(int x)
  {      
      ll st,en;
      ll n=v.size();
      vis=vi(n);
      po=vi(n,-1);
      vi an;
      if(dfs_cy(st,en,x))
         {
               ll k=en;
               while(k!=st)
                 {
                     an.push_back(k);
                     k=po[k];
                 }
              an.push_back(st);
              reverse(an.begin(),an.end());
         }
     else
      an.push_back(-1);
     return an; 
  }
void inser(int k,ll x,ll y)
  {
      if(k)
        {
            v[x].push_back(y);
            v[y].push_back(x);
        }
     else
        v[x].push_back(y);
    }
int main()
 {
     ll n,m,x,y,k;
     cin>>n>>m>>k;
     v=vector<vi>(n);
     for(int i=0;i<m;i++)
       {
            cin>>x>>y;
            x--,y--;
            inser(k,x,y);
       }
    vi an=cycle_detection(0);
    if(an[0]==-1)
      cout<<"Graph is acyclic:\n";
    else 
      {
          cout<<"Cycle is:\n";
          for(int i:an)
            cout<<i+1<<" ";
          cout<<"\n";  
      } 
 }  