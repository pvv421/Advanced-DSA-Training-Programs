#include <bits/stdc++.h>
using namespace std;
string findDuplicates(long n)
{
    int mapofnumbers[10];
    for(int i = 0 ; i<10; i++)
    {
        mapofnumbers[i] = 0;
    }
    while(n>0)
    {
        int k = n%10;
        if(mapofnumbers[k] == 0)
            mapofnumbers[k] = 1;
        else
            return "true";
        n = n/10;
    }
    return "false";
}
int main()
{
    long n = 123456770;
    cout << findDuplicates(n) << "\n";
    return 0;
}