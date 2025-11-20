#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int>> edges;

vector<vector<int>> createGraph(int n, int m){
    vector<vector<int>> graph(n);
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        u--; v--;
        graph[u].push_back(v);
        edges.push_back({u, v});
    }
    return graph;
}

bool dfs(int v, const vector<vector<int>>& g, vector<int>& color, int skipU, int skipV){
    color[v] = 1;
    for(int to : g[v]){
        if(v == skipU && to == skipV) continue;
        if(color[to] == 0){
            if(dfs(to, g, color, skipU, skipV)) return true;
        }else if(color[to] == 1){
            return true;
        }
    }
    color[v] = 2;
    return false;
}

bool hasCycle(const vector<vector<int>>& g, int n, int skipIndex){
    int skipU = -1, skipV = -1;
    if(skipIndex != -1){
        skipU = edges[skipIndex].first;
        skipV = edges[skipIndex].second;
    }
    vector<int> color(n, 0);
    for(int i = 0; i < n; i++){
        if(color[i] == 0){
            if(dfs(i, g, color, skipU, skipV)) return true;
        }
    }
    return false;
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g = createGraph(n, m);

    bool ok = false;
    for(int i = 0; i < m; i++){
        if(!hasCycle(g, n, i)){
            ok = true;
            break;
        }
    }

    if(ok) cout << "YES";
    else cout << "NO";
}
