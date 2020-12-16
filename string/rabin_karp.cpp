#include<bits/stdc++.h>
#define mod 1000000007
#define mo 998244353
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
ll p=31;
vi calc_hash(string s,ll c,vi &po)
  {
      vi hash_str(s.length());
      hash_str[0]=s[0]-'a'+1;
      for(int i=1;i<s.length();i++)
        hash_str[i]=(hash_str[i-1]+(s[i]-'a'+1)*po[i])%c;
     return hash_str;
  }
ll get_hash_substr(int l,int r,string s,vi &hash_str,int c,vi &po)
  {
      ll p,q;
      p=hash_str[r];
      if(l)
        q=hash_str[l-1];
      else 
        q=0;
      ll ans=(p-q+c)%c;
      return ans; 
  }  
vi calc(ll c)
 {
     vi po(1000005);
     po[0]=1;
     for(int i=1;i<1000005;i++)
       po[i]=(po[i-1]*p)%c;
    return po;
 }  
int main()
{
    string s,t;
    int n;
    cin>>s>>t;
    n=s.length();
    vi po_1,po_2;
    po_1=calc(mod);
    po_2=calc(mo);
    vi pt_1,pt_2,str_1,str_2;
    pt_1=calc_hash(t,mod,po_1);
    pt_2=calc_hash(t,mo,po_2);
   str_1=calc_hash(s,mod,po_1);
   str_2=calc_hash(s,mo,po_2);
   ll x=pt_1.back(),y=pt_2.back();
   int l=t.length();
   vi an;
   for(int i=0;i<n-l;i++)
     {
         ll a,b,c,d;
         a=get_hash_substr(i,i+l-1,s,str_1,mod,po_1);
         b=get_hash_substr(i,i+l-1,s,str_2,mo,po_2);
         if(a==(x*po_1[i])%mod && b==(y*po_2[i])%mo)
            an.push_back(i);  
     }
   for(auto it:an)
     cout<<it<<" ";
   cout<<"\n";  
}