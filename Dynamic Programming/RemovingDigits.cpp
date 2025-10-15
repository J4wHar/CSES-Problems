#include "../main.h"

ll dp[N];

ll doDp(int x){
    if (x < 0){
        return INF;
    }
    if (x == 0){
        return 0;
    }
    if(dp[x] != -1){
        return dp[x];
    }

    string x_str = to_string(x);
    dp[x] = INF;
    for (auto& c : x_str){
        int digit = c - '0';
        dp[x] = min(dp[x], 1 + doDp(x-digit));
    }

    return dp[x];
}

void removingDigits(){
    ll n;
    cin >> n;
    memset(dp, -1, sizeof dp);
    cout << doDp(n);
}