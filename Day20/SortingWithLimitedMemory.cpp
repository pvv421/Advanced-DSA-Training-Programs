//not working. still a work in progress
#include <bits/stdc++.h>
using namespace std;
void display(int a[], int n)
{
    for(int i = 0; i<n; i++)
        cout << a[i] << " ";
    cout << "\n-------\n";
}
void display2(vector<int> &a, int n)
{
    for(int i = 0; i<n; i++)
        cout << a[i] << " ";
    cout << "\n-------\n";
}
void LimitedMemorySort(int arr[], int n)
{
    int k = n/10;
    int ram[k];
    int i= 0;
    while(i<n)
    {
        for(int j = 0; j<k; j++)
        {
            ram[j] = arr[i];
            i+=1;
        }
        sort(ram,ram+k);
        i = i-10;
        for(int j = 0; j<k; j++)
        {
            arr[i] = ram[j];
            i+=1;
        }
    }
   /* vector<int> ans;
    i = 0;
    while(i<n)
    {
        for(int j = 0; j<k; j++)
        {
            ram[j] = arr[i];
            i = i+k;
        }
        sort(ram,ram+k);
        for(int j = 0; j<k; j++)
        {
            ans.push_back(ram[j]);
        }
        i = i-(n-k-1);
    }
    return ans; */
}
int main()
{
    int n;
    cin >> n;
    int A[n];
    for(int i = 0; i<n; i++)
    {
        cin >> A[i];
    }
    display(A,n);
    LimitedMemorySort(A,n);
    display(A,n);
    return 0;
}
