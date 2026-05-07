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
#define oo LLONG_MAX
#define fast                 \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
#define loop(x) for(int i = 0;i<x;i++)
using namespace std;
string a,b,c;
int size_a , size_b , size_c;
int dp[1001][1001];
int rec(int ia , int ib) {
    if (ia == size_a){
        int count = 0;
        for(int i = ib;i<size_b;i++)
            count += (b[i] != c[ia + i]);
        return count;
    }
    if (ib == size_b){
        int count = 0;
        for(int i = ia;i<size_a;i++)
            count += (a[i] != c[i + ib]);
        return count;
    }
    if(dp[ia][ib] != -1)
        return dp[ia][ib];
    int ch1 = rec(ia + 1 , ib) + (a[ia] != c[ia + ib]);
    int ch2 = rec(ia, ib + 1) + (b[ib] != c[ia + ib]);
    return dp[ia][ib] = min(ch1 , ch2);
}

void sol() {
    cin >> a >> b >> c;
    size_a = a.size();
    size_b = b.size();
    size_c = c.size();
    memset(dp , -1 , sizeof(dp));
    cout << rec(0,0) << endl;
}

signed main() {
    fast;
    int t = 1;
    cin >> t;
    while(t--)
        sol();
    return 0;
}

