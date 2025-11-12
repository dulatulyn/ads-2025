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


int minShiftToMatch(string pattern, string text){
    int m = pattern.size();
    vector<int> LPS(m);
    computeLPSArray(pattern, m, LPS);

    int i = 0, j = 0;
    while(i < 2 * m){
        if(pattern[j] == text[i % m]){
            i++;
            j++;
        }
        if(j == m){
            return (i - j) % m;
        } else if(i < 2 * m && pattern[j] != text[i % m]){
            if(j != 0) j = LPS[j - 1];
            else i++;
        }
    }
    return -1;
}


int main(){
    string pattern, text;
    cin >> pattern >> text;

    cout << minShiftToMatch(pattern, text);
}