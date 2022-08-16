#include <bits/stdc++.h>
using namespace std;
void sortArray(int arr[], int n)
{
    for(int i = 0; i<n; i++)
    {
        for(int j = i+1; j<n; j++)
        {
            if(arr[j]<arr[i])
            {
                int temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
        }
    }
}
void display(int arr[], int n)
{
    for(int i = 0; i<n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
}
int main()
{
    int A[] = {100,999,678,364,411,789,564,116,220,822};
    int n = sizeof(A)/sizeof(A[0]);
    display(A,n);
    sortArray(A,n);
    display(A,n);
    return 0;
}