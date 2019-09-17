#include<iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#define int long
using namespace std;

//Union find copied from : https://www.hackerearth.com/practice/notes/disjoint-set-union-union-find/
//finding root of an element.
int root(int Arr[ ],int i)
{
    if(i== Arr[i])
        return  i;
    return Arr[i] = root(Arr,Arr[i]);
}
/*modified union function where we connect the elements by changing the root of one of the element */

int Union(int Arr[ ] ,int A ,int B)
{
int root_A = root(Arr, A);
int root_B = root(Arr, B);
Arr[ root_A ] = root_B ;       //setting parent of root(A) as root(B).
}
bool find(int Arr[],int A,int B)
{
    if( root(Arr,A)==root(Arr,B) )       //if A and B have same root,means they are connected.
        return true;
    else
        return false;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int arr[] = {0,1,1,3,4,5,2,9,6,8,9,10};
    cout<<"1 2 "<<find(arr,1,3)<<endl;
    cout<<root(arr,6);


}
