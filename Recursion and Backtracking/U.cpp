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
#define loop(x) for(int i = 0;i<x;i++)
using namespace std;
int n , m;
vector<vector<int>>grid;
int vis[6][6];
int ans = 0;
void sol(int x = 0 , int y = 0){
    if(x == n - 1 && y == m - 1){
        ans++;
        return;
    }
    else if(vis[x][y] || grid[x][y] == 0)
        return;
    if(x + 1 < n){
        vis[x][y] = 1;
        sol(x + 1 , y);
        vis[x][y] = 0;
    }
    if(x - 1 >= 0){
        vis[x][y] = 1;
        sol(x - 1 , y);
        vis[x][y] = 0;
    }
    if(y + 1 < m){
        vis[x][y] = 1;
        sol(x , y + 1);
        vis[x][y] = 0;
    }
    if(y - 1 >= 0){
        vis[x][y] = 1;
        sol(x , y - 1);
        vis[x][y] = 0;
    }
}

signed main() {
    fast;
    int t = 1;
    // cin >> t;
    cin >> n >> m;
    grid.resize(n , vector<int>(m));
    loop(n){
        for(int j = 0;j<m;j++)
            cin >> grid[i][j];
    }
    while(t--)
        sol();
    cout << ans;
    return 0;
}

