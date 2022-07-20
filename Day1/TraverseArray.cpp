#include <bits/stdc++.h>
using namespace std;
//Traversing means going through each element in the array
void traverseArray(int * arr, int n)
{
    //Here arr is the array and n is the no.of elements in array
    for(int i = 0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main()
{
    //initialising the array
    int arr[] = {1,2,3,4,5,6,7};
    //finding the length of the array
    int n  = sizeof(arr)/sizeof(arr[0]);
    traverseArray(arr,n);
    return 0;
}