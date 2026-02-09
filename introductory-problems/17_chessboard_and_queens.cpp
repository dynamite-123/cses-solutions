#include <bits/stdc++.h>
using namespace std;

char grid[8][8];
int col[8], diag1[15], diag2[15];

int dfs(int r) {
    if (r == 8)
        return 1;

    int ways = 0;
    for (int c = 0; c < 8; c++) {
        if (grid[r][c] == '*')
            continue;
        if (col[c])
            continue;
        if (diag1[r - c + 7])
            continue;
        if (diag2[r + c])
            continue;

        col[c] = diag1[r - c + 7] = diag2[r + c] = 1;
        ways += dfs(r + 1);
        col[c] = diag1[r - c + 7] = diag2[r + c] = 0;
    }
    return ways;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
            cin >> grid[i][j];

    cout << dfs(0) << "\n";
    return 0;
}
