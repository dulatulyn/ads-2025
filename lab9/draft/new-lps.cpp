#include <bits/stdc++.h>
using namespace std;

void computeLPSArray(string pattern, int m, vector<int> &LPS){
    int length = 0;
    LPS[0] = 0;
    int i = 1;

    while(i < m){
        if(pattern[i] == pattern[length]){
            length++;
            LPS[i] = length;
            i++;
        } else {
            if(length != 0){
                length = LPS[length - 1];
            } else{
                LPS[i] = 0;
                i++;
            }
        }
    }
}

vector<int> KMP(string pattern, string text){
    int m = pattern.length();
    int n = text.length();

    vector<int> ans;
    vector<int> LPS(m);
    computeLPSArray(pattern, m, LPS);

    int i = 0;
    int j = 0;

    while(i < n){
        if (pattern[j] == text[i]) {
            i++;
            j++;
        }

        if (j == m) {
            ans.push_back(i - j);
            j = LPS[j - 1];
        } else if (i < n && pattern[j] != text[i]) {
            if (j != 0) {
                j = LPS[j - 1];
            }
            else {
                i++;
            }
        }
    }
    return ans;
}