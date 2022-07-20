#include <bits/stdc++.h>
using namespace std;
int fun(int *  arr, int n)
{
    string s = "";
    int sum = 0;
    int flag = 0;
    for(int i = 0; i<n; i++)
    {
        if(arr[i] == 4)
        {
            flag = 1;
        }
        if(flag == 0)
        {
            sum = sum + arr[i];
        }
        else
        {
            s = s + to_string(arr[i]);
        }
        if(arr[i] == 7)
        {
            flag = 0;
        }
    }
    int ans = sum + stoi(s);
    return ans;
}
int main()
{
    int arr[] = {1,2,3,4,5,6,7,8,9};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << fun(arr,n) << endl;
    return 0;
}