#include <bits/stdc++.h>
using namespace std;
void SelectionSort(int arr[], int n)
{
    if(n == 0)
        return;
    else
    {
        for(int i = n-2; i>=0; i--)
        {
            if (arr[i] > arr[n-1])
            {
                int temp = arr[i];
                arr[i] = arr[n-1];
                arr[n-1] = temp;
            } 
        }
        SelectionSort(arr,n-1);
    }
}
int main()
{
    int arr[5] = {1,99,22,31,0};
    SelectionSort(arr,5);
    for(int i = 0; i<5; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
    return 0;
}