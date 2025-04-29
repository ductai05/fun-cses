// Duc Tai Dinh [cieldt] - 23122013, AI23 @ HCMUS-VNUHCM
// 14:28:08, 29/04/2025
// https://cses.fi/problemset/task/1631
// --------------------------------
#include <iostream>
#include <algorithm>
#include <vector>
#include <bitset>

#define ll long long
using namespace std;

void solve(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ll n; cin >> n;
    ll a[n];
    for (ll i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n, [](ll a, ll b){
        return a < b;
    });
    // for (ll i = 0; i < n; i++) cout << a[i] << " ";

    ll rest = 0;
    for (ll i = 0; i < n - 1; i++) rest += a[i];
    if (rest >= a[n - 1]){
        cout << rest + a[n - 1];
    } else {
        cout << 2 * a[n - 1];
    }
}

int main() {
    solve();
    return 0;
}