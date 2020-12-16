#include<bits/stdc++.h>
using namespace std;
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
int main()
{
    string a,b;
    cin>>a>>b;
    cout<<str_add(a,b)<<"\n";
}