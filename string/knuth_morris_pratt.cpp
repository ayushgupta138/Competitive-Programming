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
vector<ll> substr_search(string s,string t)// all occurance of string s
 {                                         // in text t
     string str=s+'$'+t;
     int x,n;
     x=str.length();
     n=s.length();
     vector<ll> an(x);
     an=pre_func(str);
     vector<ll> ret;
     for(int i=0;i<x;i++)
      if(an[i]==n)
        ret.push_back(i-n+1-s.length()-1);
     return ret;   
 }
int main()
  {
      string s,t;
      cin>>t>>s;
      vector<ll> an;
      an=substr_search(s,t);
      for(int i:an)
        cout<<i<<" ";
      cout<<"\n";  
  }