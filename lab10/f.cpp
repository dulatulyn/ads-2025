#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> createGraph(int n, int m){
    vector<vector<int>> graph(n);
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        u--; v--;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    return graph;
}

bool bfs(const vector<vector<int>>& g, int n, int s, int f){
    vector<int> used(n, 0);
    queue<int> q;
    used[s] = 1;
    q.push(s);
    while(!q.empty()){
        int v = q.front();
        q.pop();
        if(v == f) return true;
        for(int to : g[v]){
            if(!used[to]){
                used[to] = 1;
                q.push(to);
            }
        }
    }
    return false;
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g = createGraph(n, m);
    int a, b;
    cin >> a >> b;
    a--; b--;
    if(bfs(g, n, a, b)) cout << "YES";
    else cout << "NO";
}