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
#define int long long
#define fast                 \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
using namespace std;
void sol(){
    int n,k;cin >> n >> k;
    vector<int>nums(n+1);
    vector<int>prefix(n+1);
    for(int i = 1;i <= n;i++){
        cin >> nums[i];
        nums[i] += nums[i-1];
    }
    int ans = 0;
    int l = 1, r = l;
    while (l <= n) {
        while (r <= n) {
            if (nums[r] - nums[l-1] == k)
                ans++;
            r++;
        }
        l++;
        r = l;
    }
    cout << ans;
}
/*
2 -1 3 5 -2
2 1 4 9 7
*/

signed main() {
    fast;
    int t = 1;
    // cin >> t;
    while(t--)
        sol();
    return 0;
}
