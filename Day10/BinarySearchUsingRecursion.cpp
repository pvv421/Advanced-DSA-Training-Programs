#include <bits/stdc++.h>
using namespace std;
int BinarySearch(int arr[], int left, int right, int search)
{
    if(right >= left)
    { 
        int mid = (left+right)/2;
        if(arr[mid] == search)
            return mid;
        else if(search < arr[mid])
            return BinarySearch(arr,left,mid-1,search);
        else
            return BinarySearch(arr,mid+1,right,search);
    }
    return -1;
}
int main()
{
    int arr[10] = {0,1,2,3,4,5,6,7,8,9};
    int n = sizeof(arr)/sizeof(arr[0]);
    int left = 0;
    int right = n-1;
    int search = 66;
    int ans = BinarySearch(arr,left,right, search);
    if(ans!= -1)
        cout << "Found at index " << ans << "\n";
    else
        cout <<"Not Found" << "\n";
    return 0;
}