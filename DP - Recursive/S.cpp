/*
////////////////////   ///     ///   /////////   /////////   /////////
      ///             ///     ///          ///      ///      ///
      ///             ///////////     ////////       ///      ///////
      ///             ///     ///          ///       ///      ///
      ///             ///     ///   /////////    /////////    ///
*/
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
int n,m;
vector<int>nums;
int dp[100001];

int rec(int i) {
    if(i == n)
        return 0;
    if(dp[i] != -1)
        return dp[i];
    if(nums[i] != 0)
        return dp[i] = rec(i+1);
    int ch = 0;
    int count = 0;
    if(i - 1 >= 0 && i + 1 <= n-1){
        for(int k = 1;k<=m;k++){
            if(abs(k - nums[i-1]) <= 1 && abs(k - nums[i + 1] ) <= 1)
                count++;
        }
        ch = count + rec(i+1);
    }
    else if(i - 1 >= 0 && nums[i-1]!=0) {
        int temp = nums[i-1];
        if(temp == 1 || temp == m)
            ch = 2 + rec(i+1);
        else
            ch = 3 + rec(i+1);
    }
    else if(i + 1 <= n-1 && nums[i+1] != 0) {
        int temp = nums[i+1];
        if(temp == 1 || temp == m)
            ch = 2 + rec(i+1);
        else
            ch = 3 + rec(i+1);
    }
    else
        ch = m * rec(i + 1);
    return dp[i] = ch;
}
/*
3 5
1 0 3
*/
void sol() {
    cin >> n >> m;
    nums.resize(n);
    loop(n)
        cin >> nums[i];
    memset(dp , -1 , sizeof(dp));
    cout << rec(0);
}

signed main() {
    fast;
    int t = 1;
    // cin >> t;
    while(t--)
        sol();
    return 0;
}

