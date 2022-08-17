/* 
Input: a[n, n], a two dimensional array containing n rows and n columns,
       where n is a power of 2. ‘item’, which is to be searched in the 
       above array.

Output: The algorithm prints “Found”, when the element (item) is found in the
        array otherwise it prints “Not Found”.

Condition: The given array is sorted such that an element in a particular column
           in ith row is less than the element in that column in the jth row, where 
           j > i. In addition, an element in the ith column of a particular row is 
           less than the item in the jth column of the same row if j > i.
            1<=n,m<=100
*/
#include <bits/stdc++.h>
using namespace std;
//Regular binary search for a 1D array
int BinarySearch(vector<int> &A, int low, int high, int search)
{
    if(high >= low)
    { 
        int mid = (low+high)/2;
        if(A[mid] == search)
            return mid;
        else if(search < A[mid])
            return BinarySearch(A,low,mid-1,search);
        else
            return BinarySearch(A,mid+1,high,search);
    }
    return -1;
}

//Binary Search for 2D sorted array
void BinarySearch2D(vector<vector<int> > &A,int n, int m, int low, int high, int search)
{
    if(high >= low)
    {
        int mid = (low+high)/2;
        int mid2 = m/2;
        if(BinarySearch(A[mid],0,m-1,search) != -1) //searches for the element in middle row
            cout << "Found" << "\n";
        else if(search < A[mid][mid2])
            return BinarySearch2D(A,n,m,low,mid-1,search);
        else
            return BinarySearch2D(A,n,m,mid+1,high,search);
    }
    else
        cout << "Not Found" << "\n";
}

int main()
{
    vector<vector<int> > A;
    int n,m;
    cout << "\nEnter n value(rows): ";
    cin >> n;
    cout << "\nEnter m value(columns): ";
    cin >> m;
    for(int i = 0; i<n; i++)
    {
        cout << "\nEnter elements of row"<<i+1<<" :\n";
        vector<int> Row;
        int element;
        for(int j = 0; j<m; j++)
        {
            cin >> element;
            Row.push_back(element);
        }
        A.push_back(Row);
    }
    int search;
    cout << "\nEnter the element to be searched: \n";
    cin >> search;
    BinarySearch2D(A,n,m,0,n-1,search);
    return 0;
}