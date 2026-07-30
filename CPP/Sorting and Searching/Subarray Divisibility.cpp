// Duc Tai Dinh [cieldt] - 23122013, AI23 @ HCMUS-VNUHCM
// 22:12:11, 01/05/2025
// https://cses.fi/problemset/task/1662
// --------------------------------
#include <iostream>
#include <map>

#define ll long long
using namespace std;

void solve(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int n; cin >> n;
    int a[n];
    for (int i = 0; i < n; i++){
        cin >> a[i];
        a[i] = ((a[i] % n) + n) % n;
    }
    // for (int i = 0; i < n; i++) cout << a[i] << " ";
    ll prefix[n + 1]; prefix[0] = 0;
    ll sum = 0;
    for (int i = 0; i < n; i++){
        sum += a[i];
        prefix[i + 1] = ((sum % n) + n) % n;
    }
    map<int, int> mp;
    ll res = 0;
    for (auto it: prefix){
        if (mp.find(it) != mp.end()){
            res += mp[it];
        }
        mp[it]++;
    }
    cout << res;
}

int main() {
    solve();
    return 0;
}