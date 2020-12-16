#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
vi a,seg,lazy;
void build(int v,int l,int r)
  {
      if(l==r)
        seg[v]=a[l];
      else 
        {
            int mid=(l+r)/2;
            build(2*v+1,l,mid);
            build(2*v+2,mid+1,r);
            seg[v]=max(seg[2*v+1],seg[2*v+2]);
        } 
  }
void update(int v,int l,int r,int tl,int tr,int k)
  {
      if(lazy[v])
        {
            seg[v]=lazy[v];
            if(tl!=tr)
              {
                  lazy[2*v+1]=lazy[v];
                  lazy[2*v+2]=lazy[v];
              }
            lazy[v]=0;
        }
      if(tl>r || tr<l)
        return;
      if(tl>=l && tr<=r)
        {
            seg[v]=k;
            if(tl!=tr)
              {
                  lazy[2*v+1]=k;
                  lazy[2*v+2]=k;
              }
            return;
        }  
    int mid=(tl+tr)/2;
    update(2*v+1,l,r,tl,mid,k);
    update(2*v+2,l,r,mid+1,tr,k);
    seg[v]=max(seg[2*v+1],seg[2*v+2]);
  }
int query(int v,int l,int r,int tl, int tr)
 {
   if(lazy[v])
        {
            seg[v]=lazy[v];
            if(tl!=tr)
              {
                  lazy[2*v+1]=lazy[v];
                  lazy[2*v+2]=lazy[v];
              }
            lazy[v]=0;
        }
    if(tl>r || tr<l)
      return INT_MIN;
    if(tl>=l && tr<=r)
      return seg[v];
    int mid=(tl+tr)/2;
    return max(query(2*v+1,l,r,tl,mid),query(2*v+2,l,r,mid+1,tr));          
 }
int main()
{
  int n;
  cin>>n;
  a=vi(n);
  seg=vi(4*n);
  lazy=vi(4*n);
  for(int i=0;i<n;i++)
    cin>>a[i];
  build(0,0,n-1);
  int u,q,l,r,k;
  cin>>u>>q;
  for(int i=0;i<u;i++)
    {
        cin>>l>>r>>k;
        update(0,l,r,0,n-1,k);
    }
   for(int i=0;i<q;i++)
     {
         cin>>l>>r;
         cout<<query(0,l,r,0,n-1)<<"\n";
     }
}