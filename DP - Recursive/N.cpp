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
vector<int>nums;
int dp[200001][2];
int rec(int i , bool is_even) {
    if(i == n)
        return 0;
    if(dp[i][is_even] != -1)
        return dp[i][is_even];
    int ch1 = rec(i + 1 , is_even);
    int ch2 = rec(i + 1 , !is_even) + nums[i];
    if(is_even)
        ch2 += nums[i];
    return dp[i][is_even] = max(ch1 , ch2);
}

void sol() {
    cin >> n;
    nums.resize(n);
    loop(n)
        cin >> nums[i];
    memset(dp , -1 , sizeof(dp));
    cout << rec(0 , 0);
}

signed main() {
    fast;
    int t = 1;
    // cin >> t;
    while(t--)
        sol();
    return 0;
}

