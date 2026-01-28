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
    int w,h,n;cin >> w >> h >> n;
    vector<vector<int>> nums (h+1 , vector<int>(w+1 , 0));

    // prefix sum for each row =>
    for (int i = 1;i<=h;i++){
        for (int j = 1;j<=w;j++)
            nums[i][j] += nums[i][j-1];
    }
    // prefix sum for each column =>
    for (int i = 1;i<=h;i++){
        for (int j = 1;j<=w;j++)
            nums[i][j] += nums[i-1][j];
    }
    
    int ans = 0;
    while(n--){
        int x1,y1,x2,y2;cin >> x1 >> y1 >> x2 >> y2;
        ans += nums[x2][y2] - nums[x1-1][y2] - nums[x2][y1-1] + nums[x1-1][y1-1];
    }
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    fast;
    int t;cin>>t;
    while(t--)
        sol();
    return 0;
}
/*
1 1
1 1


1 2
2 4

*/