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
int n,h,l,r;
vector<int>nums;
int dp[2001][4002];
int rec(int i, int sleep) {
    while(sleep >= h)
        sleep -= h;
    if(dp[i][sleep] != -1)
        return dp[i][sleep];
    int count = 0;
    if (l <= sleep && sleep <= r)
        count++;
    if (i == n)
        return dp[i][sleep] = count;
    int ch1 = rec(i + 1, sleep + nums[i]);
    int ch2 = rec(i + 1, sleep + (nums[i] - 1));
    return dp[i][sleep] = count + max(ch1, ch2);
}

void sol() {
    cin >> n >> h >> l >> r;
    nums.resize(n);
    loop(n)
        cin >> nums[i];
    memset(dp , -1 , sizeof(dp));
    cout << max(rec(1,nums[0]) , rec(1 , nums[0] - 1));
}

signed main() {
    fast;
    int t = 1;
    // cin >> t;
    while(t--)
        sol();
    return 0;
}

