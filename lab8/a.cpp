#include <bits/stdc++.h>
#define ull unsigned long long
using namespace std;

const int C = 1e9 + 7;
const int p = 11;
string getHash(string s)
{
    ull hash = 0, pow = 1;
    for (int i = 0; i < s.size(); i++)
    {
        ull curH = (s[i] - 47) * pow % C;
        hash = (hash + curH) % C;
        pow = (pow * p) % C;
    }
    return to_string(hash);
}
int main()
{
    int n;
    cin >> n;
    vector<string> v(2 * n);
    unordered_map<string, bool> mp;
    for (int i = 0; i < 2 * n; i++)
    {
        cin >> v[i];
        mp[v[i]] = true;
    }
    int cnt = 0;
    for (int i = 0; i < 2 * n; i++)
    {
        if (cnt == n)
            break;
        string hash = getHash(v[i]);
        if (mp[hash])
        {
            cout << "Hash of string " << '"' << v[i] << '"' << " is " << hash << endl;
            cnt++;
        }
    }
}