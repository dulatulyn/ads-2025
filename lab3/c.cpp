#include <bits/stdc++.h>
using namespace std;

vector<int> a;

int cntinrange(int l, int r){
    if(l > r || a.empty()) return 0;
    
    int la = 0, ra = a.size();
    while(la < ra){
        int m = la + (ra - la) / 2;
        if(a[m] < l) la = m + 1;
        else ra = m;
    }
    int left = la;
    
    la = 0, ra = a.size();
    while(la < ra){
        int m = la + (ra - la)/2;
        if(a[m] <= r) la = m + 1;
        else ra = m;
    }
    int right = ra;
    
    return right - left;
}

int main() {
	int n, q; cin >> n >> q;
	
	for(int i = 0; i < n; i++){
	    int m; cin >> m;
	    a.push_back(m);
	}
	
	sort(a.begin(), a.end());
	
	while(q--){
	    int l1, r1, l2, r2; cin >> l1 >> r1 >> l2 >> r2;
	    
	    int ans;
	    
	    if(r1 < l2 || r2 < l1){
	        ans = cntinrange(l1, r1) + cntinrange(l2, r2);
	    } else {
	        int l = min(l1, l2);
	        int r = max(r1, r2);
	        
	        ans = cntinrange(l, r);
	    }
	    
	    cout << ans << endl;
	}
}