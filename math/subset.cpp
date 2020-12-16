#include<bits/stdc++.h>
using namespace std;
vector<int> a,sub;
int n;
void search(int l)
  {
      if(l==n)
        {
               for(auto t=sub.begin();t!=sub.end();t++)
                 cout<<*t<<" ";
               cout<<endl;  
        }
       else
         {
             sub.push_back(a[l]);
             search(l+1);
             sub.pop_back();
             search(l+1);
         }
  }
int main()
{
    int k;
    cin>>n;
    for(int i=0;i<n;i++)
      {
          cin>>k;
          a.push_back(k);
      }
    search(0);
}