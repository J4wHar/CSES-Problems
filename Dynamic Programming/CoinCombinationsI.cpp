#include "../main.h"

ll dp[N];
void coinCombinationsI(){
    ll n, x;
    cin >> n >> x;
    ll a[n];
    memset(dp, 0, sizeof dp);
    for (int i=0;i<n;++i){
        cin >> a[i];
        ++dp[a[i]];
    }
    for(int i=0;i<=x;++i){
        for(int j=0;j<n;++j){
            ll cur = i+a[j];
            if (cur <= x){
                dp[cur] = ((dp[cur]%MOD) + dp[i]) % MOD;
            }
        }
    }

    cout << dp[x] % MOD;
}