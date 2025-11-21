#include <bits/stdc++.h>
using namespace std;

vector<pair<int, vector<int>>> createGraph(int n, int m){
    vector<pair<int,  vector<int>>> graph(n, {0, {}});
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        u--; v--;
        graph[u].second.push_back(v);
        graph[v].second.push_back(u);
    }
    return graph;
}

void changeColor(vector<pair<int, vector<int>>>& v, int n){
    if(n >= 0 && n < v.size()) v[n].first = 1;
}

int findClosestOne(vector<pair<int, vector<int>>>& graph, int start) {
    int n = graph.size();
    vector<int> visited(n, 0);
    queue<pair<int,int>> q;
    q.push({start, 0});
    visited[start] = 1;

    while (!q.empty()) {
        auto [u, dist] = q.front();
        q.pop();

        if (graph[u].first == 1)
            return dist;

        for (int v : graph[u].second) {
            if (!visited[v]) {
                visited[v] = 1;
                q.push({v, dist + 1});
            }
        }
    }

    return -1;
}

int main(){
    int n, m, q;
    cin >> n >> m >> q;

    vector<pair<int, vector<int>>> v = createGraph(n, m);
    
    for(int i = 0; i < q; i++){
        int op, start;
        cin >> op >> start;
        start--;
        if(op == 1) changeColor(v, start);
        else cout << findClosestOne(v, start) << "\n"; 
    }
}