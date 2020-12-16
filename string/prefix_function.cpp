#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> pre_func(string s) // returns a vector such that pi[i]
 {                           // is the longest proper prefix s.t 
      int n=s.length(),j;    // prefix==suffix for the substring 
      vector<ll> pi(n);     // s[0 .... i]
      for(int i=1;i<n;i++)
        {
           j=pi[i-1];
           while(j>0 && s[j]!=s[i]) 
             j=pi[j-1];
          if(s[j]==s[i])
            j++;
          pi[i]=j;      
        }
   return pi;
 }
int main()
{
    string s;
    cin>>s;
    vector<ll> ans(s.length());
    ans=pre_func(s);
    for(ll i:ans)
      cout<<i<<" ";
    cout<<"\n";  
} 