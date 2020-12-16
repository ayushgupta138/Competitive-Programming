#include<bits/stdc++.h>
using namespace std;
vector<vector<pair<int,int>>> v;
void dijstra(int s,vector<int> &d,vector<int> &pt)
{
    int n=v.size(),p,wt,u,len;
    d[s]=0;
    pair<int,int> pr;
    set<pair<int,int>> check;
    check.insert({0,s});
    while(!check.empty())
    {
         pr=*(check.begin());
        check.erase(check.begin());
        u=pr.second;
        len=pr.first;
        if(len==INT_MAX)
          break;
        d[u]=len;
        for(int i=0;i<v[u].size();i++)
         {
             p=v[u][i].first;
             wt=v[u][i].second;
             if(d[p]>d[u]+wt)
             {
                pt[p]=u;
                if(check.find({d[p],p})!=check.end())
                   check.erase(check.find({d[p],p}));
                d[p]=d[u]+wt;
                check.insert({d[p],p});
             }
         }
    }

}
int main()
{
    int n,e,a,b,c,g;
    cin>>n>>e;
    vector<pair<int,int>> v1;
    for(int i=0;i<n;i++)
      v.push_back(v1);
    for(int i=0;i<e;i++)
     {
         cin>>a>>b>>c;
         v[a-1].push_back({b-1,c});
         v[b-1].push_back({a-1,c});
     }
    vector<int> d(n,INT_MAX),p(n,-1);
    cin>>g;
    dijstra(g-1,d,p);
    for(int i=0;i<n;i++)
      cout<<d[i]<<" ";
      cout<<"\n";
}