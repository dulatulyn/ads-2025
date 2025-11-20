#include <bits/stdc++.h>
using namespace std;

long long modPow(long long a, long long b, long long mod) {
    long long r = 1;
    while (b) {
        if (b & 1) r = (r * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return r;
}

bool canCover(const string& text, const vector<string>& patterns) {
    const long long p = 31;
    const long long mod = 1e9 + 7;
    int n = text.size();

    vector<long long> power(n);
    power[0] = 1;
    for (int i = 1; i < n; i++)
        power[i] = (power[i - 1] * p) % mod;

    vector<long long> pref(n + 1, 0);
    for (int i = 0; i < n; i++) {
        int value = text[i] - 'a' + 1;
        pref[i + 1] = (pref[i] + value * power[i]) % mod;
    }

    long long inv_p = modPow(p, mod - 2, mod);
    vector<long long> inv_power(n);
    inv_power[0] = 1;
    for (int i = 1; i < n; i++)
        inv_power[i] = (inv_power[i - 1] * inv_p) % mod;

    unordered_map<int, unordered_set<long long>> by_len;
    for (string pattern : patterns) {
        long long hash_pattern = 0;
        for (int i = 0; i < (int)pattern.size(); i++) {
            int value = pattern[i] - 'a' + 1;
            hash_pattern = (hash_pattern + value * power[i]) % mod;
        }
        by_len[(int)pattern.size()].insert(hash_pattern);
    }

    vector<int> diff(n + 1, 0);
    for (auto &kv : by_len) {
        int m = kv.first;
        auto &hs = kv.second;
        if (m > n) continue;
        for (int i = 0; i + m <= n; i++) {
            long long cur = (pref[i + m] - pref[i] + mod) % mod;
            long long normalized = (cur * inv_power[i]) % mod;
            if (hs.count(normalized)) {
                diff[i] += 1;
                diff[i + m] -= 1;
            }
        }
    }


    int cover = 0;
    for (int i = 0; i < n; i++) {
        cover += diff[i];
        if (cover <= 0) return false;
    }
    return true;
}

int main() {
    string text; cin >> text;
    int m; cin >> m;
    vector<string> patterns(m);
    for (int i = 0; i < m; i++) cin >> patterns[i];
    if (canCover(text, patterns)) cout << "YES";
    else cout << "NO";
}