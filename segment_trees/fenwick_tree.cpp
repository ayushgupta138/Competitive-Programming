#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
class fenwick_tree
 {
    vector<ll> bit;
    public:
    fenwick_tree(vector<ll> a)
      {
          bit=vi(a.size());
          for(int i=0;i<a.size();i++)
             update(i,a[i]);
      }
    int at(int i)
      {
          return bit[i];
      }
    int sum(int l)
      {
          ll ans=0;
          while(l>=0)
            {
                ans+=bit[l];
                l=(l&(l+1))-1;
            }
         return ans;
      }
    int sum_query(int l,int r)
      {
          return sum(r)-sum(l-1);
      }
    void update(int i,int del)
      {
          while(i<bit.size())
            {
                bit[i]+=del;
                i=(i|(i+1));
            }
      }
 };
int main()
{
    int n;
    cin>>n;
    vi a(n);
    for(int i=0;i<n;i++)
      cin>>a[i];
    fenwick_tree fen_a(a);
      for(int i=0;i<n;i++)
        cout<<fen_a.at(i)<<" ";
      int l,r;
      cin>>l>>r;
      fen_a.update(l,r);
      for(int i=0;i<n;i++)
        cout<<fen_a.at(i)<<" ";
     cout<<"\n";
}
