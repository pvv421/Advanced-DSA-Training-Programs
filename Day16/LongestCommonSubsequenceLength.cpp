#include <bits/stdc++.h>
using namespace std;
int LCS(string X, string Y)
{
    int m = X.length();
    int n = Y.length();
    int c[m+1][n+1];
    for(int i = 0; i<=m; i++)
    {
        for(int j = 0; j<=n; j++)
        {
            if(i == 0 || j == 0)
            {
                c[i][j] = 0;
            }
            else if(X[i-1] == Y[j-1])
            {
                c[i][j] = c[i-1][j-1] + 1;
            }
            else
            {
                c[i][j] = max(c[i][j-1],c[i-1][j]);
            }
        }
    }
    return c[m][n];
}

int main()
{
    string X = "AGGTAB";
    string Y = "GXTXAYB";
    cout << LCS(X,Y) << "\n";
    return 0;
}