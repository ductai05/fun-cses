// Duc Tai Dinh [cieldt] - 23122013, AI23 @ HCMUS-VNUHCM
// 20:24:51, 21/04/2025
// https://cses.fi/problemset/task/2168
// --------------------------------
#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;

class Range{
public:
    ll first;
    ll second;
    ll id;
    bool contain;
    bool otherContain;
    Range(){
        first = 0;
        second = 0;
        id = 0;
        contain = false;
        otherContain = false;
    }
};

void solve(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ll n; cin >> n;
    vector<Range*> ranges(n);
    for (ll i = 0; i < n; i++){
        ranges[i] = new Range();
        cin >> ranges[i]->first >> ranges[i]->second;
        ranges[i]->id = i;
    }
    sort(ranges.begin(), ranges.end(), [](Range* a, Range* b){
        if (a->first == b->first) return a->second > b->second;
        return a->first < b->first;
    });

    ll minR = 2e9;
    for (ll i = n - 1; i > -1; i--){ // contain
        if (ranges[i]->second >= minR) ranges[i]->contain = true;
        minR = min(minR, ranges[i]->second);
    }
    ll maxR = 0;
    for (ll i = 0; i < n; i++){ // otherContain
        if (ranges[i]->second <= maxR) ranges[i]->otherContain = true;
        maxR = max(maxR, ranges[i]->second);
    }

    sort(ranges.begin(), ranges.end(), [](Range* a, Range* b){
        return a->id < b->id;
    });

    for (ll i = 0; i < n; i++) cout << ranges[i]->contain << " "; 
    cout << "\n";
    for (ll i = 0; i < n; i++) cout << ranges[i]->otherContain << " "; 
    cout << "\n";
}

int main() {
    solve();
    return 0;
}