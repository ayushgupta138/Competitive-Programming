#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> v;
vector<int> a,b;
int color()
 {
     int n=v.size();
     vector<int> col(n);
     col[0]=1;
     int h=0;
     for(int i=0;i<n;i++)
       {
           for(int t:v[i])
              if(col[t]==0)
               col[t]=3-col[i];
              else if(col[t]==col[i])
                 {
                     h=1;
                     break;
                 } 
            if(h)
               break;
       }
 
 if(h)
   return 0;
 for(int i=0;i<n;i++)
    if(col[i]==1)
      a.push_back(i);
     else 
        b.push_back(i);
  return 1;       
 }
int main()
{
     int n,e,c,d;
     cout<<"Enter the number of vertices and edges:\n";
     cin>>n>>e;
     v=vector<vector<int>>(n);
     for(int i=0;i<e;i++)
       {
           cin>>c>>d;
           c--,d--;
           v[c].push_back(d);
           v[d].push_back(c);
       }
    int h=color();
    if(h)
     {
         cout<<"Graph is Bipartite:\nPartitions are:\n";
         for(auto t=a.begin();t!=a.end();t++)
            cout<<*t+1<<" ";
        cout<<endl;
        for(auto t=b.begin();t!=b.end();t++)
           cout<<*t+1<<" ";
        cout<<endl;      
      }
     else
        cout<<"Graph is not bipartite\n";
  } 