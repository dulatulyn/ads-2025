#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    vector<int> v(t);
    set<int> w;
    for(int i = 0; i < t; i++){
        cin >> v[i];
        w.insert(v[i]);
    }

    int n , m;
    cin >> n >> m;

    unordered_map<int, pair<int, int>> pos;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            int k;
            cin >> k;
            if(w.count(k)){
                pos[k] = {i, j};
            }
        }
    }

    for(int i : v){
        if(pos.count(i)){
            cout << pos[i].first << " " << pos[i].second << endl;
        } else {
            cout << -1 << endl;
        }
    }
    return 0;
}