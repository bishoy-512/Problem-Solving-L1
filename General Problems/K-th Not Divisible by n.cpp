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

void sol() {
    int n , k;cin >> n >> k;
    if(n > k)
        cout << k << endl;
    else if (n == k)
        cout << k + 1 << endl;
    else {
        int l = 1 , r = 2 * 1e9 , mid;
        while(l <= r){
            mid = l + (r - l)/2;
            if(mid % n != 0 && mid > k && mid <= n+k){
                cout << mid << endl;
                break;
            }
            else if (mid > k) r = mid - 1;
            else if (mid % n != 0 && k > abs(n-mid)) l = mid + 1;
        }
    }
}

/*

n = 4 , k = 12

1 2 3 4 5 6 7 8  9  10 11 12 13 14 15

1 2 3 5 6 7 9 10 11 13 14 15 17 18 19

=======================================

n = 3 , k = 7

1 2 3 4 5 6  7  8  9 10 11 12 13 14 15

1 2 4 5 7 8 10 11 13 14 16 17 18 19 20

*/


signed main() {
    fast;
    int t = 1;
    cin >> t;
    while(t--)
        sol();
    return 0;
}
