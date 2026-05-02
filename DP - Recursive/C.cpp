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
vector<int>heights;
int n,k;
int dp[100005];

int rec(int i){
    if(i == n - 1)
        return 0;
    if(dp[i] != -1)
        return dp[i];
    int ans = LLONG_MAX;
    for(int j = 1; j <= k; j++){
        if(i + j < n){
            int cost = rec(i + j) + abs(heights[i] - heights[i + j]);
            ans = min(ans, cost);
        }
    }
    return dp[i] = ans;
}

void sol() {
    cin >> n >> k;
    heights.resize(n);
    memset(dp, -1, sizeof(dp));
    loop(n)
        cin >> heights[i];
    int ans = rec(0);
    cout << ans;
}

signed main() {
    fast;
    int t = 1;
    // cin >> t;
    while(t--)
        sol();
    return 0;
}

