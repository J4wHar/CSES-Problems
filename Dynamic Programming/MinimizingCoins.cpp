#include "../main.h"

// Should be declared here, not in the method. Why?
// Otherwise, it would be saved in the stack which has a limited size -> Segmentation fault
// Solution: Global declaration -> static memory (judge memory limit), or use vector -> Heap
int dp[N];

void minimizingCoins(){
    int n, x;
    cin >> n >> x;
    int coins[n];
    int coin, cur;
    for (int i=0;i<n;++i){
        cin >> coins[i];
    }

    memset(dp, -1, sizeof dp);
    dp[0] = 0;
    for (int i=0;i<=x;++i){
        if (dp[i] == -1){
            continue;
        }
        for (int j=0;j<n;j++){
            coin = coins[j];
            cur = i+coin;
            if (cur > x){
                continue;
            }
            if (dp[cur] == -1){
                dp[cur] = 1 + dp[i];
            }else{
                dp[cur] = min(dp[cur], 1+dp[i]);
            }
        }
    }

    cout << dp[x];
}