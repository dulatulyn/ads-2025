#include <bits/stdc++.h>
using namespace std;

string prefixHashes(vector<long long> pref) {
    const long long p = 2;
    const long long mod = 2e18;

    string s = "";
    long long power = 1;

    for (int i = 0; i < pref.size(); i++) {
        long long hash = pref[i];
        
        long long hash_prev;
        if (i == 0) hash_prev = 0;
        else hash_prev = pref[i - 1];

        long long diff = (hash - hash_prev + mod) % mod;
        
        long long value = diff / power; 

        char c = 'a' + value;
        s += c;

        power = (power * p) % mod;
    }

    return s;
}

int main(){
    int n; cin >> n;
    vector<long long> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    cout << prefixHashes(v);
}