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
using namespace std;

vector<int>levels;
vector<vector<int>> adj;
vector<bool>vis;
queue<int>nodes;
vector<int>parent;

void bfs(int start) {
    nodes.push(start);
    vis[start] = 1;
    levels[start] = 0;
    parent[start] = 0;
    while (!nodes.empty()) {
        int node = nodes.front();
        nodes.pop();
        for (auto ch: adj[node]) {
            if (!vis[ch]) {
                nodes.push(ch);
                vis[ch] = 1;
                parent[ch] = node;
                levels[ch] = levels[node] + 1;
            }
        }
    }
}

int n , m;
void sol(){
    cin >> n >> m;
    adj.resize(n+1 , vector<int>());
    vis.resize(n+1 , 0);
    levels.resize(n+1 , -1);
    parent.resize(n+1 , 0);
    for(int i = 1;i <= m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    bfs(1);
    if(vis[n]){
        stack<int>ans;
        int k = n;
        while(k != 0){
            ans.push(k);
            k = parent[k];
        }
        cout << ans.size() << endl;
        while(!ans.empty()){
            cout << ans.top() << " ";
            ans.pop();
        }
    }else cout << "IMPOSSIBLE";
}

signed main() {
    fast;
    int t = 1;
    // cin >> t
    while(t--)
        sol();
    return 0;
}