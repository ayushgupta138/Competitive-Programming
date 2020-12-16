#include<iostream>
using namespace std;
typedef long long ll;
ll power(ll a,ll b)
{
    ll ans=1;
    while(b>0)
    {
        if(b&1)
          ans*=a;
        b>>=1;
        a*=a;  
    }
 return ans;
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
ll fact(ll n,ll m)
  {
    ll k=1;
    for(ll i=2;i<=n;i++)
       k=(k*i%m)%m;
    k%=m;
    return k;   
  }

int main()
{
   ll n,m;
   cin>>n>>m;
   cout<<power(n,m)<<endl;
}