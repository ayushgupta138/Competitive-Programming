#include<bits/stdc++.h>
using namespace std;
int subarr_sum(vector<int> &a,int k)
{
    int pre=0;
    int ans=0,n=a.size();
    unordered_map<int,int> ump;
    ump[pre]++;
    for(int i=0;i<n;i++)
      {
          pre+=a[i];
          ans+=ump[pre-k];
      ump[pre]++;
      }
    return ans;
}
int main()
{
    int n,k;
    cin>>n>>k;
    vector<int> a(n);
    for(int i=0;i<n;i++)
      cin>>a[i];
    int ans=subarr_sum(a,k);
    cout<<ans<<endl;
}