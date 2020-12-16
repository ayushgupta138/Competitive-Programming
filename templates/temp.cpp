#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
template<typename T>
using order_set = tree<T, null_type, less<T>, rb_tree_tag , tree_order_statistics_node_update>; 
template<typename T>
using order_multiset = tree<T,null_type,less_equal<T>, rg_tree_tag, tree_order_statistics_node_update>;

#define mod 1000000007
#define mo 998244353
#define rep(i,a,n) for(int i=a;(n>a)?i<=n:i>=n;(n>a)?i++:i--)
#define in(i,n,a) for(int i=0;i<n;i++) cin>>a[i];
#define reps(i,n) for(int i=0;i<n;i++)
#define all(x) x.begin(),x.end()
#define sortrev(x) sort(x.rbegin(),x.rend())
#define sor(x) sort(all(x))
#define rev(x) reverse(all(x))
#define PI 3.141592653589793238462643
#define epsilon 0.000000001

typedef long long ll;
typedef vector<ll> vi;
typedef pair<int,int> pii;
typedef vector<pii> vpii;

// debugging tools
template<typename T>
void __p(T a)
  {
      cout<<a<<" ";
  }
template<typename T, typename U>
void __ppr(pair<T,U> a)
 {
     cout<<"{ "a.first<<" "<<a.second<<" }"<<"\n";
 }
 template<typename T>
 void __psin(T a)
  {
      for(auto t:a)
        __p(t);
      cout<<"\n";  
  }
template<typename T>
void __pdou(T a)
  {
      for(auto t:a)
        __ppr(t);
  }  

// Modular Arithmatic functions
ll add(ll a,ll b,ll c)
 {
     a+=b;
     if(a>=c)
       a-=c;
     return a;  
 }
ll sub(ll a,ll b,ll c)
 {
     a-=b;
     if(a<0)
       a+=c;
     return a;  
 } 
 ll mult(ll a,ll b, ll c)
   {
       return (a*b)%c;
   }
ll gcdExtended(ll a,ll b,ll &x,ll &y) 
{
    if(a==0)
    {
        x=0;
        y=1;
        return b;
    }
    ll x1,y1,d;
    d=gcdExtended(b%a,a,x1,y1);
    x=y1-(b/a)*x1;
    y=x1;
    return d;
}
ll modinverse(ll b,ll m)
{
    ll g,x,y;
    g=gcdExtended(b,m,x,y);
    if(g!=1)
      return -1;
    return (x%m+m)%m; 
} 
ll divide(ll a,ll b,ll m)
{
    ll inv;
    inv=modinverse(b,m);
    if(inv==-1)
      return -1;
    return (inv*(a%m))%m;
}
ll bin_exp(ll a,ll b,ll c=1000000000000000000LL)
 {
     a%=c;
  ll ans=1;
  while(b>0)
    {
        if(b&1)
          ans=(ans*a)%c;
        b>>=1;
        a=(a*a)%c;  
    }
 return ans;
 }
ll inv(ll a,ll c)
  {
      return bin_exp(a,c-2);
  }   

// Combinatorics
ll fact(ll n,ll c=1000000000000000000LL)  
 {
     ll ans=1;
     for(int i=1;i<=n;i++)
       ans=(ans*i)%c;
     return ans;  
 }
ll comb(ll n,ll r,ll c=1000000000000000000LL)
 {
     if(r==0 || r==n)
       return 1;
     ll ans=1;
     ll x=max<ll>(r,n-r);
     ll y=min<ll>(r,n-r);
     for(ll i=n;i<x;i--)
       {
           if(i%y==0 && y>1)
             {
                   ans=(ans*i/y)%c;
                   y--;
             }
           else
              ans=(ans*i)%c;
        }
   return ans;
 } 

// intersection union of pair ans rectangles
pair<int,int> uni(pair<int,int> a,pair<int,int> b)
  {
      if(a.first>b.first)
        swap(a,b);
      pair<int,int> ans;
      if(b.first>a.second)
        return {-1,-1};
      ans.first=min(a.first,b.first);
      ans.second=max(a.second,b.second);
      return ans;   
  }
pair<int,int> intersect(pair<int,int> a,pair<int,int> b)
  {
      if(a.first>b.first)
        swap(a,b);
      if(b.first>a.second)
        return {-1,-1};
      pair<int,int> ans;
      ans.first=max(a.first,b.first);
      ans.second=min(a.second,b.second);
      return ans;    
  }  
vector<int> a(4),b(4),c(4);
vector<int> rec_inter(vector<int> &a, vector<int> &b)
  {
       c[0]=max(a[0],b[0]);
       c[1]=max(a[1],b[1]);
       c[2]=min(a[2],b[2]);
       c[3]=min(a[3],b[3]);
       if(c[0]>c[2] || c[1]>c[3])
         c[0]=c[1]=c[2]=c[3]=INT_MIN;
       return c;  
  }

// string function
 string str_add(string a,string b)
 {
    string ans;
    if(a.length()<b.length())
      swap(a,b);
    int c=0,n=a.length()-1,k=b.length()-1,x,y,z;
    for(int i=0;i<b.length();i++)
      {
            x=a[n-i]-'0';
            y=b[k-i]-'0';
            z=x+y+c;
            c=z/10;
            z%=10;
            ans.push_back(z+'0');
      }
    for(int i=n-b.length();i>=0;i--)
      {
          x=a[i]-'0';
          z=x+c;
          c=z/10;
          z%=10;
          ans.push_back(z+'0');
      }
  reverse(ans.begin(),ans.end());
  return ans;
 }

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
 ll start_pali(string s) // returns the maximum length of palindrome 
  {                      // starting from the beginning in O(n)
      string t=s;
      rev(s);
      t+='$'+s;
      int n=s.length();
      vi a(2*n+1);
      a=pre_func(t);
      int k,x;
      ll ans=LLONG_MIN;
      for(int i=n+1;i<=2*n;i++)
        {
           k=a[i];
           x=2*n-i;
           if(k==x)
             ans=max<ll>(ans,2*k);
           else if(x==k-1)
             ans=max<ll>(ans,2*k-1);  
        }
    return ans;
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
 // Prime checkers
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

bool isprim(int n)
{
    if(n<=1)
     return false;
    if(n<=3)
       return true;
    if(n%2==0 || n%3==0)
      return false;
    for(int i=5;i*i<=n;i=i+6)
       if(n%i==0 || n%(i+2)==0)
         return false;
    return true;          
}
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
// graph algorithm
// bipartite checking 
vector<vector<int>> v;
vector<int> a,b;
int color()
 {
     int n=v.size();
     vector<int> col(n);
     col[0]=1;
     int h=0;
     for(int i=0;i<n;i++)
       {
           for(int t:v[i])
              if(col[t]==0)
               col[t]=3-col[i];
              else if(col[t]==col[i])
                 {
                     h=1;
                     break;
                 } 
            if(h)
               break;
       }
 
 if(h)
   return 0;
 for(int i=0;i<n;i++)
    if(col[i]==1)
      a.push_back(i);
     else 
        b.push_back(i);
  return 1;       
 }

// cycle detection
vector<vi> v;
vi vis,po;
bool dfs_cy(ll &st,ll &en,int x)
  {
     vis[x]=1;
     for(int i:v[x])
      if(i!=po[x])
        {
            if(vis[i]==0)
              {
                  po[i]=x;
                  if(dfs_cy(st,en,i))
                    return true;
              }
           else if(vis[i]==1)
             {
                 st=i;
                 en=x;
                 return true;
             }
        }
   vis[x]=2;
   return false;
  }
vi cycle_detection(int x)
  {      
      ll st,en;
      ll n=v.size();
      vis=vi(n);
      po=vi(n,-1);
      vi an;
      if(dfs_cy(st,en,x))
         {
               ll k=en;
               while(k!=st)
                 {
                     an.push_back(k);
                     k=po[k];
                 }
              an.push_back(st);
              reverse(an.begin(),an.end());
         }
     else
      an.push_back(-1);
     return an; 
  }
void inser(int k,ll x,ll y) // k is 1 if graph is undirected
  {
      if(k)
        {
            v[x].push_back(y);
            v[y].push_back(x);
        }
     else
        v[x].push_back(y);
    }
// special algo
vi subset_sum(vi &a,ll x) // determines if sum x is possible with 
  {                      // some subset of a
      ll sum=0;
      for(ll i:a)
        sum+=i;
      vi an;
      if(x>sum)
        {
           an.push_back(-1);
           return an;
        }  
     else
       {
           ll n=a.size();
           int dp[n][x+1]={};
           for(int i=0;i<n;i++)
            dp[i][0]=1;
           if(a[0]<=x)
             dp[0][a[0]]=1;
           int check[n][x+1];
           memset(check,-1,sizeof(check));
           for(int i=1;i<n;i++)
              {
                  for(int j=0;j<=x;j++)
                     {
                      if(j>=a[i] && dp[i-1][j-a[i]])
                       {
                           dp[i][j]=1;
                           check[i][j]=j-a[i];
                       }
                     dp[i][j]|=dp[i-1][j];
                     if(check[i][j]==-1 && dp[i][j])
                       check[i][j]=j;
                     }
              }  
          if(dp[n-1][x])
            {
                ll k=x;
                for(int i=n-1;check[i][k]!=-1;i--)
                  if(check[i][k]!=k)
                    {
                        an.push_back(i);
                        k=check[i][k];
                    }
            }
         else
            an.push_back(-1);
         return an;
        }
  }
void calc_subset_sum(vi &a,vi &b,int l,int r)
 {
     for(ll i=0;i<(1LL<<(r-l+1));i++)
       {
           ll sum=0;
           for(ll j=0;j<r-l+1;j++)
             if((i&(1LL<<j)))
               sum+=a[j+l];
           b.push_back(sum);    
       }
 }
ll meet_middle(vi &a,ll x)
  {
      vi b,c;
      int n=a.size();
      calc_subset_sum(a,b,0,n/2);
      calc_subset_sum(a,c,n/2 + 1,n-1);
      sor(b);
      sor(c);
      ll ans=LLONG_MIN,k;
      for(ll i=0;i<b.size();i++)
        {
             k=(ll)(lower_bound(c.begin(),c.end(),x-b[i])-c.begin());
             if(k>0)
               ans=max<ll>(ans,b[i]+c[k-1]);
        }   
    return ans;
  }
// 
// main starts
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll l,r,x,y,z,n,m,p,q,g,h,k,ans,res,sum,t;
    string s;
    cin>>t;
    while(t--)
     {
            
     }
}  
  
