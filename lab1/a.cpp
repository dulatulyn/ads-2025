#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; 
    cin >> t;
    
    for(int i = 0; i < t; i++){
        deque<int> dq;
        int n; cin >> n;
        for(int j = 0; j < n; j++){
            int c = n - j;
            
            dq.push_front(n - j);
            
            while(c > 0){
                dq.push_front(dq.back());
                dq.pop_back();
                c--;
            }
        }
        for(int x : dq) cout << x << " ";
        cout << endl;
    }
    return 0;
}
