#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> createGraph(int n, int m){
    vector<vector<int>> graph(n);
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        u--; v--;
        graph[u].push_back(v);
    }
    return graph;
}

void printGraph(const vector<vector<int>>& graph){
    for(int i = 0; i < (int)graph.size(); i++){
        cout << i << ":";
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
    
    priority_queue<int, vector<int>, greater<int>> q; 
    for(int i = 0; i < n; i++){
        if(indeg[i] == 0){
            q.push(i);
        }
    }
    
    vector<int> result;
    while(!q.empty()){
        int u = q.top();
        q.pop();
        result.push_back(u);
        for(int v : g[u]){
            indeg[v]--;
            if(indeg[v] == 0){
                q.push(v);
            }
        }
    }
    
    if((int)result.size() != n){
        return {};
    }
    return result;
}


int main(){
    int n, m;
    cin >> n >> m;

    vector<vector<int>> g = createGraph(n, m);
    vector<int> res = topologicalSort(g);
    
    if(res.size() != 0){
        cout << "Possible\n";
        for(int x : res) cout << x + 1 << " ";
    }
    else {
        cout << "Impossible";
    }
}