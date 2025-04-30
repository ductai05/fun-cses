// cieldt - AI23@HCMUS
 
#include <iostream>
#include <algorithm> 
// #include <vector>
// #include <string>
// #include <unordered_map>
// #include <set>
#define F first
#define S second
using namespace std;
 
bool priority(pair<int, int> a, pair<int, int> b){
    return a.first < b.first;
}
 
void print(pair<int, int> *a, int n){
    cout << "value: ";
    for (int i = 0; i < n; i++){
        cout << a[i].first << " ";
    }
    cout << "\nindex: ";
    for (int i = 0; i < n; i++){
        cout << a[i].second << " ";
    }
    cout << "\n";
}
 
void solve(){
    int n, x; cin >> n >> x;
    
    pair<int, int> *a = new pair<int, int> [n];
    for(int i = 0; i < n; i++){
        cin >> a[i].first;
        a[i].second = i + 1;
    }
    sort(a, a + n, priority);
    // print(a, n);
    int st = 0, en = n - 1;
    while(st < en){
        if (x < a[st].F + a[en].F){
            en--;
        } else if (x > a[st].F + a[en].F){
            st++;
        } else {
            cout << a[st].S << " " << a[en].S;
            return;
        }
    }
    cout << "IMPOSSIBLE";
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
