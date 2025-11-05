#include <bits/stdc++.h>
using namespace std;

bool isSubstring(const string &a, const string &b) {
    if (a.size() > b.size()) return false;
    for (size_t i = 0; i + a.size() <= b.size(); i++) {
        if (b.compare(i, a.size(), a) == 0) return true;
    }
    return false;
}

string slicing(string s, int ind1, int ind2) {
    if (ind1 < 0) ind1 = 0;
    if (ind2 >= s.size()) ind2 = s.size() - 1;
    if (ind1 > ind2) return "";
    return s.substr(ind1, ind2 - ind1 + 1);
}

int main(){
    int n; cin >> n;
    vector<string> v(n);
    
    int min_ind = 0;
    string min_str;
    
    for(int i = 0; i < n; i++){
        cin >> v[i];
        if(i == 0 || v[i].size() < min_str.size()){
            min_str = v[i];
            min_ind = i;
        }
    }
    
    string max_ans = "";
    for(int i = 0; i < min_str.size(); i++){
        for(int j = i; j < min_str.size(); j++){
            string ans = slicing(min_str, i, j);
            bool ok = true;
            for(int k = 0; k < n; k++){
                if(k == min_ind) continue;
                if(!isSubstring(ans, v[k])){
                    ok = false;
                    break;
                }
            }
            if(ok && ans.size() > max_ans.size()) max_ans = ans;
        }
    }
    
    cout << max_ans;
}