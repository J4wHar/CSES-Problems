#include "../main.h"

void diceCombinations(){
    int n;
    cin >> n;
    ll dp[n+1];
    dp[0] = 1;
    int l, r;
    for(int i=1;i<=n;++i){
        dp[i] = 0;
        l = max(0, i - 6);
        r = i-1;
        for(int cur=l;cur<=r;++cur){
            dp[i] = (dp[i] + dp[cur]) % MOD;
        }
    }

    cout << dp[n];
}