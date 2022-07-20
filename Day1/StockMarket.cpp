/*
Problem Statement: 
You are given an array/list 'prices' where the elements of the array represent
the prices of the stock as they were yesterday and indices of the array represent minutes.
Your task is to find and return the maximum profit you can make by buying and selling stock.
You can buy and sell the stock only once.

You can't sell without buying first.

For the given array [ 2, 100, 150, 120],
The maximum profit can be achieved by buying the stock at minute 0 when its price is Rs. 2 
and selling it at minute 2 when its price is Rs. 150.
So, the output will be 148.

SAMPLE INPUTS AND OUTPUTS:

i/p: 2, 100, 150, 120
o/p: 148

i/p: 150, 50, 75, 66
o/p: 13

i/p: 4,3,2,1
o/p: 0
*/


#include <bits/stdc++.h>
using namespace std;
// O(n^2) approach:
int maximumProfit(int * arr, int n)
{
    int profit, maxProfit = 0;
    for(int i = 0; i<n; i++)
    {
        for(int j = i+1; j<n; j++)
        {
            if(arr[i]<arr[j])
            {
                profit = arr[j] - arr[i];
                if(profit > maxProfit)
                {
                    maxProfit = profit;
                }
            }
        }
    }
    return maxProfit;
}
// O(n) approach:
int optimisedMaximumProfit(int * arr, int n)
{
    int profit, sellingPrice, maxProfit = 0;
    sellingPrice = arr[0];
    for(int i = 1; i<n; i++)
    {
        if(arr[i] < sellingPrice)
            sellingPrice = arr[i];
        profit = arr[i] - sellingPrice;
        if (profit > maxProfit)
        {
            maxProfit = profit;
        }
    }
    return maxProfit;
}
int main()
{
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i<n; i++)
    {
        cin >> a[i];
    }
    cout << optimisedMaximumProfit(a,n) << endl;
    return 0;
}