#include<bits/stdc++.h>
using namespace std;
vector<bool> is_prime;
set<int> s;
void sieve_ero(int n)
{
   is_prime[0]=is_prime[1]=false;
   for(int i=2;i<=n;i++)
     {
         if(is_prime[i])
           {
               s.insert(i);
               for(long long j=(long long)i*i;j<=n;j+=i)
                 is_prime[j]=false;
           }
     }
}
int main()
{
    int n;
    cin>>n;
    is_prime=vector<bool>(n+1,true);
    sieve_ero(n);
    for(auto t=s.begin();t!=s.end();t++)
       cout<<*t<<" ";
    cout<<endl;   
}