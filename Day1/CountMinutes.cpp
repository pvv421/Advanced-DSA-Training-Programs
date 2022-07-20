#include <bits/stdc++.h>
using namespace std;
int countMinutes(string s)
{
    //12:00am-12:00pm
    int ans;
    int hour1, hour2, min1, min2, time1, time2;
    string temp;
    temp = s.substr(0,2);
    hour1 = stoi(temp);
    if(hour1 == 12)
        hour1 = 0;
    temp = s.substr(3,2);
    min1 = stoi(temp);
    temp = s.substr(5,2);
    if(temp == "am") 
        time1 = 1;
    else 
        time1 = 2;
    temp = s.substr(8,2);
    hour2 = stoi(temp);
    if(hour2 == 12)
        hour2 = 0;
    temp = s.substr(11,2);
    min2 = stoi(temp);
    temp = s.substr(13,2);
    if(temp == "am")
        time2 = 1;
    else
        time2 = 2;
    if(time1 == 2)
        hour1 = 12 + hour1;
    if(time2 == 2)
        hour2 = 12 + hour2;
    int totaltime1 = hour1*60 + min1;
    int totaltime2 = hour2*60 + min2;
    if (totaltime2 > totaltime1)
    {
        return totaltime2-totaltime1;
    }
    else
    {
        return 1440-(totaltime1-totaltime2);
    }
}
int main()
{
    string time;
    cin >> time;
    cout << countMinutes(time) << endl; 
    return 0;
}