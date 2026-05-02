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

vector<int> levels;
vector<vector<int>> adj;
vector<bool> vis;
int n , m , k , s;
vector<int>goods;
vector<unordered_set<int>>items;
queue<int>temp;

int get_cost(int i){
    int count = 1;
    int cos = 0;
    while(!temp.empty()){
        int t = temp.front();
        temp.pop();
        if(items[i].size() == s)
            return cos;
        if(!items[i].count(goods[t])){
            items[i].insert(goods[t]);
            cos += levels[t];
        }
    }
    return cos;
}

void bfs(int start) {
    queue<int> nodes;
    nodes.push(start);
    vis[start] = 1;
    levels[start] = 0;
    while (!nodes.empty()) {
        int node = nodes.front();
        nodes.pop();
        for (auto ch: adj[node]) {
            if (!vis[ch]) {
                    nodes.push(ch);
                    vis[ch] = 1;
                    levels[ch] = levels[node] + 1;
                    temp.push(ch);
                    if(temp.size() == s - 1)
                        break;
                }
            }
            if(temp.size() == s - 1)
                break;
        }
}

void sol(){
    cin >> n >> m >> k >> s;
    adj.assign(n+1 , vector<int>());
    vis.assign(n+1 , 0);
    levels.assign(n+1 , -1);
    goods.resize(n+1);
    items.assign(n+1 , unordered_set<int>());
    for(int i = 1; i <= n;i++){
        cin >> goods[i];
        items[i].insert(goods[i]);
    }
    for(int i = 1;i <= m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i = 1;i<=n;i++){
        bfs(i);
        cout << get_cost(i) << " ";
        vis.assign(n+1 , 0);
        levels.assign(n+1 , -1);
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