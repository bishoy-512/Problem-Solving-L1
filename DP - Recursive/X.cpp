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
#define fast                 \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
#define loop(x) for(int i = 0;i<x;i++)
using namespace std;
int n,w;
vector<pair<int,int>>nums;
unordered_map<int,int> dp[101];
int rec(int i , int sum) {
    if(i == n)
        return 0;
    if(dp[i].count(sum))
        return dp[i][sum];
    int ch1 = rec(i + 1 , sum);
    int ch2 = 0;
    if(sum + nums[i].first <= w)
        ch2 = rec(i + 1 , sum + nums[i].first) + nums[i].second;
    return dp[i][sum] = max(ch1 , ch2);
}

void sol() {
    cin >> n >> w;
    nums.resize(n);
    loop(n)
        cin >> nums[i].first >> nums[i].second;
    cout << rec(0,0);
}

signed main() {
    fast;
    int t = 1;
    // cin >> t;
    while(t--)
        sol();
    return 0;
}

