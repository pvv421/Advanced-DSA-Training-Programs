#include <bits/stdc++.h>
using namespace std;
void specialString(string s)
{
    int n = s.length();
    string tempname = "";
    string tempnum = "";
    string ans= "";
    int flag = 0, flag1 = 0;
    for(int i = 1; i<n; i++)
    {
        if(flag == 0)
        {
            if(s[i]!=':')
            {
                tempname = tempname + s[i];
            }
            else
            {
                flag = 1;
            }
        }
        else
        {
            if(s[i]!=',' && s[i]!=')')
            {
                tempnum = tempnum + s[i];
            }
            else
            {
                flag = 0;
                flag1 = 1;
            }
        }
        if(flag1 == 1)
        {
            int sum = 0;
            for(int j = 0; j<tempnum.length(); j++)
            {
                int k = (int)tempnum[j]-48;
                k = k*k;
                sum = sum+k;
            }
            int len = tempname.length();
            if(sum%2 == 0)
            {
                string s1 = tempname.substr(0,2);
                string s2 = tempname.substr(2,len-2);
                string ans = s2+s1;
                cout << ans << " ";
            }
            else
            {
                string s1 = tempname.substr(1,len-1);
                string ans = s1 + tempname[0];
                cout << ans << " ";
            }
            flag1 = 0;
            tempnum = "";
            tempname = "";
            flag = 0;
        }
    }
    cout<<endl;
}
int main()
{
    string s;
    cin >> s;
    specialString(s);
    return 0;
}