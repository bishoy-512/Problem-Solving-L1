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
#include <cstring>
#define int long long
#define fast                 \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
#define loop(x) for(int i = 0;i<x;i++)
using namespace std;
unordered_map<int, int> dp;
int n;
int rec(int n) {
    if(n == 0)
        return n;
    auto it = dp.find(n);
    if (it != dp.end()) return it->second;
    int ch1 = rec(n/2);
    int ch2 = rec(n/3);
    int ch3 = rec(n/4);
    return dp[n] = max({ch1 + ch2 + ch3, n});
}


void sol() {
    while(cin >> n)
        cout << rec(n) << endl;
}

signed main() {
    fast;
    int t = 1;
    // cin >> t;
    while(t--)
        sol();
    return 0;
}

