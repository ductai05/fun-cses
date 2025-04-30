// Duc Tai Dinh [cieldt] - 23122013, AI23 @ HCMUS-VNUHCM
// 16:53:55, 18/04/2025
// https://cses.fi/problemset/task/2183
// --------------------------------
#include <iostream>
#include <vector>
#include <algorithm>
 
#define ll long long
using namespace std;
 
void solve(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
 
    ll n; cin >> n;
    ll res = 1;
    vector<ll> num(n);
    for (ll i = 0; i < n; i++) cin >> num[i];
    sort(num.begin(), num.end(), [](ll a, ll b){
        return a < b;
    });
    // for (ll i = 0; i < n; i++) cout << num[i] << " "; cout << '\n';
    for (ll i = 0; i < n; i++){
        if (num[i] <= res){
            res += num[i];
        } else break;
    }
    cout << res;
}
 
int main() {
    solve();
    return 0;
}
