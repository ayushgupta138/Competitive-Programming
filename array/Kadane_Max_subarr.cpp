#include<bits/stdc++.h>
using namespace std;
int maxsubarrSum(int a[],int n,int &start,int &end)
{
    int max_of_array=INT_MIN;
    start=end=0;
    int max_till_end=0,k=0;
    for(int i=0;i<n;i++)
      {
          max_till_end+=a[i];
          if(max_of_array<max_till_end)
            {
                max_of_array=max_till_end;
                start=k;
                end=i;
            }
          
          if(max_till_end<0  && i!=n-1)
            {
                k=i+1;
                max_till_end=0;
            }  
      }
return max_of_array;
}
int main()
{
      int n,s,e;
      cin>>n;
      int a[n];
      for(int i=0;i<n;i++)
        cin>>a[i];
      int ans=maxsubarrSum(a,n,s,e);
      cout<<ans<<" "<<s<<" "<<e<<endl;   
}