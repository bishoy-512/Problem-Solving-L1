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
int n,m,mx=LONG_LONG_MIN;
vector<vector<int>> nums;
void sol(int x , int y , int sum) {
    if(x == n - 1 && y == m - 1){
        mx = max(mx , sum);
        return;
    }
    if (x + 1 < n)
        sol(x + 1, y, sum + nums[x + 1][y]);
    if (y + 1 < m)
        sol(x, y + 1, sum + nums[x][y + 1]);
}

signed main() {
    fast;
    int t = 1;
    // cin >> t;
    cin >> n >> m;
    nums.resize(n , vector<int>(m));
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++)
            cin >> nums[i][j];
    }
    while(t--)
        sol(0,0,nums[0][0]);
    cout << mx;
    return 0;
}
