#include <bits/stdc++.h>
using namespace std;
void ShellSort(int a[])
{
    int N = sizeof(a)/sizeof(a[0]);
    int h = 1;
    while(h < N/3)
        h = 3*h + 1;
    while(h>=1)
    {
        for(int i = h; i< N; i++)
        {
            int temp = a[i];
            int j;
            for(j = i; j>=h && a[j-h] > temp; j -= h)
                a[j] = a[j-h];
            a[j] = temp;
        }
    }
}

void display(int arr[])
{
    int n = sizeof(arr)/sizeof(arr[0]);
    for(int i = 0; i<n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

int main()
{
    int A[] = {5,0,13,6,9,1,2,4};
    ShellSort(A);
    display(A);
    return 0; 
}