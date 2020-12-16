#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define mo 998244353
#define frs(i,a,b) for(int i=int(a);i<int(b);i++)
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef set<int> si;
typedef map<int,int> mii;
ll gcdExtended(ll a,ll b,ll &x,ll &y)
{
    if(a==0)
    {
        x=0;
        y=1;
        return b;
    }
    ll x1,y1,d;
    d=gcdExtended(b%a,a,x1,y1);
    x=y1-(b/a)*x1;
    y=x1;
    return d;
}
ll modinverse(ll b,ll m)
{
    ll g,x,y;
    g=gcdExtended(b,m,x,y);
    if(g!=1)
      return -1;
    return (x%m+m)%m; 
} 
ll divide(ll a,ll b,ll m)
{
    ll inv;
    inv=modinverse(b,m);
    if(inv==-1)
      return -1;
    return (inv*(a%m))%m;
}
bool isprime(int n)
{
    if(n<=1)
     return false;
    if(n<=3)
       return true;
    if(n%2==0 || n%3==0)
      return false;
    for(int i=5;i*i<=n;i=i+6)
       if(n%i==0 || n%(i+2)==0)
         return false;
    return true;          
}
ll pow_mod(ll a,ll b,ll c)
{
  a%=c;
  ll ans=1;
  while(b>0)
    {
        if(b&1)
          ans=(ans*a)%c;
        b>>=1;
        a=(a*a)%c;  
    }
 return ans;
}
ll add(ll a,ll b)
  {
    a+=b;
    if(a>=mod)
      a-=mod;
    return a;  
  }
ll mult(ll a,ll b)
  {
    return (a*b)%mod;
  }
ll inv(ll a)
  {
   return pow_mod(a,mod-2);
  }
ll fact(ll n,ll m)
  {
    ll k=1;
    for(ll i=2;i<=n;i++)
       k=(k*i%m)%m;
    k%=m;
    return k;   
  }
ll comb(ll a,ll b,ll c)
 {
   ll u,d,k;
   if(b==0 || b==a) 
     return 1;
   else 
    { 
   u=fact(a,c);
   d=fact(b,c);
   k=fact(a-b,c);
   d=(d%c*k%c)%c;
   u=divide(u,d,c);
   return u;
   }
 }
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
ll a,b,c;
cin>>a>>b>>c;
cout<<comb(a,b,c)<<endl;
}
/*
#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define mo 998244353
typedef long long ll;
typedef vector<int> vi;
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   int n,t,k,l,r,x,y,z,m,c,p,q;
   ll res,sum,ans;
   string s;
   cin>>t;
   while(t--)
    {
        
    }
}
*/