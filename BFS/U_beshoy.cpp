#include<iostream>
#include<vector>
#include<string>
#include <algorithm>
#include <numeric> 
#include<cmath>
#include<array>
#include<iomanip>
#include<queue>
#include<set>
#include<bitset>
#include<stack>
#include<map>
#include<unordered_set>
#include <climits>
#include <cstring>
#include <bitset>
using namespace std;
#define ll long long
const int MOD = 1000000007, MAXN = 200000;

ll n , m , k ,s;
vector<bool>vis,vi;
vector<vector<ll>>adj;
vector<pair<ll,ll>>level;
vector<int> weig;
vector<vector<ll>>costs;
bool flag = false;
void bfs(int item){
    queue<ll>q;
    for(int i = 1 ; i <= n;i++){
        if(weig[i] == item){
            q.push(i);
            costs[item][i] = 0;
        }
    }
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        for(auto ch : adj[cur]){
            if(costs[item][cur] + 1 < costs[item][ch]) {
                costs[item][ch] = costs[item][cur] + 1;
                q.push(ch);
            }
        }
    }
}
int main (){
    cin >> n >> m >> k >> s;
    adj.assign(n + 1 , vector<ll>());
    vis.assign(n + 1 , false);
    vi.assign(n + 1 , false);
    costs.assign(k+1, vector<ll>(n+1, LONG_LONG_MAX));
    weig.assign(n+1 , 0);
    for(int i = 1 ; i <= n ; i++){
        cin >> weig[i];
    }
    for(int i = 0; i < m ; i++){
        int u , v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i = 1 ; i <= k ; i++){
        bfs(i);
    }
    for(int i = 1; i <= n;i++){
        vector<int>ans;
        for(int j = 1;j <= k;j++)
            ans.push_back(costs[j][i]);
        sort(ans.begin() , ans.end());
        int sum = 0;
        for(int j = 0;j < s;j++)
            sum += ans[j];
        cout << sum << " ";
    }
    return 0;
} 
/*
5 5 4 3
1 2 4 3 2
1 2
2 3
3 4
4 1
4 5
OutputCopy
2 2 2 2 3 
InputCopy
7 6 3 2
1 2 3 3 2 2 1
1 2
2 3
3 4
2 5
5 6
6 7
OutputCopy
1 1 1 2 2 1 1
*/