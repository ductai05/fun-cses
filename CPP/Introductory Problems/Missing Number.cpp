#include<iostream>
 
using namespace std;
 
int main(){
    long long n;
    cin >> n;
    long long s = 0, t = 0;
    for (int i = 0; i < n - 1; i++){
        cin >> t;
        s += t;
    }
    cout << n * (n + 1) / 2 - s;
}