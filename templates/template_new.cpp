#include<bits/stdc++.h>
#define mod 1000000007
#define mo 998244353
using namespace std;
typedef long long ll;
typedef vector<int> vi;
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