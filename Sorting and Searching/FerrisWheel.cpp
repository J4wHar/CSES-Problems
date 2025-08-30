#include <bits/stdc++.h>

#define J4wHar std::ios_base::sync_with_stdio(0) ; cin.tie(0) ;
#define pb push_back
#define mp make_pair
#define max(a,b) (a>b ? a : b)
#define min(a,b) (a<b ? a : b)
#define endl '\n'
#define st size_t
#define show(x) cout << #x << " = " << x << endl ;
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
using namespace std ;
typedef long long ll;
typedef unsigned long long ull;
const ll N = 2e5 +5 ;
const ll INF = LLONG_MAX ;
const ll MOD = 7 + 1e9 ;
int dx[] = {0 , 0 , 1 , -1};
int dy[] = {1 , -1 , 0 , 0};
void ferrisWheel(){
    int n;
    ll x;
    cin >> n >> x;
    ll p[n];
    for (int i=0;i<n;++i){
        cin >> p[i];
    }

    sort(p, p+n);
    int l=0, r=n-1;
    int ans = 0;
    while(l <= r){
        if (l == r){
            ++ans;
            break;
        }

        if (p[l] + p[r] <= x){
            ++ans;
            ++l;
            --r;
        } else {
            ++ans;
            --r;
        }
    }

    cout << ans;
}