#include<bits/stdc++.h>
using namespace std;
vector<int> a,seg;
void build(int l,int r,int v)
  {
      if(l==r)
        seg[v]=a[l];
      else 
        {
            int mid=(l+r)/2;
            build(l,mid,2*v+1);
            build(mid+1,r,2*v+2);
            seg[v]=seg[2*v+1]+seg[2*v+2];
        } 
  }
int pre_sum(int l,int r,int v,int x,int k)
  {
      if(l>k || seg[v]<x)
        return -1; 
      int mid=(l+r)/2;
      if(l==r)
        return l;
      if(seg[2*v+1]>=x)
        return pre_sum(l,mid,2*v+1,x,k);
      else
         return pre_sum(mid+1,r,2*v+2,x-seg[2*v+1],k);
  }
int main()
{
    int n;
    cin>>n;
    a=vector<int>(n);
    seg=vector<int>(4*n);
    for(int i=0;i<n;i++)
      cin>>a[i];
    build(0,n-1,0);
    int x,l,r;
    cin>>r>>x;
    cout<<pre_sum(0,n-1,0,x,r)<<"\n";
}