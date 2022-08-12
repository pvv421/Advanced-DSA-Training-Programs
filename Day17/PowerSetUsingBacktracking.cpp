//not working
#include <bits/stdc++.h>
using namespace std;
void Find(int arr[],int sub[],int p)
{
    int n = sizeof(arr)/sizeof(arr[0]);
    if(p == n)
    {
        string s = "";
        for(int i = 0; i<n; i++)
        {
            if(sub[i]!=0)
            {
                s = s+to_string(sub[i]);
            }
        }
        cout << s << "\n";
    }
    else 
    {
        sub[p] = 0;
        Find(arr,sub,p+1);
        sub[p] = arr[p];
        Find(arr,sub,p+1);
    }
}
int main()
{
    int a[] = {1,2,3};
    int sub[3];
    Find(a,sub,0);
    return 0;
}