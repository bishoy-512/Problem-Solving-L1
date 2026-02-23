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
int is_tree = 0;
int m = 0;

void dfs(int start){
    vis[start] = 1;
    for(auto i:adj[start]){
        if(!vis[i]){
            dfs(i);
        }
    }
}

unordered_set<int> uni;
unordered_map<int,int> in;
void sol() {
    // Get Nodes , Edges
    int counter = 0;
    while(true){
        int u,v;cin>>u>>v;
        if(u == 0 && v == 0){
            counter++;
            if(uni.empty())
                cout << "Case " << counter << " is a tree.\n";
            else {
                int roots = 0;
                int root;
                for(auto i : uni){
                    if(in[i] == 0){
                        roots++;
                        root = i;
                    }
                }
                if(roots == 1){
                    is_tree++;
                    dfs(root);
                    for(auto i : uni){
                        if(!vis[i]){
                            is_tree++;
                        }
                    }
                    if(is_tree == 1 && m == (int)uni.size() - 1)
                        cout << "Case " << counter << " is a tree.\n";
                    else
                        cout << "Case " << counter << " is not a tree.\n";
                }
                else
                    cout << "Case " << counter << " is not a tree.\n";
            }
            is_tree = 0;
            uni.clear();
            in.clear();
            adj.assign(200000 , vector<int>());
            vis.assign(200000 , 0);
            m = 0;
        }
        else if(u == -1 && v == -1)
            break;
        else{
            m++;
            uni.insert(u);
            uni.insert(v);
            adj[u].push_back(v);
            in[v]++;
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