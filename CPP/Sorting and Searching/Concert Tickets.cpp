// Duc Tai Dinh [cieldt] - 23122013, AI23 @ HCMUS-VNUHCM
// 09:43:58, 18/04/2025
// https://cses.fi/problemset/task/1091
// --------------------------------
#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <unordered_map>
 
#define ll long long
using namespace std;
 
void solve(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ll n, m; cin >> n >> m;
 
    ll x;
    multiset<ll> tickets;
    for (ll i = 0; i < n; i++) {
        cin >> x;
        tickets.insert(x);
    }
 
    ll t;
    for (ll i = 0; i < m; i++) {
        cin >> t;
        auto it = tickets.upper_bound(t);
        if (it == tickets.begin()){
            cout << "-1\n";
        } else {
            --it;
            cout << *it << "\n";
            tickets.erase(it);
        }
 
    }
}
 
int main() {
    solve();
    return 0;
}
