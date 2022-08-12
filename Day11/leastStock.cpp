#include <bits/stdc++.h>
using namespace std;
int stocks(int input1, int input2[])
{
    int initialprice = input2[0];
    int min = initialprice;
    for(int i = 1; i<input1; i++)
    {
        initialprice = initialprice+input2[i];
        if(initialprice < min)
            min = initialprice;
    }
    return min;
}
int main()
{
    int arr[5] = {-39957,-17136,35466,21820,-26711};
    cout << stocks(5,arr);
    return 0;
}