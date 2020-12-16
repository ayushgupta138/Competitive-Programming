#include<bits/stdc++.h>
using namespace std;
int n;
vector<int> perm;
vector<bool> vis(n+1);
void search()
{
    if(perm.size()==n)
      for(int i=0;i<=n;i++)
        if(i==n)
          cout<<endl;
        else  
          cout<<perm[i]<<" ";
    else
        {
            for(int i=1;i<=n;i++)
               {
                   if(vis[i])
                     continue;
                   else 
                     {
                         perm.push_back(i);
                         vis[i]=1;
                         search();
                         perm.pop_back();
                         vis[i]=false;
                     } 
               }
        }
 }
int main()
{
        cin>>n;
        search();
}