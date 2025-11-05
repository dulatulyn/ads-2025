#include <bits/stdc++.h>
using namespace std;

int countOccurrences(const string& text1, const string& text2, const string& pattern) {
    const long long p = 31;
    const long long mod = 1e9 + 7;
    int n = text1.size(), m = pattern.size();

    if (m > n) return 0;

    vector<long long> power(n);
    power[0] = 1;
    for (int i = 1; i < n; i++)
        power[i] = (power[i - 1] * p) % mod;

    vector<long long> pref1(n + 1, 0);
    for (int i = 0; i < n; i++) {
        int value = text1[i] - 'a' + 1;
        pref1[i + 1] = (pref1[i] + value * power[i]) % mod;
    }
    vector<long long> pref2(n + 1, 0);
    for (int i = 0; i < n; i++) {
        int value = text2[i] - 'a' + 1;
        pref2[i + 1] = (pref2[i] + value * power[i]) % mod;
    }
    
    long long hash_pattern = 0;
    for (int i = 0; i < m; i++) {
        int value = pattern[i] - 'a' + 1;
        hash_pattern = (hash_pattern + value * power[i]) % mod;
    }

    int count = 0;
    for (int i = 0; i + m - 1 < n; i++) {
        long long cur1 = (pref1[i + m] - pref1[i] + mod) % mod;
        long long cur2 = (pref2[i + m] - pref2[i] + mod) % mod;
        if (cur1 == cur2 && cur2 == (hash_pattern * power[i]) % mod)
            count++;
    }

    return count;
}

int main() {
    string s1, s2, pattern;
    cin >> s1 >> s2 >> pattern;

    cout << countOccurrences(s1, s2, pattern);
}