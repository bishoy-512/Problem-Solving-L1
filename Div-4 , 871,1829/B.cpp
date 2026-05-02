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
    int n;cin>>n;
    int first_zero = 0 , last_zero = 0;
    vector<int>nums(n);
    loop(n)
        cin >> nums[i];
    int ans = 0;
    while(first_zero < n && last_zero < n){
        if(nums[first_zero] == 0){
            last_zero = first_zero;
            while(nums[last_zero] == 0 && last_zero < n)
                last_zero++;
            ans = max(ans , last_zero - first_zero);
            first_zero = last_zero;
        }else first_zero++;
    }
    cout << ans << endl;
}
/*
5
5
1 0 0 1 0
4
0 1 1 1
1
0
3
1 1 1
9
1 0 0 0 1 0 0 0 1
*/



signed main() {
    fast;
    int t = 1;
    cin >> t;
    while(t--)
        sol();
    return 0;
}
