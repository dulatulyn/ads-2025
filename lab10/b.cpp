#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> fill(int n, int m) {
    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> a[i][j];
    return a;
}

int bfs(vector<vector<int>>& a, int n, int start, int finish) {
    vector<int> dist(n, -1);
    queue<int> q;
    dist[start] = 0;
    q.push(start);

    while (!q.empty()) {
        int v = q.front();
        q.pop();
        if (v == finish) return dist[v];
        for (int u = 0; u < n; u++) {
            if (a[v][u] == 1 && dist[u] == -1) {
                dist[u] = dist[v] + 1;
                q.push(u);
            }
        }
    }
    return -1;
}

int main() {
    int n;
    if (!(cin >> n)) return 0;
    auto g = fill(n, n);
    int s, t;
    cin >> s >> t;
    cout << bfs(g, n, s - 1, t - 1);
}