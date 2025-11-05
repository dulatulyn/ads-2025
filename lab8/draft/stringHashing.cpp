#include <bits/stdc++.h>
using namespace std;

long long hashString(string s){
    const int p = 31;
    const int mod = 1e9 + 7;
    long long hash = 0;
    long long power = 1;

    for(char c : s){
        int value = c - 'a' + 1;
        hash = (hash + value * power) % mod;
        power = (power * p) % mod;
    }
    return hash;
}

vector<long long> prefixHashes(string s){
    const int p = 31;
    const int mod = 1e9 + 7;

    vector<long long> pref;
    long long hash = 0;
    long long power = 1;

    for (char c : s) {
        int value = c - 'a' + 1;
        hash = (hash + value * power) % mod;
        pref.push_back(hash);
        power = (power * p) % mod;
    }
    return pref;
}


int main(){
    string s1; cin >> s1;
    
    vector<long long> v = prefixHashes(s1);
    
    
    for(long long i : v) cout << i << " ";
    
    cout << endl;
    cout << hashString(s1);
}