// Duc Tai Dinh [cieldt] - 23122013, AI23 @ HCMUS-VNUHCM
// 11:57:47, 29/04/2025
// https://cses.fi/problemset/task/1630
// --------------------------------
#include <iostream>
#include <vector>
#include <algorithm>
 
#define ll long long
using namespace std;
 
void solve(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
 
    ll n; cin >> n;
    vector<pair<ll, ll>> ad(n);
    for (ll i = 0; i < n; i++) cin >> ad[i].first >> ad[i].second;
    sort(ad.begin(), ad.end(), [](const pair<ll, ll>& a, const pair<ll, ll>& b){
        return a.first > b.first;
    });
    ll res = 0;
    for (ll i = 0; i < n; i++){
        res += ad[i].second;
        res -= (ad[i].first * (i + 1));
    }
    cout << res;
    
}
 
int main() {
    solve();
    return 0;
}
