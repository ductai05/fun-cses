// Duc Tai Dinh [cieldt] - 23122013, AI23 @ HCMUS-VNUHCM
// 08:40:05, 29/04/2025
// https://cses.fi/problemset/task/1620
// --------------------------------
#include <iostream>
#define ll long long

using namespace std;

bool canMake(const ll* a, const ll n, const ll time, const ll product){
    ll pd = 0;
    for (int i = 0; i < n; i++){
        pd += time / a[i];
        if (pd >= product) {
            return true;
        }
    }
    return pd >= product;
}

void solve(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    ll n, t; cin >> n >> t;
    ll a[n];
    for (ll i = 0; i < n; i++) cin >> a[i];
    ll max_val = 0;
    for (ll i = 0; i < n; i++) max_val = max(max_val, a[i]);
    ll lo = 0, hi = (ll) (1000000000) * max_val;
    while(lo < hi){
        ll mid = lo + (hi - lo) / 2;
        if (canMake(a, n, mid, t)){
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }
    cout << hi;
}

int main() {
    solve();
    return 0;
}