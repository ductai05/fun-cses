#include<iostream>
 
using namespace std;
 
int main(){
    int n; cin >> n;
    int *a = new int[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    
    int max_now = a[0];
    long long ans = 0;
    for (int i = 0; i < n; i++){
        max_now = max(max_now, a[i]);
        ans += max_now - a[i];
    }
    cout << ans;
    return 0;
}
