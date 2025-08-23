// Duc Tai Dinh [cieldt] - 23122013, AI23 @ HCMUS-VNUHCM
// 23:40:52, 23/08/2025
// https://cses.fi/problemset/task/1158
// --------------------------------
#include <iostream>
#include <vector>

using namespace std;

void solve(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int n, x; cin >> n >> x;
    vector<int> prices(n + 1, 0);
    vector<int> pages(n + 1, 0);
    for (int i = 1; i <= n; i++) cin >> prices[i];
    for (int i = 1; i <= n; i++) cin >> pages[i];

    // dp[n][x]: number of pages, in first n books & limit x money
    vector<vector<int>> dp(n + 1, vector<int> (x + 1, 0));
    for (int book = 1; book <= n; book++){
        for (int money = 0; money <= x; money++){
            if (prices[book] > money) dp[book][money] = dp[book - 1][money];
            else {
                dp[book][money] = max(dp[book - 1][money], dp[book - 1][money - prices[book]] + pages[book]);
            }
        }
    }
    cout << dp[n][x];
}

int main() {
    solve();
    return 0;
}