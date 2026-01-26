// Duc Tai Dinh [cieldt] - 23122013, AI23 @ HCMUS-VNUHCM
// 16:55:00, 26/01/2025
// https://cses.fi/problemset/task/3420
// -----------------------------------------------------

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;
#define ll long long

void solve(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll res = 0;
    ll n; cin >> n;
    vector<ll> arr(n);
    for (ll i = 0; i < n; i++) {
        cin >> arr[i];
    }
    ll left = 0, right = 0;
    set<ll> s;
    while (right < n) {
        if (s.find(arr[right]) == s.end()) {
            s.insert(arr[right]);
            res += right - left + 1;
            right++;
        } else {
            s.erase(arr[left]);
            left++;
        }
    }
    cout << res << "\n";
}

int main(){
    solve();
    return 0;
}

