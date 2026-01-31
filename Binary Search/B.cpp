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
#define loop(x) for(int i = 0;i<x;i++)
using namespace std;


void sol(){
    int n,q;cin >> n >> q;
    vector<int>nums(n);
    loop(n)
        cin >> nums[i];
    while(q--){
        int l = 0,r = n-1,ans = -1,mid;
        int x;cin >> x;
        while(l <= r){
            mid = l + (r-l)/2;
            if(nums[mid] >= x){
                r = mid - 1;
                ans = mid + 1;
            }
            else
                l = mid + 1;
        }
        cout << ans << endl;
    }
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    fast;
    int t = 1;
    // cin >> t;
    while(t--)
        sol();
    return 0;
}
