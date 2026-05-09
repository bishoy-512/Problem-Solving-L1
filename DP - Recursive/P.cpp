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
int n,m;
vector<vector<int>>edges;
map<int,int>in_degree;
queue<int>nums;
int dp[100001];
int rec(int i) {
    if(i > n)
        return 0;
    if(dp[i] != -1)
        return dp[i];
    int ch1 = 0;
    for(auto k : edges[i])
        ch1 = max(rec(k)+1,ch1);
    return dp[i] = ch1;
}

void sol() {
    cin >> n >> m;
    edges.resize(n+1);
    loop(m){
        int x,y;cin>>x>>y;
        edges[x].push_back(y);
        in_degree[y]++;
    }
    memset(dp , -1 , sizeof(dp));
    int ans = -oo;
    for(int i = 1;i<=n;i++)
        if(!in_degree.count(i))
            ans = max(ans ,rec(i));
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

