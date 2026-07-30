// Duc Tai Dinh [cieldt] - 23122013, AI23 @ HCMUS-VNUHCM
// 22:51:57, 18/08/2025
// https://cses.fi/problemset/task/1637
// --------------------------------
#include <iostream>
#include <vector>
#include <set>

using namespace std;

vector<int> get_all_digits(int sum){
    set<int> digits;
    while (sum != 0){
        digits.insert(sum % 10);
        sum /= 10;
    }
    vector<int> digits_vec(digits.begin(), digits.end());
    return digits_vec;
}

void solve(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int n; cin >> n;
    vector<int> dp(n + 1);
    dp[0] = 0;
    for (int sum = 1; sum <= n; sum ++){
        vector<int> all_digits = get_all_digits(sum);
        dp[sum] = 1000000000;
        for (int digit : all_digits){
            dp[sum] = min(dp[sum], 1 + dp[sum - digit]);
        }
    }
    cout << dp[n];
}

int main() {
    solve();
    return 0;
}