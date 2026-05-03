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
int n;
vector<int>days;
int dp[101][2][2];
int rec(int i , bool do_contest , bool do_sport) {
    if(i == n)
        return 0;
    if(dp[i][do_contest][do_sport] != -1)
        return dp[i][do_contest][do_sport];
    int ch1,ch2,ch3,ch4,ch5;
    ch2 = ch3 = ch4 = ch5 = LONG_MAX;
    ch1 = rec(i + 1 , 0 , 0) + 1;
    if (days[i] == 1 && !do_contest)
        ch2 = rec(i + 1 , 1 , 0);
    if (days[i] == 2 && !do_sport)
        ch3 = rec(i + 1 , 0 , 1);
    if(days[i] == 3 && !do_sport)
        ch4 = rec(i + 1 , 0 , 1);
    if (days[i] == 3 && !do_contest)
        ch5 = rec(i + 1 , 1 , 0);
    return dp[i][do_contest][do_sport] = min({ch1,ch2,ch3,ch4,ch5});
}


void sol() {
    cin >> n;
    days.resize(n);
    memset(dp , -1 , sizeof(dp));
    loop(n)
        cin >> days[i];
    cout << rec(0,0,0);
}

signed main() {
    fast;
    int t = 1;
    // cin >> t;
    while(t--)
        sol();
    return 0;
}

