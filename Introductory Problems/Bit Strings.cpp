#include<iostream>
#include<cmath>
using namespace std;
typedef long long ll;
 
void solve(){
    return;
}
 
int main(){
    long long n; cin >> n;
    ll m = pow(10, 9) + 7;
    ll ans = 1;
    while (n--){
        ans *= 2;
        ans %= m;
    }
    cout << ans;
}
