#include <bits/stdc++.h>
#define row 6
#define col 7
using namespace std;
 
int vis[row + 1][col + 1], id;
int diameter = 0, length = 0;
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

void dfs(int a, int b, int lis[][col], int& x, int& y)
{
    vis[a][b] = id;
    length++;
    if (length > diameter) {
        x = a;
        y = b;
        diameter = length;
    }
    for (int j = 0; j < 4; j++) {
        int cx = a + dx[j];
        int cy = b + dy[j];
        if (cx < 0 || cy < 0 || cx >= row || cy >= col || lis[cx][cy] == 0 || vis[cx][cy]) {
            continue;
        }
        dfs(cx, cy, lis, x, y);
    }
    vis[a][b] = 0;
    length--;
}
void findMaximumLength(int lis[][col])
{
    int x, y;
    id++;
    length = 0;
    diameter = 0;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (lis[i][j] != 0) {
                dfs(i, j, lis, x, y);
                i = row;
                break;
            }
        }
    }
    id++;
    length = 0;
    diameter = 0;
    dfs(x, y, lis, x, y);
    cout << diameter;
}

int main()
{
    int grid[][col] = { { 0, 0, 0, 0, 0, 0, 0 },
                        { 0, 1, 0, 1, 0, 0, 0 },
                        { 0, 1, 0, 1, 0, 0, 0 },
                        { 0, 1, 0, 1, 0, 1, 0 },
                        { 0, 1, 1, 1, 1, 1, 0 },
                        { 0, 0, 0, 1, 0, 0, 0 } };
    findMaximumLength(grid);
 
    return 0;
}