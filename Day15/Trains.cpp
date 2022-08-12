#include <bits/stdc++.h>
using namespace std;
int findPlatform(int arr[], int dep[], int n)
{
    sort(arr, arr + n);
    sort(dep, dep + n);
    int plat_needed = 1, result = 1;
    int i = 1, j = 0;
 
    while (i < n && j < n) {
        if (arr[i] <= dep[j]) {
            plat_needed++;
            i++;
        }
        else if (arr[i] > dep[j]) {
            plat_needed--;
            j++;
        }
        if (plat_needed > result)
            result = plat_needed;
    }
 
    return result;
}

int main()
{
    int arr[] = { 900, 915, 1030, 1045 , 1050, 1150};
    int dep[] = { 930, 1300, 1100, 1145, 1130, 1200};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << findPlatform(arr, dep, n);
    return 0;
}