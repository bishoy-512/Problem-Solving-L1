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
#define loop(x) for(int i = 1;i<=x;i++)
using namespace std;


void sol(){
    int n,q;cin>>n>>q;
    vector<int>nums(n+1);
    loop(n)
        cin >> nums[i];
    sort(nums.begin() + 1, nums.begin() + n + 1, greater<int>());
    loop(n)
        nums[i] += nums[i-1];
    while(q--){
        int x;cin>>x;
        int l = 1,r = n,mid,ans = -1;
        while(l <= r){
            mid = l + (r-l)/2;
            if(nums[mid] >= x){
                r = mid - 1;
                ans = mid;
            }
            else
                l = mid + 1;
        }
        cout << ans << endl;
    }
}

/*
4 3 3 1 1 4 5 9
=>
9 5 4 4 3 3 1 1
=>
9 14 18 22 25 28 29 30
=>
1
10
50
14
15
22
30
=>
*/
signed main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    fast;
    int t = 1;
    cin >> t;
    while(t--)
        sol();
    return 0;
}
