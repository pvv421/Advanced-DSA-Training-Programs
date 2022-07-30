#include <bits/stdc++.h>
using namespace std;
double prefixEvaluation(string exp)
{
    stack<double> st;
    int n = exp.length();
    for(int i = n-1; i>=0; i--)
    { 
        if(exp[i]>='0' and exp[i]<='9')
        {
            st.push((double)exp[i]-'0');
        }
        else
        {
            double a = st.top();
            st.pop();
            double b = st.top();
            st.pop();
            double c;
            if(exp[i] == '+') c = a+b;
            else if(exp[i] == '-') c = a-b;
            else if(exp[i] == '*') c = a*b;
            else if(exp[i] == '/') c = a/b;
            st.push(c);
        }
    }
    return st.top();
}
int main()
{
    string exp;
    cin >> exp;
    cout << prefixEvaluation(exp)<<"\n";
    return 0;
}