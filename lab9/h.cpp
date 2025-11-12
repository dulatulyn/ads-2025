#include <bits/stdc++.h>
using namespace std;

int main() {
    string s; cin >> s;
    int cnt = 0, n = s.size();

    for(int len = 1; len*2 < n; len++)
        if(equal(s.begin(), s.begin()+len, s.begin()+len))
            cnt++;

    cout << cnt;
}