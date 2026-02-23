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
set<vector<int>>teams_of_three;
set<vector<int>>teams_of_two;
set<int>teams_of_one;
vector<int>teams;

void dfs(int start){
    vis[start] = 1;
    teams.push_back(start);
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
    for(int i = 1;i <= n;i++){
        if(!vis[i]){
            dfs(i);
            if(teams.size() == 3)
                teams_of_three.insert({teams[0] , teams[1] , teams[2]});
            else if (teams.size() == 2)
                teams_of_two.insert({teams[0] , teams[1]});
            else if (teams.size() == 1)
                teams_of_one.insert(teams[0]);
            else{
                cout << -1;
                return;
            }
            teams.clear();
        }
    }
    int ones = teams_of_one.size();
    int twos = teams_of_two.size();
    bool flag = (ones >= twos) && ((ones - twos) % 3 == 0);
    if(flag){
        set<vector<int>> new_teams_of_two;
        for(auto i : teams_of_two){
            i.push_back(*teams_of_one.begin());
            new_teams_of_two.insert(i);
            teams_of_one.erase(*(teams_of_one.begin()));
        }
        teams_of_two = new_teams_of_two;
        for(auto i : teams_of_three){
            for(auto j : i)
                cout << j << " ";
            cout << endl;
        }
        for(auto i : teams_of_two){
            for(auto j : i)
                cout << j << " ";
            cout << endl;
        }
        int c = 0;
        for(auto i : teams_of_one){
            cout << i << " ";
            c++;
            if(c == 3){
                cout << endl;
                c = 0;
            }
        }
    }else cout << -1;
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

