#include "../main.h"

bool compare(pair<ll, ll> x, pair<ll, ll> y){
    if (x.second == y.second){
        return x.first < y.first;
    }

    return x.second < y.second;
}

void movieFestival(){
    int n;
    vector<pair<ll, ll>> v;
    ll a, b;
    cin >> n;
    for (int i=0;i<n;++i){
        cin >> a >> b;
        v.pb(mp(a, b));
    }
    sort(v.begin(), v.end(), compare);
    ll ans = 1;
    ll cur = v[0].second;
    for (int i=1;i<n;++i){
        pair<ll, ll> x = v[i];
        if (x.first < cur){
            continue;
        }
        ++ans;
        cur = x.second;
    }
    cout << ans;
}