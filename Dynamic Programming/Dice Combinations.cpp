// Duc Tai Dinh [cieldt] - 23122013, AI23 @ HCMUS-VNUHCM
// 15:06:10, 09/08/2025
// https://cses.fi/problemset/task/1633
// --------------------------------
#include <iostream>
#include <vector>
typedef long long ll;

using namespace std;

ll dice(ll n){
    vector<ll> dp(n + 1, 0);
    ll modulo = 1000000007;
    dp[0] = 1;
    for (ll i = 1; i <= n; i++){
        for (ll j = 1; j <= min((ll) 6, i); j++){
            dp[i] = (dp[i] + dp[i - j]) % modulo;
        }
    }
    return dp[n];
}

void solve(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    ll n; cin >> n;
    cout << dice(n);
}

int main() {
    solve();
    return 0;
}