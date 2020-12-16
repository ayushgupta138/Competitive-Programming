#include<iostream>
using namespace std;
bool isprime(int n)
{
    if(n<=1)
     return false;
    if(n<=3)
       return true;
    if(n%2==0 || n%3==0)
      return false;
    for(int i=5;(long long)i*i<=n;i=i+6)
       if(n%i==0 || n%(i+2)==0)
         return false;
    return true;          
}
int main()
{
   int n;
   cin>>n;
   cout<<isprime(n)<<endl;
}