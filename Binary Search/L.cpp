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

void sol()
{
    int n,a,b;cin>>n>>a>>b;
    vector<int>nums(n);
    loop(n)
        cin >> nums[i];
    vector<int>sorted = nums;
    sort(sorted.begin(),sorted.end());
    loop(n)
    {
        int l = lower_bound(sorted.begin(),sorted.end(),nums[i] + a)-sorted.begin();
        int r = lower_bound(sorted.begin(),sorted.end(),nums[i] + b)-sorted.begin() - 1;
        cout<< r - l + 1 << " ";
        l = upper_bound(sorted.begin(),sorted.end(),nums[i] - b)-sorted.begin();
        r = upper_bound(sorted.begin(),sorted.end(),nums[i] - a)-sorted.begin() - 1;
        cout<< r - l + 1 << '\n';
    }
}
/*
5 3 7
8 6 5 14 12
5 6 8 12 14

5 =>
0 -1 -3 -7 -9
pred: if X - x in range [a <= x && x < b]
f f t f f
prey:
6 =>
1 0 -2 -6 -8
pred: if X - x in range [a <= x && x < b]
f f f t f

8 =>
3 2 0 -4 -6

12 =>
7 6 4 0 -2

14 =>
9 8 6 2 0

*/

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    fast;
    int t = 1;
    // cin >> t;
    while(t--)
        sol();
    return 0;
}
