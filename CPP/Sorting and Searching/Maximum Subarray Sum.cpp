// cieldt - AI23@HCMUS
 
#include <iostream>
#include <algorithm> 
// #include <vector>
// #include <string>
// #include <unordered_map>
// #include <set>
#define F first
#define S second
typedef long long ll;
using namespace std;
 
void print(ll *a, ll *ps, ll n){
    cout << "a: ";
    for (ll i = 0; i < n; i++) cout << a[i] << " ";
    cout << "\nps: ";
    for (ll i = 0; i < n + 1; i++) cout << ps[i] << " ";
    cout << "\n";
}
 
void searchValue(ll *ps, ll *a, ll n, ll &ans){
    ans = ps[1];
    ll minn = ps[0];
    for (ll i = 1; i < n + 1; i++){
        ans = max(ans, ps[i] - minn);
        minn = min(minn, ps[i]);
    }
}
 
void solve(){
    ll n; cin >> n;
    ll *a = new ll [n];
    ll *ps = new ll [n + 1];
    for (ll i = 0; i < n; i++) cin >> a[i];
    ps[0] = 0;
    for (ll i = 1; i < n + 1; i++) ps[i] = ps[i - 1] + a[i - 1];
    // print(a, ps, n);
    
    ll ans;
    searchValue(ps, a, n, ans);
    cout << ans;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
