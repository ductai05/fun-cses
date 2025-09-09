// Duc Tai Dinh [cieldt] - 23122013, AI23 @ HCMUS-VNUHCM
// 20:46:00, 09/09/2025
// https://cses.fi/problemset/task/1746
// --------------------------------
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>

typedef long long ll;

using namespace std;


void solve(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ll n, m;
    ll MOD = 1e9 + 7;
    cin >> n >> m;
    vector<ll> a(n + 1, 0);
    for (ll i = 1; i <= n; i++){
        cin >> a[i];
    }

    vector<vector<ll>> dp(n + 1, vector<ll> (m + 2, 0)); // dp[i][x]; 1<=i<=n; 1<=x<=m
    if (a[1] == 0){
        for (ll x = 1; x <= m; x++) dp[1][x] = 1;
    } else {
        for (ll x = 1; x <= m; x++) dp[1][x] = ((x == a[1]) ? 1 : 0);
    }
    for (ll i = 2; i <= n; i++){
        if (a[i] != 0){
            dp[i][a[i]] = (dp[i - 1][a[i] - 1] + dp[i - 1][a[i]] + dp[i - 1][a[i] + 1]) % MOD;
            continue;
        } 
        for (ll x = 1; x <= m; x++){
            dp[i][x] = (dp[i - 1][x - 1] + dp[i - 1][x] + dp[i - 1][x + 1]) % MOD;
        }
    }
    ll res = 0;
    for (ll x = 1; x <= m; x++){
        res = (res + dp[n][x]) % MOD;
    }
    cout << res;
}

int main() {
    solve();
    return 0;
}