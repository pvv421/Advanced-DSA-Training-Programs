// Works if size is 2 power n
#include <bits/stdc++.h>
using namespace std;
int counterfeitcoin(int A[], int n, int l, int h)
{
    if(n == 2)
    {
        if(A[l] == A[h])
        {
            return -1;
        }
    }
    else
    {
        if(A[l]<A[h])
            return A[l];
        else
            return A[h];
    }
    if(n>2)
    {
        return counterfeitcoin(A,n/2,l,(n/2)-1);
        return counterfeitcoin(A,n/2,n/2,h);
    }
    return -1;
}
int main()
{
    int A[] = {2,2,2,2,1,2,2,2};
    int n = sizeof(A)/sizeof(A[0]);
    cout << counterfeitcoin(A,n,0,n-1);
    return 0;
}