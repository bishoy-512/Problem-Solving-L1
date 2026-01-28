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
#define int long long
#define fast                 \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
using namespace std;


void sol(){
    int n,m;cin >> n >> m;
    vector<int>nums(n+1);
    for(int i = 1;i <= n;i++)
        cin >> nums[i];
    sort(nums.begin()+1,nums.end());

    
    int l = 1, r = 1;
    int ans = 0;
    int temp = 0;
    
    while(r <= n){
        temp += nums[r];
        
        while(l <= r && (nums[r] - nums[l] > 1 || temp > m)){
            temp -= nums[l];
            l++;
        }
        
        ans = max(ans, temp);
        r++;
    }
    
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    fast;
    int t;cin >> t;
    while(t--)
        sol();
    return 0;
}
