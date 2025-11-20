#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> fill(int n, int m) {
    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> a[i][j];
    return a;
}

int bfs(vector<vector<int>>& a, int n, int m) {
    queue<pair<int, int>> q;
    int mushrooms = 0;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            if (a[i][j] == 2) q.push({i, j});
            else if (a[i][j] == 1) mushrooms++;
        }

    if (mushrooms == 0) return 0;
    if (q.empty()) return -1;

    int ops = -1;
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    while (!q.empty()) {
        int sz = q.size();
        ops++;
        while (sz--) {
            auto [x, y] = q.front();
            q.pop();
            for (int k = 0; k < 4; k++) {
                int nx = x + dx[k], ny = y + dy[k];
                if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                if (a[nx][ny] == 1) {
                    a[nx][ny] = 2;
                    mushrooms--;
                    q.push({nx, ny});
                }
            }
        }
    }

    if (mushrooms > 0) return -1;
    return ops;
}

int main() {
    int n, m;
    if (!(cin >> n >> m)) return 0;
    auto field = fill(n, m);
    cout << bfs(field, n, m);
}