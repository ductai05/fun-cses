#include<iostream>
 
using namespace std;
typedef long long ll;
 
void solve(){
    return;
}
 
int main(){
    ll n; cin >> n;
    if (n >= 1) cout << "0\n";
    for (ll i = 2; i <= n; i++){
        cout << i*i*(i*i - 1)/2 - 4*(i-1)*(i-2) << "\n";
    }
}
