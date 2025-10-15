#include "../main.h"

ll dp[N];

void coinCombinationsII(){
    ll n, x;
    cin >> n >> x;
    int a[n];
    for (int i=0;i<n;++i){
        cin >> a[i];
    }

    sort(a, a+n);
    dp[0] = 1;

    for (int i=0;i<n;++i){
        int coin = a[i];
        for (int cur=0;cur<x;++cur){
            ll sum = cur + coin;
            if (sum > x){
                break;
            }
            dp[sum] += dp[cur];
            dp[sum] %= MOD;
        }
    }

    cout << dp[x];
}
