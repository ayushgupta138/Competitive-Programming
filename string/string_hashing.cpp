#include<bits/stdc++.h>
#define mod 1000000007
#define mo 998244353
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
ll p=31;
vi po(1000005);
vi calc_hash(string s,ll c)
  {
      vi hash_str(s.length());
      hash_str[0]=s[0]-'a'+1;
      for(int i=1;i<s.length();i++)
        hash_str[i]=(hash_str[i-1]+(s[i]-'a'+1)*po[i])%c;
  }
ll get_hash_substr(int l,int r,string s,vi &hash_str,int c)
  {
      ll p,q;
      p=hash_str[r];
      if(l)
        q=hash_str[l-1];
      else 
        q=0;
      ll ans=(p-q+c)%c;
      ans=(ans*po[s.length()-l]);  
      return ans; 
  }  
void calc()
 {
     po[0]=1;
     for(int i=1;i<1000005;i++)
       po[i]=(po[i-1]*p)%mod;
 }
int main()
 {
     string s;
     int n;
     cin>>s;
     n=s.length();
     vi ha=calc_hash(s,mod);
     vi has_s=calc_hash(s,mo);
 }