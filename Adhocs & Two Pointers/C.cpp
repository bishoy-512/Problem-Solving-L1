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
    int n,q;cin >> n >> q;
    vector<vector<int>> nums (n+1 , vector<int>(n+1));

    for (int i = 1;i<=n;i++){
        for (int j = 1;j<=n;j++){
            char c;cin>>c;
            if(c == '*')
                nums[i][j] = 1;
            else
                nums[i][j] = 0;
        }
    }
    // prefix sum for each row =>
    for (int i = 1;i<=n;i++){
        for (int j = 1;j<=n;j++)
            nums[i][j] += nums[i][j-1];
    }
    // prefix sum for each column =>
    for (int i = 1;i<=n;i++){
        for (int j = 1;j<=n;j++)
            nums[i][j] += nums[i-1][j];
    }

    while(q--) {
        int y1,x1,y2,x2;cin >> x1 >> y1 >> x2 >> y2;
        cout << nums[x2][y2] - nums[x1-1][y2] - nums[x2][y1 - 1] + nums[x1 - 1][y1 - 1] << endl;
    }

}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    fast;
    
    //while()
        sol();
    return 0;
}
