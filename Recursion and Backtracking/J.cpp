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

int n, k;
vector<int> nums;

void sol(int idx = 0, int sum = 0, vector<int> s = {}) {
    if (idx == n) {
        if (sum % k == 0) {
            loop(n) cout << s[i] << " ";
            cout << "\n";
        }
        return;
    }
    for (int val = 1; val <= nums[idx]; val++) {
        s.push_back(val);
        sol(idx + 1, sum + val, s);
        s.pop_back();
    }
}

signed main() {
    fast;
    int t = 1;
    // cin >> t;
    cin >> n >> k;
    nums.resize(n);
    loop(n)
        cin >> nums[i];
    while(t--)
        sol();
    return 0;
}
