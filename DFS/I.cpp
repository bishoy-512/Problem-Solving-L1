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

using namespace std;

int n , m;
vector<bool> vis;
vector<vector<int>> adj;
vector<int> weight;
bool f = true;

void dfs(int start){
    for(auto i : adj[start]){
        if(weight[start] <= weight[i]){
            f = false;
            break;
        }
    }
}

void sol(){
    cin >> n >> m;

    adj.assign(n + 1 , vector<int>());
    vis.assign(n + 1 , 0);
    weight.assign(n + 1 , 0);

    for(int i = 1 ; i <= n ; i++)
        cin >> weight[i];

    for(int i = 0 ; i < m ; i++){
        int u , v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int ans = 0;

    for(int i = 1 ; i <= n ; i++){
        if(!vis[i]){
            f = true;
            dfs(i);
            if(f)
                ans++;
        }
    }

    cout << ans;
}

signed main() {
    fast;
    int t = 1;
    // cin >> t
    while(t--)
        sol();
    return 0;
}