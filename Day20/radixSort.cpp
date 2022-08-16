//not working. working only in java
#include <bits/stdc++.h>
using namespace std;
void countingSort(int arr[], int n, int exp)
{
    int output[n];
    int count[10];
    for(int i = 0; i<n; i++)
    {
        count[(arr[i]/exp)%10]++;
    }
    for(int i = 1; i<10; i++)
    {
        count[i] += count[i-1];
    }
    for(int i = n-1; i>=0; i--)
    {
        output[count[(arr[i]/exp)%10]-1] = arr[i];
        count[(arr[i]/exp)%10]--;
    }
    for(int i = 0; i<n; i++)
    {
        arr[i] = output[i];
    }
}
void radixSort(int arr[], int n)
{
    int max = arr[0];
    for( int i = 1; i<n; i++)
    {
        if(arr[i]>max)
        {
            max = arr[i];
        }
    }
    for (int exp = 1; max/exp > 0; exp*=10)
    {
        countingSort(arr,n,exp);
    }
}
void display(int a[], int n)
{
    for(int i = 0 ; i<n; i++)
        cout << a[i] << " ";
    cout << "\n";
}
int main()
{
    int A[] = {525,131,755,112,567,976,111,100,653,322};
    int n = sizeof(A)/sizeof(A[0]);
    display(A,n);
    radixSort(A,n);
    display(A,n);
    return 0;
}