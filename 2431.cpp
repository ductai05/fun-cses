// Duc Tai Dinh [cieldt] - 23122013, AI23 @ HCMUS-VNUHCM
// 08:30:13, 18/04/2025
// https://cses.fi/problemset/task/2431/
// --------------------------------
#include <iostream>

using namespace std;
typedef long long ll;

ll power(ll a, ll b){
    ll res = 1;
    while (b > 0){
        if (b & 1){ // b mod 2 == 1 => a^b = a * (a^2)^((b-1)/2)
            res *= a;
        } // b mod 2 == 0 => a^b = (a^2)^(b/2) 
        a *= a;
        b >>= 1;
    }
    return res;
}

ll query(ll k){
    ll digits = 1;
    ll base = 9;
    while (k - digits * base > 0){
        k -= digits * base;
        digits++;
        base *= 10;
    }
    // index of k in the number. if index == 0 -> most right
    ll index = k % digits;
    // the number which contains the Nth digit
    ll res = power(10, digits - 1) + (k - 1) / digits;
    if (index != 0){
        res /= power(10, digits - index);
    }
    return res %= 10;
}

void solve(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int q; cin >> q;
    ll k;
    while(q--){
        cin >> k;
        cout << query(k) << "\n";
    }
}

int main() {
    solve();
    return 0;
}