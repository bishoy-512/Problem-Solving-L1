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
string s,t;
int max_len;
int dp[3005][3005];

int rec(int i, int j) {
    if (i == s.size() || j == t.size())
        return 0;
    if(dp[i][j] != -1)
        return dp[i][j];
    int ch1,ch2,ch3;
    ch1 = ch2 = ch3 = 0;
    if (s[i] == t[j])
        ch1 = rec(i+1, j+1) + 1;
    else {
        ch2 = rec(i+1, j);
        ch3 = rec(i, j+1);
    }
    return dp[i][j] = max({ch1,ch2,ch3});
}

void build() {
    string ans = "";
    int i = 0, j = 0;
    while (i < s.size() && j < t.size()) {
        if (s[i] == t[j]) {
            ans += s[i];
            i++; j++;
        }
        else if (rec(i+1, j) >= rec(i, j+1))
            i++;
        else
            j++;
    }
    cout << ans;
}

void sol() {
    cin >> s >> t;
    memset(dp, -1, sizeof(dp));
    max_len = rec(0,0);
    build();
}

signed main() {
    fast;
    int t = 1;
    // cin >> t;
    while(t--)
        sol();
    return 0;
}

