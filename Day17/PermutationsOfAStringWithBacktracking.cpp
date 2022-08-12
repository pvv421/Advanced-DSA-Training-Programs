#include <bits/stdc++.h>
using namespace std;
void backtrack(string str, int cidx, int n)
{
    if(cidx == n)
        cout << str << "\n";
    else 
    {
        for(int i = cidx; i<=n; i++)
        {
            swap(str[cidx],str[i]);
            backtrack(str, cidx+1, n);
            swap(str[cidx],str[i]);
        }
    }
}
int main()
{
    string s = "ABC";
    int n = s.length();
    backtrack(s,0,n-1);
    return 0;
}