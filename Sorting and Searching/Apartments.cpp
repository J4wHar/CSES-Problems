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