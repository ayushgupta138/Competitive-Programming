#include<bits/stdc++.h>
using namespace std;
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
int main()
{
       for(int i=0;i<4;i++)
         cin>>a[i];
       for(int i=0;i<4;i++)
         cin>>b[i];
    c=rec_inter(a,b);
    if(c[0]==INT_MIN)
      cout<<"No intersection\n";
    else 
      { 
          cout<<c[0]<<" "<<c[1]<<" "<<c[2]<<" "<<c[3]<<"\n";
      }   
}