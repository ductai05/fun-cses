// Duc Tai Dinh [cieldt] - 23122013, AI23 @ HCMUS-VNUHCM
// 08:43:32, 01/05/2025
// https://cses.fi/problemset/task/1661
// --------------------------------
#include <iostream>
#include <map>

#define ll long long
using namespace std;

void solve(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ll n, x; cin >> n >> x;
    ll a[n];
    for (ll i = 0; i < n; i++) cin >> a[i];

    ll prefix_sum = 0, res = 0;
    map<ll, ll> sums;
    sums[0] = 1;
    for (int i = 0; i < n; i++){
        prefix_sum += a[i];
        res += sums[prefix_sum - x];
        sums[prefix_sum]++;
    }
    cout << res;
}

int main() {
    solve();
    return 0;
}