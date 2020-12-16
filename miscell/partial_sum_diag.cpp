#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> a;
vector<int> b,c;
int n,m,l,x,y,k;
void prin(vector<int> &a)
  {
      for(int i=0;i<a.size();i++)
        cout<<a[i]<<" ";
      cout<<"\n";  
  }
int main()
{
    cin>>n>>m;
    a=vector<vector<int>>(n,vector<int>(m));
    b=vector<int>(n+m-1);
    c=vector<int>(n+m-1);
    for(int i=0;i<n;i++)
      for(int j=0;j<m;j++)
        {
         cin>>a[i][j];
         b[i+j]+=a[i][j];
         c[i+m-1-j]+=a[i][j];
        }
    prin(b);
    prin(c);
}