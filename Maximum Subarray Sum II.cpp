// Duc Tai Dinh [cieldt] - 23122013, AI23 @ HCMUS-VNUHCM
// 23:17:46, 07/06/2025
// https://cses.fi/problemset/task/1644
// --------------------------------
#include <iostream>
#include <climits>

typedef long long ll;
using namespace std;

void searchValue(ll *ps, ll *arr, ll n, ll a, ll b, ll &ans){
    ans = ps[1];
    ll minn = ps[0];
    for (ll i = 1; i < n + 1; i++){
        ans = max(ans, ps[i] - minn);
        minn = min(minn, ps[i]);
    }
}

void solve(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    ll n, a, b; cin >> n >> a >> b;
    ll *arr = new ll[n];
    for (int i = 0; i < n; i++) cin >> arr[i];
    ll pref = 0;
    ll *prefix = new ll[n + 1];
    prefix[0] = 0;
    for (int i = 0; i < n + 1; i++){
        pref += arr[i];
        prefix[i + 1] = pref;
    }

    // for (int i = 0; i < n + 1; i++) cout << prefix[i] << " "; cout << "\n";

    ll ans;
    searchValue(prefix, arr, n, a, b, ans);
    cout << ans;

    delete [] arr, prefix;
}

int main() {
    solve();
    return 0;
}