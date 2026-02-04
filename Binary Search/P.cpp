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

bool can(int mid , vector<int>nums , int k){
    int count = 0 , cur_sum = 0;
    loop(nums.size()){
        if(cur_sum + nums[i] > mid){
            count++;
            cur_sum = 0;
        }
        cur_sum += nums[i];
    }
    return count + 1 <= k;
}

void sol() {
    int n,k;cin>>n>>k;
    vector<int>nums(n);
    int max_num = LONG_LONG_MIN , sum = 0; 
    loop(n){
        cin >> nums[i];
        sum += nums[i];
        max_num = max(max_num , nums[i]);
    }
    int l = max_num , r = sum , ans = LONG_LONG_MAX , mid;
    while(l<=r){
        mid = l + (r-l)/2;
        if(can(mid , nums , k)){
            r = mid - 1;
            ans = min(ans , mid);
        }else l = mid + 1;
    }
    cout << ans;
}
/*
5 3
2 4 7 3 5
2 6 13 16 21
*/

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    fast;
    int t = 1;
    // cin >> t;
    while(t--)
        sol();
    return 0;
}
