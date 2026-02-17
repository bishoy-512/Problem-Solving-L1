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

void sol(int x) {
    if(x == 1)
        return;
    if(x % 2 == 0){
        cout << x / 2 << " ";
        sol(x / 2);
    }
    else{
        cout << 3 * x + 1  << " ";
        sol(3 * x + 1);
    }
}

signed main() {
    fast;
    int t = 1;
    // cin >> t;
    int x;cin >> x;
    cout << x << " ";
    while(t--)
        sol(x);
    return 0;
}
