#include<iostream>
 
using namespace std;
typedef long long ll;
 
void solve(){
    return;
}
 
int main(){
    ll n; cin >> n;
    ll sum = n*(n + 1)/2;
    if (sum % 2 != 0) {
        cout << "NO";
        return 0;
    } else {
        cout << "YES\n";
    }
    
    ll midsum = sum/2;
    sum = midsum;
    ll skip = 0, big = 0;
    ll num1 = 0;
    for (int i = n; i >= 1; i--){
        num1++;
        sum -= i; 
        if (sum < i - 1){
            skip = sum;
            big = i;
            if (sum != 0) num1++;
            break;
        }
    }
    
    sum = midsum;
    cout << num1 << "\n";
    for (int i = n; i >= 1; i--){
        cout << i << " ";
        sum -= i; 
        if (sum < i - 1){
            skip = sum;
            big = i;
            if (sum != 0) cout << sum;
            break;
        }
    }
    cout << "\n";
    
    cout << n - num1 << "\n";
    for (int i = 1; i < big; i++){
        if (i != skip){
            cout << i << " ";
        }
    }
}
