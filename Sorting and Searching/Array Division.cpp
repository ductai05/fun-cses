// Duc Tai Dinh [cieldt] - 23122013, AI23 @ HCMUS-VNUHCM
// 22:02:34, 04/06/2025
// https://cses.fi/problemset/task/1085/
// --------------------------------
#include <iostream>

typedef long long ll;
using namespace std;

bool check(const ll *a, ll k, ll n, ll max_sub_array){
    ll count = 0;
    long long sum = 0;
    ll i = 0;
    while (i < n){
        sum += a[i];
        if (sum > max_sub_array){
            sum = 0;
            count++;
        } else {
            i++;
        }
    }
    count++;
    return count <= k;
}

void solve(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    // max element <= maximum sum in a subarray <= sum of array

    ll n, k;
    cin >> n >> k;
    ll *a = new ll [n];

    for (ll i = 0; i < n; i++) cin >> a[i];

    long long sum_of_array = 0;
    ll max_ele = 0;
    for (ll i = 0; i < n; i++){
        sum_of_array += a[i];
        max_ele = max(max_ele, a[i]);
    }

    ll begin = max_ele, end = sum_of_array;
    while(begin <= end){
        ll mid = begin + (end - begin) / 2;
        if (check(a, k, n, mid)){ // can create k subarray with maximum sum in a subarray = mid
            end = mid - 1;
        } else {
            begin = mid + 1;
        }
    }
    cout << begin;

    delete [] a;
}

int main() {
    solve();
    return 0;
}