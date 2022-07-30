#include <bits/stdc++.h>
using namespace std;
int MinimumCoins(int coins[], int n, int amount)
{
    if (amount == 0) return 0;
    int ans = INT_MAX;
    for(int i = 0; i<n; i++)
    {
        if(coins[i]<=amount)
        {
            int ans2 = MinimumCoins(coins, n, amount-coins[i]);
            if(ans2!= INT_MAX && ans2+1 < ans)
            {
                ans = ans2 + 1;
            }
        }
    }
    return ans;
}
int main()
{
    int arr[4] = {1,5,9,6};
    int amount = 11;
    cout << MinimumCoins(arr,4,amount) << "\n";
    return 0;
}