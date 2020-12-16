#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
vi a,seg;
void build(int v,int l,int r)
  {
      if(l==r)
        {
            seg[v]=l;
            return;
        }
      ll mid,x,y;
      mid=l+(r-l)/2;
      build(2*v+1,l,mid);
      build(2*v+2,mid+1,r);
      x=seg[2*v+1];
      y=seg[2*v+2];
      if(a[x]<a[y])
        seg[v]=x;
      else 
        seg[v]=y; 
  }
ll query(int v,int l,int r,int tl,int tr)
  {
      if(l>r)
        return -1;
      if(l==tl && r==tr)
        return seg[v];
      ll x,y,mid;
      mid=tl+(tr-tl)/2;
      x=query(2*v+1,l,min<ll>(mid,r),tl,mid);
      y=query(2*v+2,max<ll>(l,mid+1),r,mid+1,tr);    
      if(x==-1)
        return y;
      else if(y==-1)
        return x;
      else if(a[x]<a[y])
        return x;
      else 
        return y;    
  }
void update(int i,int k,int v,int l,int r)
  {
      ll x,y,mid;
      mid=l+(r-l)/2;
      if(l==r)
        a[i]=k;
      else 
        {
            if(i<=mid)
              update(i,k,2*v+1,l,mid);
            else 
              update(i,k,2*v+2,mid+1,r);
            x=seg[2*v+1];
            y=seg[2*v+2];
            if(a[x]<a[y])
              seg[v]=x;
            else 
              seg[v]=y;    
        } 
  }  
int main()
 {
      ll n;
      cin>>n;
      a=vi(n);
      seg=vi(4*n);
      for(int i=0;i<n;i++)
        cin>>a[i];
      build(0,0,n-1);
      ll q,k;
      cin>>q;
      while(q--)
       {
           ll l,r;
           cin>>l>>r;
           cout<<query(0,l,r,0,n-1)<<"\n";
       }
     cin>>q>>k;
     update(q,k,0,0,n-1);
     cin>>q;
     while(q--)
       {
           ll l,r;
           cin>>l>>r;
           cout<<query(0,l,r,0,n-1)<<"\n";
       }
 }