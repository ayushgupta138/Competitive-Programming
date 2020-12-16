#include<bits/stdc++.h>
using namespace std;
int main()
{
  int n;
  cin>>n;
  vector<int> v(n);
  for(int i=0;i<n;i++)
    cin>>v[i];
  vector<int> ans(n,1);
  vector<int> rec(n,-1);
  int an=INT_MIN,x=-1;
  for(int i=0;i<n;i++)
    {
        for(int j=i-1;j>=0;j--)
          if(v[j]<v[i])
            {
            if(ans[i]<ans[j]+1)
              {
                  ans[i]=ans[j]+1;
                  rec[i]=j;
              }
            }
        if(ans[i]>an)
          {
              an=ans[i];
              x=i;
          }
    }  
  cout<<an<<"\n";
  vector<int> p;
  for(int i=x;i!=-1;i=rec[i])
    p.push_back(i);
  reverse(p.begin(),p.end());
  for(int c: p)
    cout<<v[c]<<" ";
 cout<<"\n";     
}