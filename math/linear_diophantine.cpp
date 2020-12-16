//beauty
//well written poetry
#include<iostream>
using namespace std;
int gcdExtended(int a,int b,int &x,int &y) //returns gcd of a and b and changes the value of x and y such that they satisfy
{                                         // ax+by=gcd(a,b)
    if(a==0)
    {
        x=0;
        y=1;
        return b;
    }
    int x1,y1,d;
    d=gcdExtended(b%a,a,x1,y1);
    x=y1-(b/a)*x1;
    y=x1;                                                 
    return d;
}
int modinverse(int b,int m)       // returns inverse modulo of b under mod m or -1 if it does not exist
{
    int g,x,y;
    g=gcdExtended(b,m,x,y);
    if(g!=1)
      return -1;
    return (x%m+m)%m; 
} 
int divide(int a,int b,int m)  // returns the result of division of a/b under mod m or -1 if not applicable
{
    int inv;
    inv=modinverse(b,m);
    if(inv==-1)
      return -1;
    return (inv*(a%m))%m;  
}
int main()
{
    int a,b,x,y,m;              
    cin>>a>>b;
    cout<<gcdExtended(a,b,x,y)<<endl;
    cout<<x<<" "<<y<<endl;
    cin>>a>>b;
    cout<<modinverse(a,b)<<endl;
    cin>>a>>b>>m;
    cout<<divide(a,b,m)<<endl;
}