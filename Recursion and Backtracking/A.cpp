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


int sol(int x) {
    if(x == 0)
        return 1;
    return x * sol(x-1);
}

signed main() {
    fast;
    int t = 1;
    // cin >> t;
    int x;cin>>x;
    while(t--)
        cout << sol(x);
    return 0;
}
