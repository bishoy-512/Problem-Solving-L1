
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

int n,l,r,x;
vector<int>nums;
set<vector<int>>ans;
void sol(int idx = 0 , int num_of_problems = 0 , int diff = 0 , int max_diff = -1 , int min_diff = INT_MAX , vector<int>temp = {}) {
    if(num_of_problems >= 2 && l <= diff && diff <= r && max_diff - min_diff >= x)
        ans.insert(temp);
    if(idx == n)
        return;
    sol(idx + 1 , num_of_problems , diff , max_diff , min_diff , temp);
    temp.push_back(idx);
    sol(idx + 1 , num_of_problems + 1 , diff + nums[idx] , max(max_diff , nums[idx]) , min(min_diff , nums[idx]) , temp);
}

signed main() {
    fast;
    int t = 1;
    // cin >> t;
    cin >> n >> l >> r >> x;
    nums.resize(n);
    loop(n)
        cin >> nums[i];
    while(t--)
        sol();
    cout << ans.size();
    return 0;
}

