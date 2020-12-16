#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int> a(n);
    long long sum=0;
    for(int i=0;i<n;i++)
      {
           cin>>a[i];
           sum+=a[i];
      }
    sort(a.begin(),a.end());
    for(int i=n-1;i>=0;i--)
     {
         if(2*a[i]<=sum)
           sum-=2*a[i];
     }
    cout<<sum<<"\n";
}