/*  Given a string with names and numbers, take one name and one number each.
    if the length of the name is a digit in the number, then add that character to the output.
    if there is no digit matching the length but a digit exists that is less than length, then add 
    the character that is at the position of the highest digit for such case.
    if the above two cases don't exist, then add X to the output.
Sample input: (Abhishek:43848,Mayur:3749,Friends:3949,Yeah:7878)
Sample output: kueX */
#include <bits/stdc++.h>
using namespace std;
string specialString(string s)
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
            int templen = tempname.length();
            int key  = -1;
            for(int j = 0;j<tempnum.length();j++)
            {
                int a = (int)tempnum[j]-48;
                if(a<=templen && a>key)
                {
                    key = a;
                }
            }
            if(key == -1)
            {
                ans = ans+"X";
            }
            else
            {
                ans = ans + tempname[key-1];
            }
            flag1 = 0;
            tempnum = "";
            tempname = "";
            flag = 0;
        }
    }
    return ans;
}
int main()
{
    string s;
    cin >> s;
    cout << specialString(s) << endl;
    return 0;
}