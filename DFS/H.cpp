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
int mini = LONG_LONG_MAX;
vector<bool>vis;
vector<vector<int>>adj;
vector<int>weight;

void dfs(int start){
    vis[start] = 1;
    mini = min(mini , weight[start]);
    for(auto i:adj[start]){
        if(!vis[i]){
            dfs(i);
        }
    }
}

void sol(){
    cin >> n >> m;
    adj.assign(n+1,vector<int>());
    vis.assign(n+1,false);
    weight.assign(n+1 , 0);
    vector<int>vec(n+1,1);
    for(int i = 1;i <= n;i++){
        cin >> weight[i];
    }
    for(int i = 0;i < m ;i++){
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int ans = 0;
    for(int i = 1 ;i <= n;i++){
        if(!vis[i]){
            mini = INT_MAX;
            dfs(i);
            ans += mini;
        }
    }
    cout << ans << "\n";
}

signed main() {
    fast;
    int t = 1;
    // cin >> t;
    while(t--)
        sol();
    return 0;
}

