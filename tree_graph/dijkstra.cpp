#include<bits/stdc++.h>
using namespace std;
vector<vector<pair<int,int>>> v;
void dijstra(int s,vector<int> &d,vector<int> &p)
{
    int n=v.size(),t,e,l;
    vector<bool> used(n,false);
    d.assign(n,INT_MAX);
    p.assign(n,-1);
    d[s]=0;
    for(int i=0;i<n;i++)
     {
          t=-1;
             for(int j=0;j<n;j++)
               if(!used[j] &&(t==-1 || d[j]<d[t]))
                 t=j;
           if(d[t]==INT_MAX)
             break;
           used[t]=true;
           for(auto k : v[t])
           {
               e=k.first-1;
               l=k.second;
               if(d[e]>d[t]+l)
                  {
                      d[e]=d[t]+l;
                      p[e]=t;
                  }
           }         
     }
}
vector<int> pathres(int a,int b,vector<int> p)
 {
     vector<int> path;
     if(p[b]==-1)
       return path;
     for(int i=b;i!=-1;i=p[i])
       path.push_back(i+1);
    reverse(path.begin(),path.end());
    return path;
 }
int main()
{
    int n,e;
    cout<<"Enter the number of vertices and edges:\n";
    cin>>n>>e;
    int a,b,c;
    for(int i=0;i<n;i++)
      {
          vector<pair<int,int>> v1;
          v.push_back(v1);
      }
    cout<<"Enter the edges and corresponding weights:\n";
    for(int i=0;i<e;i++)
      {
          cin>>a>>b>>c;
          v[a-1].push_back({b,c});
          v[b-1].push_back({a,c});
      }
    vector<int> dist(n),p(n),ans;
    cout<<"Enter the vertex from which you want the shortest path:\n";
    cin>>a;
    dijstra(a-1,dist,p);
    for(int i=0;i<n;i++)
      cout<<dist[i]<<" ";
    cout<<endl;
    cout<<"Enter the vertex to which you want the path:\n";
    cin>>b;  
    ans=pathres(a-1,b-1,p);
    if(!ans.size())
      cout<<"No path exists\n";
    else 
      cout<<"Path is:\n"; 
    for(auto t=ans.begin();t!=ans.end();t++)
      cout<<*t<<" ";
    cout<<endl;  
}