#include <bits/stdc++.h>
using namespace std;
void calculateSpan(int price[], int n, int S[])
{
    stack<int> st;
    st.push(0); 
    S[0] = 1;
    for(int i = 1; i<n; i++)
    {
        while(!st.empty() && price[st.top()]<price[i])
            st.pop();
    S[i] = (st.empty()) ? (i+1) : (i - st.top());
    st.push(i);
    }
}
int main()
{
    int prices[6] = {7,2,5,8,6,9};
    int S[6];
    calculateSpan(prices, 6, S);
    for(int i = 0; i<6; i++)
    {
        cout << S[i] << " ";
    }
    cout << endl;
    return 0;

}