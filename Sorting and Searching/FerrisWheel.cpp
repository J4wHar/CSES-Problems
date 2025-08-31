#include "../main.h"

void ferrisWheel(){
    int n;
    ll x;
    cin >> n >> x;
    ll p[n];
    for (int i=0;i<n;++i){
        cin >> p[i];
    }

    sort(p, p+n);
    int l=0, r=n-1;
    int ans = 0;
    while(l <= r){
        if (l == r){
            ++ans;
            break;
        }

        if (p[l] + p[r] <= x){
            ++ans;
            ++l;
            --r;
        } else {
            ++ans;
            --r;
        }
    }

    cout << ans;
}