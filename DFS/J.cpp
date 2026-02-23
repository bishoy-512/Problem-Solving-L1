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
vector<pair<int,vector<int>>>ans;
vector<int>s;
int parent;

void dfs(int start){
    vis[start] = 1;
    s.push_back(start);
    if(adj[start].size() == 0){
        ans.push_back({s.size() , s});
        s.clear();
        return;
    }
    for(auto i:adj[start]){
        if(!vis[i]){
            dfs(i);
        }
    }
}

void sol() {
    // Get Nodes , Edges
    int n;cin>>n;
    // Initialize All Needed Vectors using 1 indexed
    adj.resize(n+1,vector<int>());
    vis.resize(n+1,0);
    // Get Edges (m)
    for(int i = 1;i <= n;i++){
        int temp;cin>>temp;
        if(i == temp){
            parent = temp;
            continue;
        }
        adj[temp].push_back(i);
    }
    dfs(parent);
}

signed main() {
    fast;
    int t = 1;
    cin >> t;
    while(t--){
        adj.clear();
        vis.clear();
        s.clear();
        ans.clear();
        sol();
        sort(ans.rbegin() , ans.rend());
        cout << ans.size() << endl;
        for(auto i : ans){
            cout << i.first << endl;
            for(auto j : i.second)
                cout << j << " ";
            cout << endl;
        }
    }
    return 0;
}
/*
1
5
3 1 3 3 1
*/

