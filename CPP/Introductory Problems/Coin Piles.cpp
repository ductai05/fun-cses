#include<iostream>
#include<cmath>
using namespace std;
typedef long long ll;
 
void solve(){
    ll a, b; cin >> a >> b;
    cout << ((((2*a - b) % 3 == 0) && ((2*b - a) % 3 == 0) &&(2*a >= b) && (2*b >= a)) ? "YES\n" : "NO\n");
}
 
int main(){
    int t; cin >> t;
    while(t--){
        solve();
    }
}
