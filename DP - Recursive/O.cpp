/*
////////////////////   ///     ///   /////////   /////////   /////////
      ///             ///     ///          ///      ///      ///
      ///             ///////////     ////////       ///      ///////
      ///             ///     ///          ///       ///      ///
      ///             ///     ///   /////////    /////////    ///
*/
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
#include <cstring>
#define int long long
#define oo LLONG_MAX
#define fast                 \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
#define loop(x) for(int i = 0;i<x;i++)
using namespace std;
int n;
vector<pair<pair<int,int>,int>>nums;
int dp[200001];
int rec(int i , int curr_day) {
    if(i == n)
        return 0;
    if(dp[i] != -1)
        return dp[i];
    int ch1 = rec(i+1 , curr_day);
    int ch2 = 0;
    if(curr_day < nums[i].first.first)
        ch2 = rec(i + 1, nums[i].first.second) + nums[i].second;
    return dp[i] = max(ch1 , ch2);
}

void sol() {
    cin >> n;
    nums.resize(n);
    loop(n)
        cin >> nums[i].first.first >> nums[i].first.second >> nums[i].second;
    sort(nums.begin() , nums.end());
    memset(dp , -1 , sizeof(dp));
    cout << rec(0 , 1);
}

signed main() {
    fast;
    int t = 1;
    // cin >> t;
    while(t--)
        sol();
    return 0;
}

