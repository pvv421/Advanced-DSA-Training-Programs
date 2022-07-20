/* Given a number, take the digits at odd index, square and concatenate them 
and print the first 4 digits of the concatenated string as otp 
if the length of the string is less than 4, then add zeroes to the otp */
#include <bits/stdc++.h>
using namespace std;
string otpGenerator(string s)
{
    int val;
    int len = s.length(); //getting the length of the string
    string ans = ""; //initialising the answer string
    for(int i = 1; i<len; i = i+2) //iterating over the given string in odd indexes
    {
        val = (int)s[i]-48; //converting char to int
        val = val*val; //squaring the value
        ans = ans + to_string(val); //concatenating the value to the answer string
    }
    if(ans.length()<4) //checking if the length of answer is less than 4 digits
    {
        int spaces = 4-ans.length(); //determining the number of zeroes to be added
        for(int i = 0; i<spaces; i++) //adding the zeroes
        {
            ans = ans + "0";
        }
    }
    return ans.substr(0,4); //returning the first four digits from the answer string
}
int main()
{
    string n;
    cout << "Enter the number:"<<endl;
    cin >> n;
    cout << "OTP is: " << otpGenerator(n) << endl;
    return 0;
}