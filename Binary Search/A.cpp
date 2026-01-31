#include <iostream>
#include <cmath>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
#include <iomanip>
#include <set>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <climits>
#define int long long
#define fast                 \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
using namespace std;



void sol(){
    int n,q;cin >> n >> q;
    vector<int>nums(n);
    for(int i = 0; i < n;i++)
        cin >> nums[i];
    while(q--){
        int x;cin >> x;
        int l = 0,r = n-1 , ans = -1 , mid;
        while(l <= r){
            mid = l + (r - l)/2;
            if(nums[mid] == x){
                ans = mid + 1;
                break;
            }
            else if(nums[mid] > x)
                r = mid - 1;
            else
                l = mid + 1;
        }
        cout << ans << endl;
    }
}

signed main() {
    fast;
    int t = 1;
    // cin >> t;
    while(t--)
        sol();
    return 0;
}
