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
int n,m;
vector<vector<char>> grid;
int dp[1001][1001];
int rec(int i = 0 , int j = 0) {
    if(i == n || j == m || grid[i][j] == '#')
        return 0;
    if(dp[i][j] != -1)
        return dp[i][j];
    if(i == n - 1 && j == m - 1)
        return 1;
    int ch1 = rec(i+1 , j);
    int ch2 = rec(i , j + 1);
    return dp[i][j] = ((ch1 + ch2) % (int)(1e9 + 7));
}


void sol() {
    cin >> n >> m;
    grid.assign(n, vector<char>(m));
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> grid[i][j];
    memset(dp , -1 , sizeof(dp));
    cout << rec();
}

signed main() {
    fast;
    int t = 1;
    // cin >> t;
    while(t--)
        sol();
    return 0;
}

