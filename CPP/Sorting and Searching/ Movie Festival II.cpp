// Duc Tai Dinh [cieldt] - 23122013, AI23 @ HCMUS-VNUHCM
// 22:26:31, 04/06/2025
// https://cses.fi/problemset/task/1644
// --------------------------------
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

typedef long long ll;
using namespace std;

void solve(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ll n, k; cin >> n >> k;
    vector<pair<ll, ll>> movies(n, {0, 0});
    vector<bool> seen(n, false);
    ll st, en;
    for (ll i = 0; i < n; i++){
        cin >> st >> en;
        movies[i] = {st, en};
    }
    // sort(movies.begin(), movies.end(), [](const pair<ll, ll> &a, const pair<ll, ll> &b){
    //     return a.first < b.first;
    // });
    sort(movies.begin(), movies.end(), [](const pair<ll, ll> &a, const pair<ll, ll> &b){
        return a.second < b.second;
    });
    // for (auto p : movies){
    //     cout << p.first << " - " << p.second << "\n";
    // }

    int res = 0;

    multiset<ll> end_times;
    for (ll i = 0; i < k; i++) end_times.insert(0);

    for (ll i = 0; i < n; i++){
        auto it = end_times.upper_bound(movies[i].first);
        if (it == begin(end_times)){ 
            // all end_times > st time of movies[i] 
            // => no one can see this movie
            continue;
        } else {
            end_times.erase(--it);
            end_times.insert(movies[i].second);
            res++;
        }

    }
    cout << res;

    return;
}

int main() {
    solve();
    return 0;
}