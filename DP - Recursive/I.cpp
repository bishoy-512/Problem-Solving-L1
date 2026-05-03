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
int oxygen,nitrogen,ssize;
vector<pair<pair<int,int>,int>>cylinders;
int dp[1001][22][80];
int rec(int i , int oa , int na) {
    oa = max(0LL, oa);
    na = max(0LL, na);
    if(oa <= 0 && na <= 0)
        return 0;
    if(i == ssize)
        return 1e9;
    if(dp[i][oa][na] != -1)
        return dp[i][oa][na];
    int ch1 = rec(i + 1 , oa - cylinders[i].first.first , na - cylinders[i].first.second) + cylinders[i].second;
    int ch2 = rec(i+1 , oa , na);
    return dp[i][oa][na] = min(ch1 , ch2);
}


void sol() {
    cin >> oxygen >> nitrogen >> ssize;
    cylinders.clear();
    cylinders.resize(ssize);
    memset(dp , -1 , sizeof(dp));
    for (int i = 0; i < ssize; i++)
        cin >> cylinders[i].first.first >> cylinders[i].first.second >> cylinders[i].second;
    cout << rec(0 , oxygen , nitrogen) << "\n";
}

signed main() {
    fast;
    int t = 1;
    cin >> t;
    while(t--)
        sol();
    return 0;
}

