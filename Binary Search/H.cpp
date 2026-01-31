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
using namespace std;

bool can(int mid , vector<int>need , vector<int>have , int k){
    int max_k = 0;
    int size = need.size();
    for(int i = 0; i < size;i++){
        if( (mid * need[i]) > have[i])
            max_k += ( mid * need[i] ) - have[i];
        if(max_k > k)
            return false;
    }
    return max_k <= k;
}

void sol(){
    int n,k;cin >> n >> k;
    vector<int>need(n);
    vector<int>have(n);
    for(int i = 0;i < n;i++)
        cin >> need[i];
    for(int i = 0;i < n;i++)
        cin >> have[i];
    int l = 0, r = 2 * 1e9 , ans = 0 , mid;
    while(l <= r){
        mid = l + (r - l) / 2;
        if(can(mid , need , have , k)){
            l = mid + 1;
            ans = mid;
        }else
            r = mid - 1;
    }
    cout << ans;
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
