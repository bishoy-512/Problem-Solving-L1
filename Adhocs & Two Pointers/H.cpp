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
    int l = 0, r = 0;
    unordered_set<int> un;
    int ans = 0;

    while(r < n){
        if(!un.count(nums[r])){
            un.insert(nums[r]);
            ans = max(ans, (int)un.size());
            r++;
        } else {
            un.erase(nums[l]);
            l++;
        }
    }
    cout << ans;

}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    fast;
    // int t;cin >> t;
    // while(t--)
        sol();
    return 0;
}
