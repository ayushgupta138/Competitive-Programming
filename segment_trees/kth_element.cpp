#include<bits/stdc++.h>
using namespace std;
vector<int> seg,a;
void build(int l,int r,int v,int x)
  {
      if(l==r)
        {
            seg[v]=(a[l]==x)?1:0;
            return;
        }
     int mid=(l+r)/2;
     build(l,mid,2*v+1,x);
     build(mid+1,r,2*v+2,x);
     seg[v]=seg[2*v+1]+seg[2*v+2];
  }
int query(int l,int r,int k,int v)
  {
      if(k>seg[v])
        return -1;
      if(l==r)
        return l;
      int mid=(l+r)/2;
      if(seg[2*v+1]>=k)
        return query(l,mid,k,2*v+1);
      else 
         return query(mid+1,r,k-seg[2*v+1],2*v+2);
           
  }
int main()
{
   int n;
   cin>>n;
   a=vector<int>(n);
   seg=vector<int>(4*n);
   for(int i=0;i<n;i++)
     cin>>a[i];
    build(0,n-1,0,0);  
  int l;
  cin>>l;
  cout<<query(0,n-1,l,0)<<"\n";
}
