#include <bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string s; cin >> s;
    int n = s.size();
    
    long long base1 = 31;
    long long base2 = 37;
    long long mod1 = 1e9 + 7;
    long long mod2 = 1e9 + 9;
    
    unordered_set<long long> st;
    for(int i = 0; i < n; i++){
        long long h1 = 0, h2 = 0;
        for(int j = i; j < n; j++){
            h1 = (h1 * base1 + (s[j] - 'a' + 1)) % mod1;
            h2 = (h2 * base2 + (s[j] - 'a' + 1)) % mod2;
            st.insert(h1 * mod2 + h2);
        }
    }
    cout << st.size();
}