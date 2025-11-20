#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> createGraph(int n, int m){
    vector<vector<int>> graph(n);
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
    }
    return graph;
}

void printGraph(const vector<vector<int>>& graph){
    for(int i = 0; i < (int)rgaph.size(); i++){
        cout << i << ":"
        for(int v : graph[i]){
            cout << v << " ";
        } 
        cout << endl;
    }
}

vector<int> topologicalSort(vector<vector<int>>& g){
    int n = g.size();
    vector<int> indeg(n, 0);

    for(int i = 0; i < n; i++){
        for(int v : g[i]){
            indeg[v]++;
        }
    }

    queue<int> q;
    for(int i = 0; i < n; i++){
        if(indeg[i] == 0){
            q.push(i);
        }
    }

    vector<int> res;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        res.push_back(u);

        for(int v : g[u]){
            indeg[v]--;
            if(indeg[v] == 0){
                q.push(v);
            }
        }

        if(res.size() != n){
            return {};
        }

        return res;
    }
}

int main(){
    int n, m;
    cin >> n >> m;

    vector<vector<int>> g = createGraph(n, m);
    printGraph(g);
}