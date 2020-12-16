#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> v;
vector<int> p;
pair<int,int> dfs(int s,int dist=0,int x=-1)
{
      pair<int,int> pr=make_pair(dist,s);
      p[s]=x;
      for(auto t : v[s])
        if(t!=x)
          pr=max(pr,dfs(t,dist+1,s));
      return pr;    
}
int main()
{
    int n,a,b;
    cin>>n;
    v=vector<vector<int>>(n);
    p=vector<int>(n);
    for(int i=0;i<n-1;i++)
      {
           cin>>a>>b;
           a--,b--;
           v[a].push_back(b);
           v[b].push_back(a);
      }
   pair<int,int> dia,gr;
   dia=dfs(0);
   gr=dfs(dia.second);
   int v=gr.second;
   vector<int> diam;
   while(v!=dia.second)
     {
          diam.push_back(v);
          v=p[v];
     }
  diam.push_back(dia.second);
  cout<<"Diameter is : "<<diam.size()-1<<endl;
  for(auto t=diam.rbegin();t!=diam.rend();t++)
      cout<<*t+1<<" ";
  cout<<endl;    
}