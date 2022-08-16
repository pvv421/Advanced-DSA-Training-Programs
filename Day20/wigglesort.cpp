#include <bits/stdc++.h>
using namespace std;
void wigglesort(int arr[], int n)
{
    for(int i = 0; i<n; i+=2)
    {
        if(i>0 && arr[i]>arr[i-1])
        {
            swap(arr[i],arr[i-1]);
        }
        if(i+1<n && arr[i]>arr[i+1])
        {
            swap(arr[i],arr[i+1]);
        }
    }
}
void display(int a[], int n)
{
    for(int i = 0; i<n; i++)
        cout << a[i] << " ";
    cout << "\n";
}
int main()
{
    int A[] = {1,5,3,2,6,0,9,8,7,4};
    int n = sizeof(A)/sizeof(A[0]);
    display(A,n);
    wigglesort(A,n);
    display(A,n);
    return 0;
}
