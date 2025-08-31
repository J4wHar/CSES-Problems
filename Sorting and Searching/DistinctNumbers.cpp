#include "../main.h"

void distinctNumbers(){
    int n;
    cin >> n;
    set<ll> s;
    ll x;
    while(n--){
        cin >> x;
        s.insert(x);
    }

    cout << s.size();
}