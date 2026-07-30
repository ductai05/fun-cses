#include <iostream>
#include <vector>
#include <string>
#include <algorithm> 
#include <unordered_map>
#include <set>
using namespace std;
 
void solve(){
    int n, m, k; cin >> n >> m >> k;
    int* a = new int[n];
    int* b = new int[m];
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];
    sort(a, a + n); sort(b, b + m);
    
    // for (int i = 0; i < n; i++) cout << a[i] << " "; 
    // cout << "\n";
    // for (int i = 0; i < m; i++) cout << b[i] << " "; 
    // cout << "\n";
    
    int ida = 0, idb = 0, ans = 0;
    while (ida < n && idb < m){
        if (abs(a[ida] - b[idb]) <= k){
            ans++; ida++; idb++;
        } else {
            if (a[ida] > b[idb]) idb++;
            else ida++;
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
