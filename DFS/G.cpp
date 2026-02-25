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

void dfs(int start){
    vis[start] = 1;
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
    unordered_set<int>city;
    for(int i = 1;i <= m;i++){
        int u , v;cin >> u >> v;
        city.insert(u);
        city.insert(v);
    }
    int x = -1;
    for(int i = 1;i<=n;i++){
        if(!city.count(i)){
            x = i;
            break;
        }
    }
    if(x == -1){
        cout << n << endl;
        for(int i = 2;i<=n;i++)
            cout << 1 << " " << i << endl;
        }
        else{
            cout << n - 1 << endl;
            for(int i = 1;i<=n;i++){
                if(x == i)
                    continue;
                cout << x << " " << i << endl;
            }
        }
    for(int i = 1; i <= n;i++){
        if(!vis[i]){
            dfs(i);
        }
    }
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

