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
    int n,t;cin>>n>>t;
    int temp = t;
    vector<int>nums(n);
    for(int i = 0;i < n;i++)
        cin >> nums[i];
    int l = 0,r = 0;
    int ans = 0;
    while(r < n){
        if(t - nums[r] >= 0){
            t -= nums[r];
            ans = max(ans , r-l+1);
            r++;
            if(t == 0){
                t += nums[l];
                l++;
            }
        }
        else{
            t += nums[l];
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
