#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
void FindTwoSum(int arr[], int n, int target)
{
    unordered_map<int, int> um;
    for(int i = 0; i<n; i++)
    {
        if(um.find(target-arr[i]) == um.end())
        {
            um[arr[i]] = i;
        }
        else if(um[target-arr[i]]!= i)
        {
            cout << um[target-arr[i]] << " " << i << "\n";
        }
    }
}
int main()
{
    int arr[] = {3,2,4};
    int n = sizeof(arr)/sizeof(arr[0]);
    int target = 6;
    FindTwoSum(arr,n,target);
    return 0;
}
