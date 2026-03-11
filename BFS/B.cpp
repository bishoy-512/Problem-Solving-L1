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
priority_queue<int, vector<int>, greater<int>> nodes;
vector<int>in_degree;
vector<int> ans;

void bfs(int start) {
    vis[start] = 1;
    levels[start] = 0;
    while (!nodes.empty()) {
        int node = nodes.top();
        nodes.pop();
        ans.push_back(node);
        for (auto ch : adj[node]) {
            in_degree[ch]--;
            if (!vis[ch]) {
                if(in_degree[ch] == 0){
                    nodes.push(ch);
                    vis[ch] = 1;
                    levels[ch] = levels[node] + 1;
                }
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
    in_degree.resize(n+1 , 0);
    for(int i = 1;i <= m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        in_degree[v]++;
    }
    for(int i = 1;i<=n;i++){
        if(in_degree[i] == 0)
            nodes.push(i);
    }
    if (nodes.size() == 0){ 
        cout << "Sandro fails.";
        return;
    }
    bfs(nodes.top());
    if(ans.size() != n)
        cout << "Sandro fails.";
    else{
        for(auto i : ans)
            cout << i << " ";
    }
        

}

signed main() {
    fast;
    int t = 1;
    // cin >> t
    while(t--)
        sol();
    return 0;
}