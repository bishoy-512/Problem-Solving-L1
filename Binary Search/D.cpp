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


void sol(){
    int n,m;cin >> n >> m;
    vector<int>nums1(n);
    vector<int>nums2(m);
    loop(n)
        cin >> nums1[i];
    loop(m)
        cin >> nums2[i];
    sort(nums1.begin() , nums1.end());
    loop(m){
        int x = nums2[i];
        int l = 0,r = n - 1,ans = -1,mid;
        while(l <= r){
            mid = l + (r-l)/2;
            if(x >= nums1[mid]){
                l = mid + 1;
                ans = mid;
            }else r = mid - 1;
        }
        cout << ans + 1 << " ";
    }
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    fast;
    int t = 1;
    // cin >> t;
    while(t--)
        sol();
    return 0;
}
