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
    int n;cin >> n;
    vector<int>nums(n+1);
    vector<char>ch(n+1);
    for(int i = 1;i<=n;i++){
        cin >> nums[i];
        nums[i] += nums[i-1];
    }
    for(int i = 1;i<=n;i++)
        cin >> ch[i];
    int l = 1,r = n;
    int ans = 0;
    while(l < r){
        if(ch[l] == 'L' && ch[r] == 'R'){
            ans += nums[r] - nums[l-1];
            r--;
            l++;
        }
        else if (ch[l] != 'L')
            l++;
        else
            r--;
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
