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
vector<int>weight;
int ans = 0;
int maxi = LONG_LONG_MIN;

void dfs(int start){
    vis[start] = 1;
    ans++;
    for(auto i:adj[start]){
        if(!vis[i]){
            dfs(i);
        }
    }
}

void sol() {
    // Get Nodes , Edges
    int n , m;cin>>n>>m;
    // Initialize All Needed Vectors using 1 indexed
    adj.resize(n+1,vector<int>());
    vis.resize(n+1,0);
    // Get Edges (m)
    for(int i = 1;i <= m;i++){
        int u , v;cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    // Loop on Each Unvisited Node
    for(int i = 1 ;i <= n;i++){
        if(!vis[i]){
            dfs(i);
            maxi = max(maxi , ans);
            ans = 0;
        }
    }
}

signed main() {
    fast;
    int t = 1;
    cin >> t;
    while(t--){
        ans = 0;
        maxi = LONG_LONG_MIN;
        adj.clear();
        vis.clear();
        sol();
        cout << maxi << endl;
    }
    return 0;
}

