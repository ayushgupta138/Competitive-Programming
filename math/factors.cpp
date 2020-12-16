#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> a,b;
void factorize(ll n)
 {
     b.push_back(n);
     a.push_back(1);
     if(n%2==0)
      {
          a.push_back(2);
          if(n!=4)
          b.push_back(n/2);
      }
      if(n%3==0)
        {
            a.push_back(3);
            if(n!=9)
            b.push_back(n/3);
        } 
      for(ll i=4;i*i<=n;i++)
        {
            if(n%i==0)
              {
                  a.push_back(i);
                  if(i!=(n/i))
                  b.push_back(n/i);
              }
        }
reverse(b.begin(),b.end());
for(auto t=b.begin();t!=b.end();t++)
   a.push_back(*t);
}
int main()
{
   ll n;
   cin>>n;
   factorize(n);
   for(auto t=a.begin();t!=a.end();t++)
      cout<<*t<<" ";
  cout<<endl;    
}