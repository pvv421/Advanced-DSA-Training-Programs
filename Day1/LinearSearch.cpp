#include <bits/stdc++.h>
using namespace std;
int linearSearch(int * arr, int n, int value)
{
    int index = -1; //initialise the index
    for(int i = 0; i<n; i++) //iterate ove the array from the start
    {
        if(arr[i] == value) 
        {
            index = i; //if the value matches, then set the index and break the loop
            break;
        }
    }
    return index; //return the index
}
int main()
{
    int n,s;
    cout << "Enter the number of elements: "<< endl;
    cin >> n;
    int a[n];
    cout << "Enter the elements: "<< endl;
    for(int i = 0; i<n; i++)
    cin >> a[i];
    cout << "Enter the element to be searched" << endl;
    cin >> s;
    int index = linearSearch(a,n,s);
    if(index == -1)
    {
        cout << "Element not in the array" << endl;
    }
    else 
    {
        cout << "The element is at the index " << index << endl;
    }
    return 0;
}