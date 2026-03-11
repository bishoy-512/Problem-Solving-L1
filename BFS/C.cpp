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
queue<int>nodes;
vector<bool>vis;
int n , m;
int s , e;
int counter = 0;
int ans = LONG_LONG_MAX;
void bfs(int start) {
    vis[start] = 1;
    levels[start] = 0;
    while (!nodes.empty()) {
        int node = nodes.front();
        nodes.pop();
        if(node * 2 <= 2e4 && !vis[node*2]){
            nodes.push(node*2);
            vis[node*2] = 1;
            levels[node * 2] = levels[node] + 1;
        }
        if(node - 1 > 0 && !vis[node - 1]){
            nodes.push(node - 1);
            vis[node - 1] = 1;
            levels[node - 1] = levels[node] + 1;
        }
        if(levels[e] != -1){
            cout << levels[e];
            return;
        }
    }
}

void sol(){
    // cin >> n >> m;
    adj.resize(2e4 , vector<int>());
    vis.resize(2e4 , 0);
    levels.resize(2e4 , -1);
    cin >> s >> e;
    if(s >= e){
        cout << s - e;
        return;
    }
    nodes.push(s);
    bfs(s);
}

signed main() {
    fast;
    int t = 1;
    // cin >> t
    while(t--)
        sol();
    return 0;
}