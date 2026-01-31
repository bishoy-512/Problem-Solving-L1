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

bool can(int mid , int t ,vector<int>nums){
    int total = 0;
    loop(nums.size()){
        total += mid / nums[i];
        if(total >= t)
            return true;
    }
    return false;
}
void sol(){
    int n,t;cin>>n>>t;
    vector<int>nums(n);
    loop(n)
        cin >> nums[i];
    int l = 1,r = 1e18,ans,mid;
    while(l <= r){
        mid = l + (r-l)/2;
        if(can(mid , t , nums)){
            r = mid - 1;
            ans = mid;
        }else l = mid + 1;
    }
    cout << ans;
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
