#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
template<typename T>
using order_set = tree<T, null_type, less<T>, rb_tree_tag , tree_order_statistics_node_update>; 
template<typename T>
using order_multiset = tree<T,null_type,less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

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
void _p(T a)
  {
      cerr<<a<<" ";
  }
template<typename T>
void _prin(T a)
  {
    cerr<<a<<"\n";
  }
template<typename T, typename U>
void _ppr(pair<T,U> a)
 {
     cerr<<"{ "<<a.first<<" , "<<a.second<<" }"<<"\n";
 }
 template<typename T>
 void _psin(T a)
  {
      for(auto t:a)
        _p(t);
      cerr<<"\n";  
  }
template<typename T>
void _pdou(T a)
  {
      for(auto t:a)
        _ppr(t);
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
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll l,r,x,y,z,n,m,p,q,g,h,k,ans,res,sum,te=1,d,e,o,f;
    string s,t;
    //cin>>te;
    while(te--)
     {
          cin>>n>>x;
          vi a(n);
          for(int i=0;i<n;i++)
            cin>>a[i];
          ans=meet_middle(a,x);
          cout<<ans<<"\n";
     }
}  