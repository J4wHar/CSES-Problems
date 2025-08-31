#include "../main.h"

void apartments(){
    int n, m, k;
    cin >> n >> m >> k;
    ll a[n], b[m];
    map<ll, ll> map;
    for (int i=0;i<n;++i){
        cin >> a[i];
    }

    sort(a, a+n);

    for (int i=0;i<m;++i){
        cin >> b[i];
        ++map[b[i]];
    }

    ll ans = 0;
    for (int i=0;i<n;++i){
        auto it = map.lower_bound(a[i]-k);
        if(it == map.end() || it->first > a[i]+k){
            continue;
        }

        --map[it->first];
        if (!map[it->first]){
            map.erase(it->first);
        }

        ++ans;
    }

    cout << ans;
}