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
int k , m;
vector<pair<int,int>>items;
int dp [51][1001];
int rec(int i , int load) {
    if(i == m)
        return 0;
    if(dp[i][load] != -1)
        return dp[i][load];
    int ch1 = 0;
    if(load - items[i].first >= 0)
        ch1 = rec(i+1 , load - items[i].first) + items[i].second;
    int ch2 = rec(i + 1 , load);
    return dp[i][load] = max(ch1 , ch2);
}


void sol() {
    cin >> k >> m;
    items.clear();
    items.assign(m, {0,0});
    memset(dp , -1 , sizeof(dp));
    for(int i = 0; i < m; i++)
        cin >> items[i].first >> items[i].second;
    cout << "Hey stupid robber, you can get " << rec(0 , k) << ".\n";
}

signed main() {
    fast;
    int t = 1;
    cin >> t;
    while(t--)
        sol();
    return 0;
}

