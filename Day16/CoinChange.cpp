#include <bits/stdc++.h>
using namespace std;
int CoinChange(int denomination[], int n, int change)
{
    int table[change+1];
    table[0] = 0;
    for(int i = 1; i<=change; i++)
    {
        table[i] = INT_MAX;
    }
    for(int i = 1; i<=change; i++)
    {
        for(int j = 0; j<n; j++)
        {
            if(denomination[j]<=i)
            {
                int sub = table[i-denomination[j]];
                if(sub != INT_MAX && sub+1<table[i])
                    table[i] = sub+1;
            }
        }
    }
    if(table[change] == INT_MAX)
        return table[change-1];
    else
        return table[change];
}

int main()
{

}