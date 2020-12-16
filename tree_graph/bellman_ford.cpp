#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define mo 998244353
#define tra(t,x) for(auto t=x.begin();t!=x.end();t++)
#define all(x) x.begin(),x.end()
#define sortall(x) sort(all(x))
#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define inf LONG_LONG_MAX
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
struct edge
{
    int a,b,wt;
};
vector<edge> v;
vll d;
vi p;
int x,n;
int bell_ford(int s)
{
    int m=v.size();
    d[s]=0;
    for(int i=0;i<n;i++)
      {
          x=-1;  
           bool flag=false;
          for(int j=0;j<m;j++)
           {
               if(d[v[j].a]<inf && d[v[j].b]>d[v[j].a]+v[j].wt)
                 {
                     d[v[j].b]=max(-inf,d[v[j].a]+v[j].wt);
                     x=v[j].b;
                     p[v[j].b]=v[j].a;
                     flag=true;
                 }
           }
        if(!flag)
          {
            x=-1;
            break;
          }
      }
   if(x==-1)
     return 1;
   else 
     return 0; 
}
void path_res(int b)
 {
     
     vi pa;
     for(int i=b;i!=-1;i=p[i])
        pa.push_back(i);
      reverse(all(pa));
     tra(t,pa)
       cout<<*t+1<<" ";
    cout<<endl;   
 }
void neg_cycle()
 {
    if(x==-1)
      cout<<"No negative cycle\n";
    else 
      {
             int y=x;
             for(int i=0;i<n;i++)
                 y=p[y];
             vi path;
            for(int i=y;;i=p[i])
              {
                  path.push_back(i);
                  if(i==y && path.size()>1)
                    break;
              }
            reverse(all(path));
            tra(t,path)
              cout<<*t+1<<" ";
            cout<<endl;  
      } 
 }
int main()
{
    //fastio();
    int m;
    cin>>n>>m;
    int a,b,c;
    for(int i=0;i<m;i++)
    {
       cin>>a>>b>>c;
       a--,b--;
       v.push_back({a,b,c});  
    }
   d=vll(n,LONG_LONG_MAX);
   p=vi(n,-1);
   cout<<"Enter the vertex from which you want to run:\n";
   cin>>a;
   a--;
   if(bell_ford(a))
     {
       cout<<"No negative cycle exists\n";
       cout<<"d is:\n";
       for(int i=0;i<n;i++)
         cout<<d[i]<<" ";
       cout<<endl;  
       cout<<"Enter the vertex to which path is needed:\n";
       cin>>a;
       a--;
       path_res(a);
     }
   else
   {
     cout<<"Negative cycle exists\n";
     neg_cycle();
   }
}