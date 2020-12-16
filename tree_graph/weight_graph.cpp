#include<bits/stdc++.h>
using namespace std;
vector<vector<pair<int,int>>> v;
void dijstra(int n,int dist[],int vis[])
{
  vis[n-1]=1;
  for(int k=0;k<v[n-1].size();k++)
    {
        dist[v[n-1][k].first-1]=min(dist[v[n-1][k].first-1],dist[n-1]+v[n-1][k].second);
        if(!vis[v[n-1][k].first-1])
          dijstra(v[n-1][k].first,dist,vis);
    }
}
int main()
{
   int n,e,g,h,j;
   cout<<"Enter the number of vertices and edges:\n";
   cin>>n>>e;
   for(int i=0;i<n;i++)
     {
         vector<pair<int,int>> v1;
         v.push_back(v1);
     }
  cout<<"Enter the edges and the weights:\n";
  for(int i=0;i<e;i++)
   {
       cin>>g>>h>>j;
       v[g-1].push_back({h,j});
       v[h-1].push_back(make_pair(g,j));
   }
 for(int i=0;i<n;i++)
   {
       cout<<i+1<<" -> ";
       for(int k=0;k<v[i].size();k++)
         cout<<v[i][k].first<<" - "<<v[i][k].second<<" ";
      cout<<endl;   
   }
int dist[n],vis[n]={};
fill_n(dist,n,INT_MAX);
cout<<"Enter the vertex from which you want the shortest path:\n";
cin>>g;
dist[0]=0;
dijstra(g,dist,vis);
cout<<"Distance is:\n";
for(int i=0;i<n;i++)
  cout<<dist[i]<<" ";
cout<<endl;  
}