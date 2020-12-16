#include<bits/stdc++.h>
using namespace std;
vector<int> a,seg;
void build(int l,int r,int v) // builds a segment tree. Currently the function processes the range a[l] ... a[r] at the vertex v of segment tree.
  {
      if(l==r)
        seg[v]=a[l];
      else 
        {
            int mid=(l+r)/2;
            build(l,mid,2*v+1);
            build(mid+1,r,2*v+2);
            seg[v]=max(seg[2*v+1],seg[2*v+2]);
        } 
  }
void update_query(int i,int k,int l,int r,int v) // update the ith index to k ie a[i]=k processing a[l]  ... a[r] at vertex v of segment tree.
  {
      if(l==r)
        seg[v]=k;
      else 
        {
            int mid=(l+r)/2;
            if(i<=mid)
              update_query(i,k,l,mid,2*v+1);
            else 
              update_query(i,k,mid+1,r,2*v+2);
            seg[v]=max(seg[2*v+1],seg[2*v+2]);   
        } 
  }
int query(int l,int r,int v,int tl,int tr) // returns max in the range a[l] ... a[r] 
  {
      if(l>r)
        return INT_MIN;
      if(l==tl && r==tr)
        return seg[v];
      else
        {
            int mid=(tl+tr)/2;
            return max(query(l,min(r,mid),2*v+1,tl,mid),query(max(mid+1,l),r,2*v+2,mid+1,tr));
        } 
         
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
    for(int i=0;i<4*n;i++)
      cout<<seg[i]<<" ";
   cout<<"\n";   
   int i,k;
   cin>>i>>k;
   cout<<query(i,k,0,0,n-1)<<"\n";
}