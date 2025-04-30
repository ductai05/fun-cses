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
 
void solve(){
    int n; cin >> n;
    ll ans = 0;
    int *a = new int [n];
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a, a + n);
    ll median;
    if (n % 2 == 1) median = a[(n - 1)/2];
    else median = a[n / 2 - 1];
    // cout << median << "\n";
    
    for (int i = 0; i < n; i++){
        ans += abs(a[i] - median);
    }
    
    cout << ans;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
