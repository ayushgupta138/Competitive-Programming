#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
vector<ll> ans;
void primefactor(ll n)
 {
     while(n%2==0)
      {
          ans.push_back(2);
          n/=2;
      }
    for(ll i=3;i*i<=n;i++)
      {
          while(n%i==0)
           {
               ans.push_back(i);
               n/=i;
           }
      }
  if(n>2)
    ans.push_back(n);
 }
int main()
{
   ll n;
   cin>>n;
   primefactor(n);
   for(int i:ans)
     cout<<i<<" ";
   cout<<"\n";   
}