#include<bits/stdc++.h>
using namespace std;
vector<int> a,seg;
void build(int l,int r,int k)
  { 
      if(l==r)
        {
            seg[k]=a[l];
            return;
        }   
      int mid=(l+r)/2;
      build(l,mid,2*k+1);
      build(mid+1,r,2*k+2);
      seg[k]=seg[2*k+1]+seg[2*k+2];
  }
int sum(int v,int l,int r,int tl,int tr) // sum query in range l .. r
  {
      if(l>r)
        return 0;
      if(l==tl && r==tr) 
        return seg[v];
      int mid=(tl+tr)/2;
      return sum(2*v+1,l,min(mid,r),tl,mid)+sum(2*v+2,max(mid+1,l),r,mid+1,tr);   
  }
void update_query(int i,int k,int l,int r,int v) // uodate query , change index i element to k;
 {
    int mid=(l+r)/2;
    if(l==r)
        seg[v]=k;
    else
      {
        if(i<=mid)
           update_query(i,k,l,mid,2*v+1);
        else if(i>mid)
           update_query(i,k,mid+1,r,2*v+2);   
        seg[v]=seg[2*v+1]+seg[2*v+2];
      }
 }
int main()
{
   int n,t;
   cin>>n;
   a=vector<int>(n);
   seg=vector<int>(4*n);
   for(int i=0;i<n;i++)
     cin>>a[i];
   build(0,n-1,0);
   for(int i=0;i<4*n;i++)
     cout<<seg[i]<<" ";
    int b,k;
    cin>>t;
   while(t--)
    {
    cin>>b>>k;
    update_query(b,k,0,n-1,0);
    for(int i=0;i<4*n;i++)
     cout<<seg[i]<<" ";
     cout<<"\n";
   }
}