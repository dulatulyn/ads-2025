#include <bits/stdc++.h>
using namespace std;

void computeLPSArray(string pattern, int m, vector<int> &LPS) {
    int length = 0;
    LPS[0] = 0;
    int i = 1;

    while (i < m) {
        if (pattern[i] == pattern[length]) {
            length++;
            LPS[i] = length;
            i++;
        } else {
            if (length != 0) {
                length = LPS[length - 1];
            } else {
                LPS[i] = 0;
                i++;
            }
        }
    }
}

int main() {
    string s;
    cin >> s;
    int n = s.size();

    vector<int> LPS(n);
    computeLPSArray(s, n, LPS);

    int period = n - LPS[n - 1];
    cout << period;
}