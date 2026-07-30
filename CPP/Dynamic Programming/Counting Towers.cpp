// Duc Tai Dinh [cieldt] - 23122013, AI23 @ HCMUS-VNUHCM
// 21:25:00, 24/09/2025
// https://cses.fi/problemset/task/2413
// --------------------------------
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>

typedef long long ll;

using namespace std;

void solve(){
    const ll MOD = 1e9 + 7;
    ll n; cin >> n;
    
    ll a = 1, b = 1;
    for (ll i = 2; i <= n; i++){
        ll new_a = (4 * a + b) % MOD;
        ll new_b = (a + 2 * b) % MOD;
        a = new_a;
        b = new_b;
    }
    cout << (a + b) % MOD << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int t; cin >> t;
    while (t--){
        solve();
    }
    // solve();
    return 0;
}