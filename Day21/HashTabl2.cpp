#include <bits/stdc++.h>
using namespace std;
long findAndRemoveDuplicates(long n)
{
    int mapofnumbers[10];
    for(int i = 0 ; i<10; i++)
    {
        mapofnumbers[i] = 0;
    }
    long ans = 0;
    while(n>0)
    {
        int k = n%10;
        if(mapofnumbers[k] == 0)
        {
            mapofnumbers[k] = 1;
            ans = (ans*10)+k;
        }
        n = n/10;
    }
    int ans2 = 0;
    while(ans!=0)
    {
        int rem = ans%10;
        ans2 = (ans2*10)+rem;
        ans = ans/10;
    }
    return ans2;
}
int main()
{
    long n = 532625317;
    //expected output is 625317
    cout << findAndRemoveDuplicates(n) << "\n";
    return 0;
}