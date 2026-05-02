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
vector<vector<int>>lake;
int n,m;
int ans = 0;
vector<vector<bool>>vis;
void sol(int sum , int x , int y) {
    if(x < 0 || x >= n || y < 0 || y >= m || lake[x][y] == 0 || vis[x][y]){
        ans = max(ans , sum);
        return;
    }
    vis[x][y] = 1;
    sol(sum + lake[x][y] , x + 1 , y);
    sol(sum + lake[x][y] , x , y + 1);
    sol(sum + lake[x][y] , x - 1 , y);
    sol(sum + lake[x][y] , x , y - 1);
}




signed main() {
    fast;
    int t = 1;
    cin >> t;
    while(t--){
        cin >> n >> m;
        ans = 0;
        vis.assign(n, vector<bool>(m , 0));
        lake.assign(n, vector<int>(m));
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++)
                cin >> lake[i][j];
        }

        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++)
                if(lake[i][j] != 0 && !vis[i][j])
                    sol(0 , i , j);
        }
        cout << ans << endl;
    }
    return 0;
}
