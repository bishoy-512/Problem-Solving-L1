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

int n,w;
vector<pair<int , int>> nums;
int ans = LONG_LONG_MIN;

void sol(int weight = w , int idx = 0 , int sum = 0) {
    if(idx == nums.size()) {
        ans = max(ans , sum);
        return;
    }
    sol(weight , idx + 1 , sum);
    if(nums[idx].first <= weight)
        sol(weight - nums[idx].first , idx + 1 , sum + nums[idx].second);
}

signed main() {
    fast;
    int t = 1;
    // cin >> t;
    cin >> n >> w;
    loop(n){
        int we,v;cin>>we>>v;
        nums.push_back({we,v});
    }
    while(t--)
        sol();
    cout << ans;
    return 0;
}

