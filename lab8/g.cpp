#include <bits/stdc++.h>
using namespace std;

string s;

string slicing(int ind1, int ind2) {
    if (ind1 < 0) ind1 = 0;
    if (ind2 >= s.size()) ind2 = s.size() - 1;
    if (ind1 > ind2) return "";
    return s.substr(ind1, ind2 - ind1 + 1);
}

int countOccurrences(const string& pattern) {
    const long long p1 = 31, mod1 = 1e9 + 7;
    const long long p2 = 37, mod2 = 1e9 + 9;
    int n = s.size(), m = pattern.size();
    if (m > n) return 0;
    
    vector<long long> power1(n), power2(n);
    power1[0] = power2[0] = 1;
    for (int i = 1; i < n; i++) {
        power1[i] = (power1[i - 1] * p1) % mod1;
        power2[i] = (power2[i - 1] * p2) % mod2;
    }
    
    vector<long long> pref1(n + 1, 0), pref2(n + 1, 0);
    for (int i = 0; i < n; i++) {
        int value = s[i] - 'a' + 1;
        pref1[i + 1] = (pref1[i] + value * power1[i]) % mod1;
        pref2[i + 1] = (pref2[i] + value * power2[i]) % mod2;
    }
    
    long long hash_pattern1 = 0, hash_pattern2 = 0;
    for (int i = 0; i < m; i++) {
        int value = pattern[i] - 'a' + 1;
        hash_pattern1 = (hash_pattern1 + value * power1[i]) % mod1;
        hash_pattern2 = (hash_pattern2 + value * power2[i]) % mod2;
    }
    
    int count = 0;
    for (int i = 0; i + m - 1 < n; i++) {
        long long cur1 = (pref1[i + m] - pref1[i] + mod1) % mod1;
        long long target1 = (hash_pattern1 * power1[i]) % mod1;
        
        long long cur2 = (pref2[i + m] - pref2[i] + mod2) % mod2;
        long long target2 = (hash_pattern2 * power2[i]) % mod2;
        
        if (cur1 == target1 && cur2 == target2)
            count++;
    }
    
    return count;
}

int main() {
    cin >> s;
    
    int q; cin >> q;
    
    for(int i = 0; i < q; i++) {
        int l, r; cin >> l >> r;
        string pattern = slicing(l - 1, r - 1);
        cout << countOccurrences(pattern) << endl;
    }
}