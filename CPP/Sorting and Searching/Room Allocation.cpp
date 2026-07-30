// cieldt - AI23@HCMUS
 
#include <iostream>
#include <algorithm> 
#include <vector>
// #include <string>
// #include <unordered_map>
#include <set>
#define F first
#define S second
typedef long long ll;
using namespace std;
 
 
 
void solve(){
    int n;
    cin >> n;
    vector<pair<pair<int,int>, int>> c(n); // ((arrival, departure), original_index)
    for (int i = 0; i < n; i++){
        cin >> c[i].F.F >> c[i].F.S; 
        c[i].S = i; // index of the customer
    }
    sort(c.begin(), c.end()); // Sort by arrival time
 
    set<pair<int, int>> rooms; // {departure time, room number}
    vector<int> room_allocation(n); // Store room assignment for each customer
    int max_rooms = 0; // Keep track of the maximum room number used
 
    for (int i = 0; i < n; i++){
        int arrival = c[i].F.F;
        int departure = c[i].F.S;
        int cid = c[i].S; 
 
        auto it = rooms.lower_bound({arrival, 0}); // Find a room with departure time >= arrival time
        if (it != rooms.begin()){
            --it; // Go to the previous room (because lower_bound might return a room with departure time > arrival)
            if (it->F < arrival) { // Check if the previous room is actually available
                room_allocation[cid] = it->S; // Assign the room
                rooms.erase(it); // Remove the room from the set
                rooms.insert({departure, room_allocation[cid]}); // Add the room back with updated departure time
            } else {
                // No available room found, create a new room
                max_rooms++;
                room_allocation[cid] = max_rooms;
                rooms.insert({departure, max_rooms});
            }
        } else {
            // No rooms in the set or all rooms have departure times > arrival time, create a new room
            max_rooms++;
            room_allocation[cid] = max_rooms;
            rooms.insert({departure, max_rooms});
        }
    }
 
    cout << max_rooms << "\n"; 
    for (int i = 0; i < n; ++i) {
        cout << room_allocation[i] << (i == n - 1 ? "" : " ");
    }
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1; 
    //cin >> t; 
    while(t--){
        solve();
    }
    return 0;
}
