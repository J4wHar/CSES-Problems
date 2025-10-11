#include "../main.h"

void restaurantCustomers(){
    int n;
    cin >> n;
    vector<pair<ll, ll>> v;
    ll x, y;
    for(int i=0;i<n;++i){
        cin >> x >> y;
        v.pb(mp(x, 1));
        v.pb(mp(y, -1));
    }

    int ans = 0;
    int cur = 0;
    sort(v.begin(), v.end());
    for(auto& x : v){
        cur += x.second;
        ans = max(ans, cur);
    }

    cout << ans;
}