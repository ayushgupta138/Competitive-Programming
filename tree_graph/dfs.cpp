#include<bits/stdc++.h>
using namespace std;
#define rep(i,s,t) for(i=s;i<t;i++)
vector<vector<int>> v;
int timer=0,i,cycles=0;
void dfs(int f,int vis[],int time_in[],int time_out[])
{
     cout<<f<<" ";
     vis[f-1]=1;
     time_in[f-1]=timer++;
     for(int k=0;k<v[f-1].size();k++)
         if(vis[v[f-1][k]-1] && !time_out[v[f-1][k]-1])
            cycles++;
     for(int k=0;k<v[f-1].size();k++)
       if(!vis[v[f-1][k]-1])
         dfs(v[f-1][k],vis,time_in,time_out);
     time_out[f-1]=timer++;    
}
int main()
{
    int n,k,m,t,j;
    cout<<"Enter the number of vertices and edges\n";
    cin>>n>>k;
     int vis[n]={},time_in[n]={},time_out[n]={};
     rep(i,0,n)
       {
           vector<int> v1;
           v.push_back(v1);
       }
     cout<<"Enter the edges:\n";
     rep(i,0,k)
     {
         cin>>t>>m;
         v[t-1].push_back(m);
         v[m-1].push_back(t);
     }
    rep(i,0,n)
      {
          cout<<i+1<<"-> ";
          rep(j,0,v[i].size())
            cout<<v[i][j]<<" ";
          cout<<endl;  
      }
cout<<"DFS\n";

dfs(1,vis,time_in,time_out);
cout<<endl;
rep(i,0,n)
  cout<<time_in[i]<<" ";
cout<<endl;
rep(i,0,n)
  cout<<time_out[i]<<" ";
cycles-=n-1;
cout<<endl<<"Number of cycles are: "<<cycles<<endl;   
}