#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<int> v;

int accum(int r){
    int sum = 0;
    for(int i = 0; i < r; i++){
        sum += v[i];
    }
    return sum;
}

int main(){
    int n, b; cin >> n >> b;
    
    for(int i = 0; i < n; i++){
        int m; cin >> m;
        v.push_back(m);
    }
    
    for(int i = 0; i < b; i++){
        int bug; cin >> bug;
        int left = 0, right = v.size() - 1, mid;
       
        while(left <= right){
            mid = left + (right - left) / 2;
            int sum = accum(mid);
            
            if (sum <= bug && (sum + v[mid] >= bug)) {
                break;
            } else if(sum > bug) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        
        cout << mid + 1 << endl;
    }
    return 0;
}