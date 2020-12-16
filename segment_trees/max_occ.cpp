#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>> seg;
vector<int> a;
pair<int,int> comb(pair<int,int> a,pair<int,int> b)
  {
      if(a.first>b.first)
         return a;
      else if(b.first>a.first)
         return b;
      return make_pair(a.first,a.second+b.second);       
  }
void build(int l,int r,int v)
  {
      if(l==r)
        {
            seg[v].first=a[l];
            seg[v].second=1;
            return;
        }
      int mid=(l+r)/2;
      build(l,mid,2*v+1);
      build(mid+1,r,2*v+2);
      seg[v]=comb(seg[2*v+1],seg[2*v+2]);
}
pair<int,int> query(int l,int r,int v,int tl,int tr)
  {
      if(l>r)
         return make_pair(INT_MIN,0);
      if(l==tl && r==tr)
        return seg[v];
      int mid=(tl+tr)/2;
        return comb(query(l,min(r,mid),2*v+1,tl,mid),query(max(mid+1,l),r,2*v+2,mid+1,tr));
  }
void update(int l,int r,int i,int k,int v)
  {
      if(l==r)
        seg[v]=make_pair(k,1);
      else 
        {
            int mid=(l+r)/2;
            if(i<=mid)
               update(l,mid,i,k,2*v+1);
            else 
               update(mid+1,r,i,k,2*v+2);
            seg[v]=comb(seg[2*v+1],seg[2*v+2]);     
        } 
  }
int main()
{
    int n;
    cin>>n;
    a=vector<int>(n);
    seg=vector<pair<int,int>>(4*n);
    for(int i=0;i<n;i++)
      cin>>a[i];
    build(0,n-1,0);
    int l,r;
    cin>>l>>r;
    pair<int,int> pr=query(l,r,0,0,n-1);
    cout<<pr.first<<" "<<pr.second<<"\n";
}