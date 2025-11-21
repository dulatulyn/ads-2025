#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> fillMatrix(int n, int m) {
    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> a[i][j];
    return a;
}

int main() {
    int n, m;
    cin >> n >> m;

    auto g = fillMatrix(n, n);

    for (int i = 0; i < m; i++) {
        int x, y, z;
        cin >> x >> y >> z;

        x--; y--; z--;

        if (g[x][y] == 1 && g[x][z] == 1 && g[y][z] == 1)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}