#include <bits/stdc++.h>
using namespace std;
void push(stack<int> &s1, stack<int> &minimum, int n)
{
    if(s1.empty() && minimum.empty())
    {
        s1.push(n);
        minimum.push(n);
    }
    else
    {
        int min = minimum.top();
        if(n <= min)
        {
            s1.push(n);
            minimum.push(n);
        }
        else
        {
            s1.push(n);
        }
    }
}
void pop(stack<int> &s1, stack<int> &minimum)
{
    if(s1.empty() && minimum.empty())
    {
        cout << "Stack is empty" << endl;
    }
    else
    {
        int n = s1.top();
        if(n <= minimum.top())
        {
            s1.pop();
            minimum.pop();
        }
        else
        {
            s1.pop();
        }
    }
}
void getMinimum(stack<int> &s1, stack<int> &minimum)
{
    if(s1.empty() && minimum.empty())
    {
        cout << "Stack Empty" << endl;
    }
    else
    {
        cout << minimum.top() << endl;
    }
}
int main()
{
    stack<int> s1;
    stack<int> min;
    pop(s1, min);
    push(s1, min, 1);
    push(s1, min, 2);
    push(s1, min, 0);
    getMinimum(s1,min);
    pop(s1, min);
    getMinimum(s1,min);
    pop(s1, min);
    pop(s1, min);
    getMinimum(s1, min);
}