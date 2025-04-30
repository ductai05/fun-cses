// cieldt - AI23@HCMUS
 
#include <iostream>
#include <algorithm> 
// #include <vector>
// #include <string>
// #include <unordered_map>
// #include <set>
using namespace std;
 
void solve(){
    int n; cin >> n;
    int* a = new int[n];
    int* b = new int[n];
    for(int i = 0; i < n; i++){
        cin >> a[i] >> b[i];
    }
    
    int ans = 0, now = 0;
    sort(a, a + n); sort(b, b + n);
    int ida = 0, idb = 0;
    while (ida < n && idb < n){
        if (a[ida] < b[idb]){
            now++; ida++;
            ans = max(ans, now);
        } else {
            now--; idb++;
        }
    }
    cout << ans;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
