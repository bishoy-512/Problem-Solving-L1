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
int n,x;
vector<vector<int>>bags;
int ans = 0;
void sol(int idx_bag = 0 , int product = 1 , int num_balls = 0){
    if(product == x && num_balls == bags.size())
        ans++;
    if(idx_bag >= bags.size() || product > x)
        return;
    loop(bags[idx_bag].size())
        sol(idx_bag + 1, product * bags[idx_bag][i] , num_balls + 1);
}
/*
3 200
3 10 10 10
3 10 10 10
5 2 2 2 2 2
*/
signed main() {
    fast;
    int t = 1;
    // cin >> t;
    cin >> n >> x;
    bags.resize(n);
    loop(n){
        int l;cin>>l;
        for(int j = 0;j<l;j++){
            int temp;cin>>temp;
            bags[i].push_back(temp);
        }
    }
    while(t--)
        sol();
    cout << ans;
    return 0;
}

