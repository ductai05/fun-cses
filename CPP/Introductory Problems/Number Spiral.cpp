#include<iostream>
 
using namespace std;
typedef long long ll;
void solve(){
    ll y, x; cin >> y >> x;
    ll layer = max(x, y);
    ll mid = (layer*layer + (layer-1)*(layer-1) + 1)/2;
    if (x == y) {
        cout << mid;
    } else {
        ll diff = (y > x) ? y - x : x - y;
        // cout << diff << " ";
        if ((layer % 2 == 0 && y > x) || (layer % 2 == 1 && y < x)){
            cout << mid + diff;
        } else {
            cout << mid - diff;
        }
    }
    cout << "\n";
}
 
int main(){
    ll t; cin >> t;
    while (t--){
        solve();
    }
}
