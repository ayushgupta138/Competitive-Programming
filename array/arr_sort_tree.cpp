#include<bits/stdc++.h> 
using namespace std; 
  
void printSorted(int arr[], int start, int end) 
{      
    if(start > end) 
        return; 
      
    // print left subtree 
    printSorted(arr, start*2 + 1, end); 
      
    // print root 
    cout << arr[start] << " "; 
      
    // print right subtree 
    printSorted(arr, start*2 + 2, end);  
} 
  
int main() 
{ 
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
      cin>>a[i];
    printSorted(a, 0,n-1);
    getchar();
    return 0;
} 