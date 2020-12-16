#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> spf;
vector<bool> isprime;
vector<ll> prime;
void mod_sieve(int n)
{
      isprime[0]=false;
      isprime[1]=false;
      for(ll i=2;i<=n;i++)
         {
             if(isprime[i])
               {
                   prime.push_back(i);
                   spf[i]=i;
               }
             for(ll j=0;j<prime.size() && i*prime[j]<=n && prime[j]<=spf[i];j++)
                 {
                     isprime[i*prime[j]]=false;
                     spf[i*prime[j]]=prime[j];
                 }
         }
}
int main()
{
    ll n;
    cin>>n;
    spf=vector<ll>(n+1);
    isprime=vector<bool>(n+1,true); 
    mod_sieve(n);
   // for(int i=1;i<=n;i++)
    //  cout<<spf[i]<<" ";
    for(int i:prime)
      cout<<i<<" ";
    cout<<endl;  
}