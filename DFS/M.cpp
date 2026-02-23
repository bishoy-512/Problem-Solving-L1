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

vector<bool>vis(200000);
vector<vector<int>>adj(200000);
bool reached = false;
int n,t;
void dfs(int start){
    vis[start] = 1;
    if(start == t)
        reached = true;
    for(auto i:adj[start]){
        if(!vis[i]){
            dfs(i);
        }
    }
}

void sol() {
    cin >> n >> t;
    for(int i = 1;i < n;i++){
        int temp;cin>>temp;
        adj[i].push_back(i + temp);
    }
    dfs(1);
    if(reached)
        cout << "YES";
    else
        cout << "NO";
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