#include<iostream>
using namespace std;
class Node
{
    public:
    int key;
    Node *leftptr,*rightptr;
    Node(int k)
    {
        key=k;
        leftptr=NULL;
        rightptr=NULL;
    }
};
 Node* newNode(int k)
 {
     Node* n=new Node(k);
     return n;
 }
 class Tree
{
    public:
    Node* root;
    Tree()
    {
        root=NULL;
    }
};
Node* insert(int k,Node* start)
     {
         if(start==NULL)
              return (newNode(k));
         if(k>start->key)
           start->rightptr=insert(k,start->rightptr);
         else if(k<start->key)
           start->leftptr=insert(k,start->leftptr);
     }
 void preorder(Node *ptr)
    {
        if(ptr!=NULL)
        {
            preorder(ptr->leftptr);
             cout<<ptr->key<<" ";
            preorder(ptr->rightptr);
           
        }
    }
int main()
{
    Tree t;
    Node* nd;
    int n,k;
    cin>>n;
    for(int i=0;i<n;i++)
     {
         cin>>k;
         if(i==0)
          {
           t.root=newNode(k);continue;}
         nd=insert(k,t.root);
         cout<<"Inserted "<<k<<endl;
     }
  preorder(t.root);
  cout<<endl;
}
