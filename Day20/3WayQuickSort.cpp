//working perfectly
#include <bits/stdc++.h>
using namespace std;
int compare(int a, int b)
{
    if(a>b)
        return 1;
    else if(a<b)
        return -1;
    else
        return 0;
}
void quick3WaySort(int a[], int lo, int hi)
{
    if(hi <= lo)
        return;
    int lt = lo, i = lo+1, gt = hi, v = a[lo];
    while(i <= gt)
    {
        int cmp = compare(a[i],v);
        if(cmp < 0)
            swap(a[lt++],a[i++]);
        else if(cmp > 0)
            swap(a[i], a[gt--]);
        else 
            i++;
    }
    quick3WaySort(a,lo,lt-1);
    quick3WaySort(a, gt+1, hi);
}
void display(int a[], int n)
{
    for(int i = 0 ; i<n; i++)
        cout << a[i] << " ";
    cout << "\n";
}
int main()
{
    int A[] = {5,9,0,3,22,2,7,9,5,4,21,0};
    int n = sizeof(A)/sizeof(A[0]);
    display(A,n);
    quick3WaySort(A, 0 , n-1);
    display(A,n);
    return 0;
}