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

int mn = LONG_LONG_MAX;
int sol(int idx , vector<int>apples , int gp1 , int gp2) {
    if(idx == apples.size())
        return min(mn , abs(gp1-gp2));
    return min (
                sol(idx + 1 , apples ,gp1 + apples[idx] , gp2), // take it in gp1
                sol(idx + 1 , apples ,gp1 , gp2 + apples[idx]) // take it in gp2
                );

}

signed main() {
    fast;
    int t = 1;
    // cin >> t;
    int x;cin >> x;
    vector<int>apples(x);
    loop(x)
        cin >> apples[i];
    while(t--)
        cout << sol(0,apples,0,0);
    return 0;
}
