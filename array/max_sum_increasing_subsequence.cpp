#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
vi seg,c,a;
void build(int l,int r,int v)
  {
      if(l==r)
        seg[v]=c[l];
      else 
        {
            ll mid=l+(r-l)/2;
            build(l,mid,2*v+1);
            build(mid+1,r,2*v+2);
            seg[v]=max<ll>(seg[2*v+1],seg[2*v+2]);
        } 
  }
ll query(int l,int r,int tl,int tr,int v)
  {
      if(l>r)
        return INT_MIN;
      if(l==tl && r==tr)
        return seg[v];
      ll mid=tl+(tr-tl)/2;
      return max<ll>(query(l,min<ll>(r,mid),tl,mid,2*v+1),query(max<ll>(l,mid+1),r,mid+1,tr,2*v+2));    
  }
void update(int l,int r,int i,int k,int v)
  {
      if(l==r)
        seg[v]=k;
      else 
        {
            ll mid=l+(r-l)/2;
            if(i<=mid)
              update(l,mid,i,k,2*v+1);
            else 
              update(mid+1,r,i,k,2*v+2);
            seg[v]=max<ll>(seg[2*v+1],seg[2*v+2]);   
        } 
  }
bool cmp(ll i,ll j)
{
    return a[i]<a[j];
}
void prin()
  {
      for(int i=0;i<c.size();i++)
         cout<<c[i]<<" ";
       cout<<"\n";  
  }
int main()
  {
     ll n;
     cin>>n;
     vi b(n);
     seg=vi(4*n);
     a=vi(n);
     c=vi(n);
     for(int i=0;i<n;i++)
       cin>>a[i];
     for(int i=0;i<n;i++)
      c[i]=i;
     sort(c.begin(),c.end(),cmp);
     for(int i=0;i<n;i++)
         b[c[i]]=i;
     c=vi(n,-1);
     build(0,n-1,0);
     vi dp(n,-1);
     for(int i=0;i<n;i++)
       {
           ll x=b[i];
           ll y=query(0,x-1,0,n-1,0);
           dp[i]=max<ll>(a[i],y+a[i]);
           update(0,n-1,x,dp[i],0);
           c[x]=dp[i];
       }  
  ll ans=-1;
  for(int i=0;i<n;i++)
    ans=max<ll>(ans,dp[i]);
  cout<<ans<<"\n";   
  }