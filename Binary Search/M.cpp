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
#define loop(x) for(int i = 1;i<=x;i++)
using namespace std;

int total_s = 0;
bool can(int k , vector<int>nums , int s , int n){
    int sum = 0;
    vector<int>temp(n+1);
    loop(n)
        temp[i] = nums[i] + i*k;
    sort(temp.begin(),temp.end());
    for(int i = 1;i <= k;i++){
        sum += temp[i];
        if(sum > s)
            return false;
    }
    total_s = sum;
    return true;
}

void sol() {
    int n,s;cin>>n>>s;
    vector<int>nums(n+1);
    loop(n)
        cin >> nums[i];
    int l = 0,r = n, mid,ans = 0,total = 0;
    while(l<=r){
        mid = l + (r-l)/2;
        if(can(mid , nums , s , n)){
            l = mid + 1;
            ans = mid;
            total = total_s;
        }else r = mid - 1;
    }
    cout << ans << " " << total;
}
/*
3 11
2 3 5
===== 
2 5 8
=====
k = 2 =>
3 + 2 * 2 = 7
2 + 1 * 2 = 4

5 + 2 * 2 = 9

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
