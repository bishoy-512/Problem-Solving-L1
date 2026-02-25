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
#define int long long
#define fast                 \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
#define loop(x) for(int i = 0;i<x;i++)
using namespace std;

vector<bool>vis;
vector<vector<int>>adj;
int ans = LONG_LONG_MIN;
int temp = 0;
void dfs(int start){
    vis[start] = 1;
    temp++;
    if(adj[start].size() == 1){
        ans = max(ans , temp);
        temp = 0;
    }
    for(auto i:adj[start]){
        if(!vis[i]){
            dfs(i);
        }
    }
}

void sol() {
    // Get Nodes , Edges
    int n , m;cin>>n;
    // Initialize All Needed Vectors using 1 indexed
    adj.resize(n+1,vector<int>());
    vis.resize(n+1,0);
    // Get Edges (m)
    unordered_set<int>city;
    for(int i = 1;i <= n-1;i++){
        int u , v;cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i = 1; i <= n;i++){
        if(!vis[i]){
            dfs(i);
            ans = max(ans , temp);
            temp = 0;
        }
    }
    cout << ans;
}

signed main() {
    fast;
    int t = 1;
    // cin >> t;
    while(t--){
        sol();
    }
    return 0;
}

