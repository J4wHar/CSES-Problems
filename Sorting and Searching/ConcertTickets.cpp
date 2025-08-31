#include "../main.h"

void concertTickets(){
    int n, m;
    cin >> n >> m;
    ll h[n], t[m];
    multiset<ll> ms;
    for (int i=0;i<n;++i){
        cin >> h[i];
        ms.insert(h[i]);
    }
    for (int i=0;i<m;++i){
        cin >> t[i];
    }
    for (int i=0;i<m;++i){
        if (ms.empty()){
            cout << -1 << endl;
            continue;
        }

        auto it = ms.lower_bound(t[i]);
        if (it == ms.begin() && *it > t[i]){
            cout << -1 << endl;
            continue;
        }

        if (it == ms.end() || (*it) > t[i]){
            it = prev(it);
        }

        cout << (*it) << endl;
        ms.erase(it);
    }
}