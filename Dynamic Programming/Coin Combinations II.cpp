// Duc Tai Dinh [cieldt] - 23122013, AI23 @ HCMUS-VNUHCM
// 22:15:26, 18/08/2025
// https://cses.fi/problemset/task/1636
// --------------------------------
#include <iostream>
#include <vector>

typedef long long ll;
using namespace std;

void solve(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ll n, x; cin >> n >> x;
    vector<ll> coins(n);
    for (int i = 0; i < n; i++) cin >> coins[i];
    const ll MOD = 1000000007;
    vector<ll> dp(x + 1, 0);
    dp[0] = 1;
    for (ll coin: coins){
        for (ll sum = coin; sum <= x; sum++){
            dp[sum] += dp[sum - coin];
            dp[sum] %= MOD;
        }
    }
    cout << dp[x];
}

int main() {
    solve();
    return 0;
}