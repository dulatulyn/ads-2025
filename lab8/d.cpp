#include <bits/stdc++.h>
using namespace std;

int countOccurrences(const string& text, const string& pattern) {
    const long long p = 31;
    const long long mod = 1e9 + 7;
    int n = text.size(), m = pattern.size();

    if (m > n) return 0;

    vector<long long> power(n);
    power[0] = 1;
    for (int i = 1; i < n; i++)
        power[i] = (power[i - 1] * p) % mod;

    vector<long long> pref(n + 1, 0);
    for (int i = 0; i < n; i++) {
        int value = text[i] - 'a' + 1;
        pref[i + 1] = (pref[i] + value * power[i]) % mod;
    }
    
    long long hash_pattern = 0;
    for (int i = 0; i < m; i++) {
        int value = pattern[i] - 'a' + 1;
        hash_pattern = (hash_pattern + value * power[i]) % mod;
    }

    int count = 0;
    for (int i = 0; i + m - 1 < n; i++) {
        long long cur = (pref[i + m] - pref[i] + mod) % mod;
        if (cur == (hash_pattern * power[i]) % mod)
            count++;
    }

    return count;
}

int main() {
    int n;
    
    while(cin >> n){
        if(n == 0) break;
        vector<string> v(n);
        
        for(int i = 0; i < n; i++){
            cin >> v[i];
        }
        string text; cin >> text;
        
        vector<pair<string, int>> ans;
        int max_cnt = INT_MIN;
        
        for(string pattern : v){
            int cnt = countOccurrences(text, pattern);
            ans.push_back({pattern, cnt});
            max_cnt = max(max_cnt, cnt); 
        }
        cout << max_cnt << endl;
        for(pair<string, int> it : ans){
        if(it.second == max_cnt) cout << it.first << endl;
        }   
    }
}