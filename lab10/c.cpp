#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n, m;
    cin >> n >> m;

    if(n == m){
        cout << 0;
        return 0;
    }

    vector<long long> reverse;
    long long x = m;
    reverse.push_back(x);

    while(x > n){
        if(x % 2 == 1) x++;
        else x /= 2;
        reverse.push_back(x);
    }

    while(x < n){
        x++;
        reverse.push_back(x);
    }

    vector<long long> path(reverse.rbegin(), reverse.rend());

    cout << path.size() - 1 << '\n';
    for(int i = 1; i < path.size(); i++){
        cout << path[i] << " ";
    }
}