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
vector<int>nums;
int dp[101][2][2];
int rec(int i) {
    if(i >= n)
        return 0;
    int ch1 = rec(i + 1);
    int ch2 = 0;
    if(i + nums[i] + 1 <= n)
        ch2 = 1 + nums[i] + rec(i + nums[i] + 1);
    return max(ch1,ch2);
}


void sol() {
    cin >> n;
    nums.assign(n,-1);
    loop(n)
        cin >> nums[i];
    memset(dp , -1 , sizeof(dp));
    cout << n - rec(0) << endl;
}

signed main() {
    fast;
    int t = 1;
    cin >> t;
    while(t--)
        sol();
    return 0;
}

