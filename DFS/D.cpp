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
    for(int i = 1;i <= m;i++){
        int u , v;cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    bool bus = 1 , ring = 1 , start = 1;
    int twos = 0;
    int ones = 0;
    int maxi = 0;
    // for(int i = 1;i<=n;i++){
    //     cout << "\n**************\n"<< adj[i].size() <<  "\n**************" << endl;
    // }
    for(int i = 1;i<=n;i++){
        maxi = max(maxi , (int)adj[i].size());
        if(adj[i].size() == 2)
            twos++;
        else if(adj[i].size() == 1)
            ones++;
    }
    if(twos == n - 2 && adj[1].size() == 1 && adj[n].size() == 1)
        cout << "bus topology";
    else if (twos == n)
        cout << "ring topology";
    else if(ones == maxi)
        cout << "star topology";
    else 
        cout << "unknown topology";
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

