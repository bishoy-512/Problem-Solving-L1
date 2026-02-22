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
int n , m;

void dfs(int start){
    vis[start] = 1;
    for(auto i:adj[start]){
        if(!vis[i]){
            dfs(i);
        }
    }
}

void sol() {
    cin >> n >> m;
    adj.assign(n+1,vector<int>());
    for(int i = 1;i <= m;i++){
        int u , v;cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i = 1; i <= n; i++)
        cout << adj[i].size() << endl;
}

signed main() {
    fast;
    int t = 1;
    // cin >> t;
    while(t--)
        sol();
    return 0;
}

