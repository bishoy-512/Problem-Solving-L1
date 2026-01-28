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
    int n;cin >> n;
    vector<int>nums(n);
    for(int i = 0;i < n;i++)
        cin >> nums[i];
    
    int l = 0, r = n-1;
    int alice = 0 , bob = 0;
    int count = 0;
    int ans = 0;
    bool f = true;
    while (l <= r) {
        if (alice < bob) {
            alice += nums[l];
            l++;
        } 
        else if (alice > bob) {
            bob += nums[r];
            r--;
        } 
        else {
            ans = l + (n - 1 - r);
            alice += nums[l];
            l++;
        }
    }
    if (alice == bob)
        ans = l + (n - 1 - r);
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    fast;
    int t;cin >> t;
    while(t--)
        sol();
    return 0;
}
