// Duc Tai Dinh [cieldt] - 23122013, AI23 @ HCMUS-VNUHCM
// 16:12:59, 12/08/2025
// https://cses.fi/problemset/task/1635
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

    ll n, x;
    cin >> n >> x;
    vector<ll> coins(n);
    for (int i = 0; i < n; i++){
        cin >> coins[i];
    }

    const int MOD = 1000000007;
    vector<ll> dp(x + 1, 0);
    dp[0] = 1;

    for (int i = 1; i <= x; i++){
        for (int j = 0; j < n; j++){
            if (coins[j] <= i){
                dp[i] = (dp[i] + dp[i - coins[j]]) % MOD;
            }
        }
    }

    cout << dp[x] << "\n";
}

int main() {
    solve();
    return 0;
}