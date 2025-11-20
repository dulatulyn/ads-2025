#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> createGraph(int n, int m){
    vector<vector<int>> g(n);
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        u--; v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    return g;
}

int cntBigFams(const vector<vector<int>>& g, int n){
    vector<int> visited(n, 0);
    vector<int> parent(n, -1);
    vector<int> childCount(n, 0);
    
    int big = 0;

    for(int s = 0; s < n; s++){
        if(visited[s]) continue;

        queue<int> q;
        vector<int> comp;
        
        visited[s] = 1;
        parent[s] = -1;
        
        q.push(s);
        comp.push_back(s);
        big++;

        while(!q.empty()){
            int v = q.front();
            q.pop();
            for(int to : g[v]){
                if(!visited[to]){
                    visited[to] = 1;
                    parent[to] = v;
                    childCount[v]++;

                    q.push(to);
                    comp.push_back(to);
                }
            }
        }

        for(int v : comp){
            if(parent[v] == -1) continue;
            int p = parent[v];
            if(childCount[v] > childCount[p]) big++;
        }
    }

    return big;
}

int main(){
    int n, m;
    cin >> n >> m;

    vector<vector<int>> g = createGraph(n, m);
    cout << cntBigFams(g, n);
}