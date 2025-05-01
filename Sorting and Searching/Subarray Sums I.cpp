// Duc Tai Dinh [cieldt] - 23122013, AI23 @ HCMUS-VNUHCM
// 22:11:07, 30/04/2025
// https://cses.fi/problemset/task/1660
// --------------------------------
#include <iostream>

#define ll long long
using namespace std;

void solve(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ll n, x; cin >> n >> x;
    ll a[n];
    for (ll i = 0; i < n; i++) cin >> a[i];
    ll lo = 0, hi = 0;
    ll sum = a[0], res = 0;
    while (lo <= hi && lo < n && hi < n){
        // for (int i = lo; i <= hi; i++){
        //     cout << a[i] << " ";
        // } cout << "::" << lo << " -> " << hi << " - " << sum << '\n';
            
        if (lo == hi){
            if (sum == x) res++;
            hi++;
            sum += a[hi];
            continue;
        }
        if (sum < x){
            hi++;
            sum += a[hi];
        } else if (sum > x){
            sum -= a[lo];
            lo++;
        } else { // sum == x
            res++;
            if (lo <= hi) {
                hi++;
                sum += a[hi];
            }
            else {
                sum -= a[lo];
                lo++;
            }
        }
    }
    cout << res;
}

int main() {
    solve();
    return 0;
}