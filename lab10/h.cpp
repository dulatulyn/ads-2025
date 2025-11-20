#include <bits/stdc++.h>
using namespace std;

void bfs(vector<string> &v, int x, int y){ 
    int n = v.size();
    int m = v[0].size();

    queue<pair<int,int>> q;
    q.push({x, y});
    v[x][y] = 2;

    while(!q.empty()){
        int i = q.front().first;
        int j = q.front().second;
        q.pop();

        if(i+1 < n && v[i+1][j] == 49){
            v[i+1][j] = 0;
            q.push({i+1, j});
        }
        if(i-1 >= 0 && v[i-1][j] == 49){
            v[i-1][j] = 0;
            q.push({i-1, j});
        }
        if(j+1 < m && v[i][j+1] == 49){
            v[i][j+1] = 0;
            q.push({i, j+1});
        }
        if(j-1 >= 0 && v[i][j-1] == 49){
            v[i][j-1] = 0;
            q.push({i, j-1});
        }
    }
}


int main(){
    int n, m;
    cin >> n >> m;
    vector<string> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    int cnt = 0;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(v[i][j] == 49){
                cnt++;
                bfs(v, i, j);
            }
        }
    }
    cout << cnt;
}