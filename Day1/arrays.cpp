#include <bits/stdc++.h>
using namespace std;
void displayOddSum(int * arr, int n)
{
    int sum = 0;
    for(int i = 0; i<n;i++)
    {
        sum = sum + arr[i];
        if(sum%2!=0)
        {
            cout << arr[i] << " ";
        }
        else
        {
            sum = sum - arr[i];
        }
    }
    cout<<endl;
}
void displayEvenSum(int * arr, int n)
{
    int sum = 0;
    for(int i = 0; i<n; i++)
    {
        if(arr[i]%2 == 0)
        {
            sum = sum+arr[i];
        }
    }
    cout << "The sum of even elements is: " << sum << endl;
}
void displayMiddleElement(int * arr1, int * arr2, int n1, int n2)
{
    int n = n1+n2;
    int index = 0;
    int output[n];
    int index1 = 0;
    int index2 = 0;
    while((index1!=n1) && (index2!=n2))
    {
        if(arr1[index1]<arr2[index2])
        {
            output[index] = arr1[index1];
            index1++;
            index++;
        }
        else
        {
            output[index] = arr2[index2];
            index2++;
            index++;
        }
    }
    if(index1 != n1)
    {
        while(index1!=n1)
        {
            output[index] = arr1[index1];
            index1++;
            index++;
        }
    }
    else
    {
        while(index2!=n2)
        {
            output[index] = arr2[index2];
            index2++;
            index++;
        }
    }
    /*for(int i = 0; i<n; i++) // code to print the array
    {
        cout << output[i] << " ";
    }
    cout<<endl;*/
    cout << output[n/2]<< endl;
}
void displayMiddleEle(int * arr1, int * arr2, int n1, int n2)
{
    int ele;
    int n = n1+n2;
    int index = 0;
    int index1 = 0;
    int index2 = 0;
    while((index1!=n1) && (index2!=n2) && index!=((n/2)+1))
    {
        if(arr1[index1]<arr2[index2])
        {
            ele = arr1[index1];
            index1++;
            index++;
        }
        else
        {
            ele = arr2[index2];
            index2++;
            index++;
        }
    }
    if(index == ((n/2)+1))
    {
        cout << ele;
        return;
    }
    else if(index1 != n1)
    {
        while(index1!=n1 && index!=((n/2)+1))
        {
            ele = arr1[index1];
            index1++;
            index++;
        }
        cout << ele;
        return;
    }
    else
    {
        while(index2!=n2 && index!=((n/2)+1))
        {
            ele = arr2[index2];
            index2++;
            index++;
        }
        cout << ele;
        return;
    }
}
int avgOfArray(int * arr, int n)
{
    float avg;
    int sum = 0;
    for(int i = 0; i<n; i++)
    {
        sum = sum+arr[i];
    }
    avg = (float)sum/n;
    return avg;
}
void positiveNegativeSort(int * arr, int n)
{
    int output[n];
    int index = 0;
    for(int i = 0; i<n; i++)
    {
        if(arr[i]<0)
        {
            output[index] = arr[i];
            index++;
        }
    }
    for(int i = 0; i<n; i++)
    {
        if(arr[i]>=0)
        {
            output[index] = arr[i];
            index++;
        }
    }
    for(int i = 0; i<n; i++)
    {
        cout << output[i] << " "; 
    }
    cout<<endl;
}
void positiveNegativeSort2(int * arr, int n)
{
    for(int i = 0; i< n; i++)
    {
        for(int j = 0; j<n; j++)
        {
            if(arr[i]<0 && arr[j]>=0)
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}
int unique(int a, int * arr, int n)
{
    int count = 0;
    for(int i = 0; i<n; i++)
    {
        if (arr[i] == a)
        count++;
    }
    if(count == 1)
        return 1;
    else
        return 0;
}
void printUniqueElements(int * arr, int n)
{
    for(int i = 0; i<n; i++)
    {
        if(unique(arr[i],arr,n)==1)
        {
            cout << arr[i] << " ";
        }
    }
}
/*int countMinutes(string s)
{
    //12:00am-12:00pm
    int ans;
    int hour1, hour2, min1, min2, time1, time2;
    string temp;
    temp = s[0]+s[1];
    hour1 = stoi(temp);
    temp = s[3]+s[4];
    min1 = stoi(temp);
    temp = s[5]+s[6];
    if(temp == "am")
        time1 = 1;
    else 
        time1 = 2;
    temp = s[8]+s[9];
    hour2 = stoi(temp);
    temp = s[11]+s[12];
    min2 = stoi(temp);
    temp = s[13]+s[14];
    if(temp == "am")
        time2 = 1;
    else
        time2 = 2;
    if(time1 == 2)
        hour1 = hour1 + 12;
    if(time2 == 2)
        hour2 = hour2 + 12;
    if(hour1<hour2)
    {
        int hourdiff = hour2-hour1;
        int hourmins = hourdiff*60;
        int mindiff;
        if(min1<min2)
            mindiff = min2-min1;
        else


    }
    return "hello";
}*/
int main()
{
    /*int n1,n2;
    cin>>n1>>n2;
    int a1[n1], a2[n2];
    for(int i = 0; i<n1; i++)
    cin >> a1[i];
    for(int i = 0; i<n2; i++)
    cin >> a2[i];
    displayMiddleElement(a1,a2,n1,n2);
    cout<<endl<<endl;
    displayMiddleEle(a1,a2,n1,n2);
    cout<<endl;*/
    //int n;
    //cin >> n;
    //int a[n];
    //for(int i = 0; i<n; i++)
    //cin >> a[i];
    /*positiveNegativeSort(a,n);
    cout<<endl;
    cout<< "Printing the same array: "<<endl;
    for(int i = 0; i<n; i++)
    cout << a[i] << " ";
    cout << endl;
    positiveNegativeSort2(a,n);
    cout<< "Printing the same array after rearranging: "<<endl;
    for(int i = 0; i<n; i++)
    cout << a[i] << " ";
    cout << endl;*/
    //printUniqueElements(a,n);
    //cout<<endl;
    string s = "01";
    int a = stoi(s);
    cout << a;
    return 0;
}
//1 2 3 4 5 6 7 8 10 12 14 16 99
//1 2 3 4 5 6 7
//1 2 3 4 5 6 7 8 10 12 14 16 99