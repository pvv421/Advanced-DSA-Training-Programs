//it only works in array size is a power of two
#include <bits/stdc++.h>
using namespace std;
/*void shuffleArray(int A[], int l, int r)
{
    int c = l + (r-l)/2;
    int q = l + l + (c-l)/2;
    if (l == r) 
        return;
    for(int k = l, i = q; i<=c; i++, k++)
    {
        int tmp = A[i];
        A[i] = A[c+k];
        A[c+k] = tmp;
    }
    shuffleArray(A,l,c);
    shuffleArray(A,c+l,r);
}*/

void shuffleArray(int a[], int f, int l)
{
    if (f > l) {
        return;
    }
    if (l - f == 1)
        return;
    int mid = (f + l) / 2;
    int temp = mid + 1;
    int mmid = (f + mid) / 2;
    for (int i = mmid + 1; i <= mid; i++)
        swap(a[i], a[temp++]);
    shuffleArray(a, f, mid);
    shuffleArray(a, mid + 1, l);
}
 
void printArray(int A[], int n)
{
    for(int i = 0; i<n; i++)
    {
        cout << A[i] << " ";
    }
    cout << "\n";
}
/*int main()
{
    int A[] = {1,2,3,4,5,11,22,33,44,55};
    int n = sizeof(A)/sizeof(A[0]);
    printArray(A,n);
    shuffleArray(A,0,n-1);
    printArray(A,n);
    return 0;
}*/

int main()
{
    int A[] = {1,2,3,4,5,6,7,8};
    int n = sizeof(A) / sizeof(A[0]);
    
    printArray(A,n);
    shuffleArray(A, 0, n - 1);
    n = sizeof(A) / sizeof(A[0]);
    printArray(A,n);
    //for (int i = 0; i < n; i++)
        //cout << a[i] << " ";
 
    return 0;
}