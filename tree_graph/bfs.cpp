#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> v;
vector<int> p,d,vis,bf;
void bfs(int x)
{
   int c;  
   vis[x]=1;
   d[x]=0;
   p[x]=-1;
   queue<int> q;
   q.push(x);
   bf.push_back(x);
   while(!q.empty())
   {
       c=q.front();
       q.pop();
       for(int i : v[c])
             if(!vis[i])
               { 
                vis[i]=1;
                q.push(i);
                bf.push_back(i);
                p[i]=c;
                d[i]=d[c]+1;
               }
   }
}
int main()
{
    int n,e,g,h;
    cout<<"Enter the number of vertices and edges:\n";
    cin>>n>>e;
    v=vector<vector<int>>(n);
    p=vector<int>(n,-1);
    d=vector<int>(n);
    vis=vector<int>(n);
    cout<<"Enter the edges:\n";
    for(int i=0;i<e;i++)
      {
          cin>>g>>h;
          g--,h--;
          v[g].push_back(h);
          v[h].push_back(g);
      }
    cout<<"Enter the starting vertex:\n";
    cin>>g;
    g--;
    bfs(g);
    cout<<"BFS\n";
     for(auto t=bf.begin();t!=bf.end();t++)
       cout<<*t+1<<" ";
    cout<<endl;
}