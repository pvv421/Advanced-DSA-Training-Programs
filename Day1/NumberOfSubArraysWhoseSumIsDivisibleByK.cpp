/* Given an array and an integer K. find the count of subarrays of the given array whose sum is divisible by K */
#include <bits/stdc++.h>
using namespace std;
int countSubArray(int * arr, int n, int value)
{
    int count = 0;
    for(int i = 0; i<n; i++)
    {
        for(int j = i; j<n; j++)
        {
            int sum = 0;
            for(int k = i; k<=j; k++)
            {
                sum = sum + arr[k];
            }
            if(sum%value == 0)
                count++;
        }
    }
    return count;
}
int main()
{
    int a[] = {5,0,2,3,1};
    int n = sizeof(a)/sizeof(a[0]);
    int k = 5;
    cout << countSubArray(a,n,k) << endl;
    return 0;
}
