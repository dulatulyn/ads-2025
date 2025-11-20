#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<int> sizes;

int main() {
    int n, m; cin >> n >> m;
    
    for(int i = 0; i < n; i++){
        int size; cin >> size;
        sizes.push_back(size);
    }

    vector<int> end_lines(n);
    end_lines[0] = sizes[0];
    
    for (int i = 1; i < n; i++) {
        end_lines[i] = end_lines[i - 1] + sizes[i];
    }

    for(int i = 0; i < m; i++){
        int line; cin >> line;
        
        int left = 0, right = n - 1, mid;
        
        while(left <= right){
            mid = left + (right - left) / 2;
            
            if (end_lines[mid] >= line) {
                if (mid == 0 || end_lines[mid - 1] < line) {
                    break;
                }
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        
        cout << mid + 1 << endl;
    }
    
    return 0;
}