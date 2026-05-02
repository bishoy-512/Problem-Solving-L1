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
vector<int>weights;
vector<int>values;
int n,w;
int dp[100][100000];

int rec(int load , int i){
    if(load <= 0 || i == n)
        return 0;
    if(dp[i][load] != -1)
        return dp[i][load];
    int ch1 = 0;
    if(weights[i] <= load)
        ch1 = rec(load - weights[i] , i + 1) + values[i];
    int ch2 = rec(load , i + 1);
    return dp[i][load] = max(ch1 , ch2);
}

void sol() {
    cin >> n >> w;
    weights.resize(n);
    values.resize(n);
    memset(dp, -1, sizeof(dp));
    loop(n)
        cin >> weights[i] >> values[i];
    int ans = rec(w,0);
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