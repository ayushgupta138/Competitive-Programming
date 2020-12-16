#include<iostream>
#include<algorithm>
using namespace std;
void prin(int a[],int n)
{
    for(int i=0;i<n;i++)
      cout<<a[i]<<" ";
   cout<<endl;
}
int main()
{
   int n;
   cin>>n;
   int a[n];
   for(int i=0;i<n;i++)
      cin>>a[i];
   int k=5;
   while(k--)
   {
       next_permutation(a,a+n);
       prin(a,n);
   }
  prin(a,n);
}
  