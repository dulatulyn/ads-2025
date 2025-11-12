#include <bits/stdc++.h>
using namespace std;

void computeLPSArray(const string &s, vector<int> &LPS) {
    int n = (int)s.size();
    LPS.assign(n, 0);
    int len = 0;
    for (int i = 1; i < n; ) {
        if (s[i] == s[len]) {
            LPS[i++] = ++len;
        } else if (len != 0) {
            len = LPS[len - 1];
        } else {
            LPS[i++] = 0;
        }
    }
}

int maxPrefixSuffixMatch(const string &text, const string &pattern) {
    string a = text, b = pattern;
    for (char &c : a) c = (char)tolower((unsigned char)c);
    for (char &c : b) c = (char)tolower((unsigned char)c);
    string combined = a + "#" + b;
    vector<int> LPS;
    computeLPSArray(combined, LPS);
    return LPS.back();
}

int main() {
    string pattern;
    cin >> pattern;
    
    int n;
    cin >> n;
    vector<string> texts(n);
    for (int i = 0; i < n; i++) cin >> texts[i];

    int best = 0;
    vector<string> ans;

    for (const string &text : texts) {
        int match = maxPrefixSuffixMatch(text, pattern);
        if (match > best) {
            best = match;
            ans.clear();
            ans.push_back(text);
        } else if (match == best) {
            ans.push_back(text);
        }
    }

    if (best == 0) {
        cout << 0 << "\n";
        return 0;
    }

    cout << (int)ans.size() << "\n";
    for (const string &a : ans) cout << a << "\n";
    return 0;
}