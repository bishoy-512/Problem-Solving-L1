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

string s;
set<string>ans;
void sol(int idx = 0) {
    if(idx == s.size()) {
        ans.insert(s);
        return;
    }
    for(int i = idx; i < s.size(); i++) {
        swap(s[idx], s[i]);
        sol(idx + 1);
        swap(s[idx], s[i]);
    }
}

signed main() {
    fast;
    int t = 1;
    // cin >> t;
    cin >> s;
    while(t--)
        sol();
    cout << ans.size() << endl;
    for(auto t : ans)
        cout << t << endl;
    return 0;
}
