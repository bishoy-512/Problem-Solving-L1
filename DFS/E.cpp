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
    int n , m;cin>>n>>m;

    adj.resize(n*m + 1,vector<int>());
    vis.resize(n*m + 1,0);

    vector<vector<char>>rooms(n+1 , vector<char>(m+1));

    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= m;j++)
            cin >> rooms[i][j];
    }
    unordered_set<int>uni;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (rooms[i][j] == '.') {
                if (j + 1 <= m && rooms[i][j+1] == '.') adj[(i-1)*m+j].push_back((i-1)*m+(j+1));
                if (j - 1 >= 1 && rooms[i][j-1] == '.') adj[(i-1)*m+j].push_back((i-1)*m+(j-1));
                if (i + 1 <= n && rooms[i+1][j] == '.') adj[(i-1)*m+j].push_back(i*m+j);
                if (i - 1 >= 1 && rooms[i-1][j] == '.') adj[(i-1)*m+j].push_back((i-2)*m+j);
                uni.insert((i-1)*m + j);
            }
        }
    }
    int ans = 0;
    for(auto i : uni){
        if(!vis[i]){
            ans++;
            dfs(i);
        }
    }
    cout << ans;
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

