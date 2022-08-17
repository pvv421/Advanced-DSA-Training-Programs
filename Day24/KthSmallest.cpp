/*
Write an efficient program to find the kth smallest element in a given list of elements.

Constraints:
    0<=n<1000
    0<=k<n/2

*/

#include <bits/stdc++.h>
using namespace std;
//using quicksort here
int partition(int arr[], int left, int right)
{
    int x = arr[right];
    int i = left;
    for(int j = left; j<right; j++)
    {
        if(arr[j] <= x)
        {
            swap(arr[i],arr[j]);
            i++;
        }
        swap(arr[i],arr[right]);
    }
    return i;
}

int KthSmallest(int arr[], int left, int right, int k)
{
    if(k > 0 && k<= right - left + 1)
    {
        int position = partition(arr,left,right);
        if(position - left == k-1)
            return arr[position];
        if(position - left > k-1)
            return KthSmallest(arr,left,position-1,k);
        return KthSmallest(arr,position+1, right, k-position+left-1);
    }
    else 
    {
        return INT_MAX;
    }
}

int main()
{
    int n,k;
    cout << "Enter the number of elements: ";
    cin >> n;
    int A[n];
    cout << "\nEnter the elements:\n";
    for(int i = 0; i<n; i++)
    {
        cin >> A[i];
    }
    cout << "\nEnter the K value: ";
    cin >> k;
    int ans = KthSmallest(A,0,n-1,k);
    if(ans != INT_MAX)
        cout << "\nKth smallest element is: "<< ans << "\n";
    else
        cout << "\nElement not present\n";
    return 0;
}
