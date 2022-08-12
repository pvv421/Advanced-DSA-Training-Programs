/* Serling Enterprises buys long steel rods and cuts them into shorter rods, 
which it then sells. Each cut is free. The management of Serling Enterprises 
wants to know the best way to cut up the rods.  */

#include <bits/stdc++.h>
using namespace std;

int max(int a, int b){ return (a>b)?a:b;}

int memoizedCutRodAux(int p[],int n,int r[])  //top down approach
{
    if(r[n] >= 0)
    {
        return r[n];
    }
    int q;
    if(n==0)
    {
        q = 0;
    }
    else
    {
        q = INT_MIN;
        for(int i = 0; i<n; i++)
        {
            q = max(q,p[i]+memoizedCutRodAux(p,n-i-1,r));
        }
    }
    r[n] = q;
    return q;
}

int memoizedCutRod(int price[], int n)
{
    int r[n+1];
    for(int i = 0; i<n+1; i++)
    {
        r[i] = INT_MIN;
    }
    return memoizedCutRodAux(price, n, r);
}

int bottomUpCutRod(int p[], int n) // bottom up approach
{
    int r[n+1];
    int q;
    r[0] = 0;
    for (int j = 1; j <= n; j++)
    {
        q = INT_MIN;
        for (int i = 0; i < j; i++)
        {
            q = max(q,p[i]+r[j-i-1]);
        }
        r[j] = q;
    }
    return r[n];
}

int main()
{
    int arr[] = {1,5,8,9,10,17,17,20,24,30};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << memoizedCutRod(arr,n) << "\n";
    cout << bottomUpCutRod(arr,n) << "\n";
    return 0;
}